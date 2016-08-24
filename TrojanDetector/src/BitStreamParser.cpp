#include "BitStreamParser.h"



BitStreamParser::BitStreamParser()
{
}


BitStreamParser::~BitStreamParser()
{
}
void BitStreamParser::startParse(std::string model, std::string operation, std::string goldenPath) {
	if (model.compare("Spartan 3E 100") == 0) {
		Model.setDevice_Xa3s100E();
	}
	else if (model.compare("Spartan XC3S50") == 0) {
		Model.setDevice_XC3S50();
	}
	else {
		std::cerr << "Unrecognized device model";
		exit(-1);
	}

	if (operation.compare("LUT") == 0) {
		parseLUT();
	}
	else if (operation.compare("IOB") == 0) {

	}
	else if (operation.compare("Interconnect Resources") == 0) {

	}
	else if (operation.compare("Word Map") == 0) {
		bitAnalyzer.makeWordList(goldenPath);
	}
	else {
		std::cerr << "Unrecognized parse operation";
		exit(-1);
	}
}
void BitStreamParser::parseLUT() {
	printf("Checking if processor is available...");
	if (system(NULL)) puts("Ok");
	else exit(EXIT_FAILURE);
	locateLUTs();
	std::set<std::string> afterNGD = listOfFiles("finishedFileList.txt");
	std::set<std::string> result;
	result = setDifferences(initialFileList, afterNGD);
	deleteResources(result);
}

std::vector<std::string> BitStreamParser::getDefinedParseOperations() {
	definedParseOperations.push_back("LUT");
	definedParseOperations.push_back("IOB");
	definedParseOperations.push_back("Interconnect Resources");
	definedParseOperations.push_back("Word Map");
	return definedParseOperations;
}

void BitStreamParser::locateLUTs() {
	std::vector<Coordinate> LUTCoordinates = Model.getLUTCoordinates();
	synthesizer.synthesisSetup();

	std::ofstream libraryFile;
	libraryFile.open("libraryFile.txt");
	namespace pt = boost::posix_time;
	pt::ptime now = pt::second_clock::local_time();
	std::stringstream ss;
	ss << static_cast<int>(now.date().month()) << "/" << now.date().day() << "/" << now.date().year() << ": " << now.time_of_day() << "\n";
	libraryFile << "Analysis Began At: " << ss.str() << std::endl;
	ss.clear();
	int i = 0;
	lutOffsetResponse t0, t1;
	libraryFile << "#         deviceType   offset   SliceCoordinate   hexCode       time\n";
	const char seperator = ' ';
	const int numWidth = 10;
	const int deviceTypeWidth = 13;
	const int offsetWidth = 8;
	const int sliceCoordinateWidth = 19;
	const int hexCodeWidth = 14;
	const int timeWidth = 16;
	int numberOfLUTS = LUTCoordinates.size();
	for (std::vector<Coordinate>::const_iterator it = LUTCoordinates.begin(); it != LUTCoordinates.end(); ++it) {
		//F_LUT
		initialFileList = listOfFiles("initialFiles.txt");
		t0 = getLUTOffset(F_LUT, *it);
		lib.addEntry(F_LUT, t0, *it);

		libraryFile
			<< std::left << std::setw(numWidth) << std::setfill(seperator) << i
			<< std::left << std::setw(deviceTypeWidth) << std::setfill(seperator) << "F_LUT"
			<< std::left << std::setw(offsetWidth) << std::setfill(seperator) << t0.offset
			<< std::left << std::setw(sliceCoordinateWidth) << std::setfill(seperator) << " SLICE_X" + std::to_string(it->X) + "Y" + std::to_string(it->Y)
			<< std::left << std::setw(hexCodeWidth) << std::setfill(seperator) << t0.hexCode
			<< std::left << std::setw(timeWidth) << std::setfill(seperator) << pt::second_clock::local_time().time_of_day() << std::endl;

		++i;
		cleanUP();


		//G_LUT
		initialFileList = listOfFiles("initialFiles.txt");
		t1 = getLUTOffset(G_LUT, *it);
		lib.addEntry(G_LUT, t1, *it);
		libraryFile
			<< std::left << std::setw(numWidth) << std::setfill(seperator) << i
			<< std::left << std::setw(deviceTypeWidth) << std::setfill(seperator) << "G_LUT"
			<< std::left << std::setw(offsetWidth) << std::setfill(seperator) << t1.offset
			<< std::left << std::setw(sliceCoordinateWidth) << std::setfill(seperator) << " SLICE_X" + std::to_string(it->X) + "Y" + std::to_string(it->Y)
			<< std::left << std::setw(hexCodeWidth) << std::setfill(seperator) << t1.hexCode
			<< std::left << std::setw(timeWidth) << std::setfill(seperator) << pt::second_clock::local_time().time_of_day() << std::endl;
		++i;
		cleanUP();
		emit sendUpdatePercentSignal(double(i / (double)numberOfLUTS));
	}

	//const std::vector<libraryEntry>* lutLibrary = lib.getLibrary();
	now = pt::second_clock::local_time();
	ss << static_cast<int>(now.date().month()) << "/" << now.date().day() << "/" << now.date().year() << ": " << now.time_of_day() << "\n";
	libraryFile.open("libraryFile.txt");
	libraryFile << "File Finished at " << ss.str() << std::endl;
	libraryFile.close();
}
lutOffsetResponse BitStreamParser::readBitFile() {
	BitStreamAnalyzer bitAnalyzer;
	bitAnalyzer.readBitFile(path + "item.bin");
	return bitAnalyzer.getByteOffSet();
}
lutOffsetResponse BitStreamParser::getLUTOffset(DeviceType deviceType, Coordinate coordinate) {
	update_UCF_PCF(deviceType, coordinate);
	synthesizer.synthesize(false);
	return readBitFile();
}

void BitStreamParser::update_UCF_PCF(DeviceType deviceType, Coordinate coordinate) {
	std::set<std::string> files;
	files.insert("item.ucf");
	files.insert("item.pcf");
	deleteResources(files);
	std::ofstream ucfFile;
	ucfFile.open(path + "item.ucf");
	ucfFile << "NET \"XLXN_8\" LOC = P2;\n";
	ucfFile << "NET \"XLXN_7\" LOC = P3;\n";
	if (deviceType == F_LUT) {
		ucfFile << "INST \"XLXI_11\" BEL = F;\n";
	}
	else if (deviceType == G_LUT)
	{
		ucfFile << "INST \"XLXI_11\" BEL = G;\n";
	}
	else {
		std::cerr << "Error in updateUCF: Incorrect Device Type\n";
		exit(1);
	}
	ucfFile << "INST \"XLXI_11\" LOC = SLICE_X" << coordinate.X << "Y" << coordinate.Y << ";\n";
	ucfFile << "NET \"XLXN_6\" LOC = P98;\n";
	ucfFile.close();
}
std::set<std::string> BitStreamParser::setDifferences(std::set<std::string> a, std::set<std::string> b) {
	using namespace std;
	set<string> result;
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
	return result;
}

std::set<std::string> BitStreamParser::listOfFiles(std::string fileName) {
	system(("dir Xilinx\\SingleItemTest /b > " + fileName).c_str());
	std::ifstream tempFile;
	tempFile.open(fileName);
	std::string X;
	std::set<std::string> fileNameSet;
	if (tempFile.is_open()) {
		while (std::getline(tempFile, X)) {
			fileNameSet.insert(X);
		}
	}
	else {
		std::cerr << "Failed to open " + fileName + "\n";
		exit(0);
	}
	tempFile.clear();
	tempFile.close();
	return fileNameSet;
}

void BitStreamParser::deleteResources(std::set<std::string> files) {
	for (std::set<std::string>::iterator it = files.begin(); it != files.end(); ++it) {
		try {
			boost::filesystem::remove_all((path + *it).c_str());
		}
		catch (const std::exception& e) {

		}
	}
}

void BitStreamParser::setPath(std::string path_) {
	path = path_;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	wPath = converter.from_bytes(path_);
	synthesizer.setPath(path, wPath);
}
void BitStreamParser::cleanUP() {
	std::set<std::string> afterSynthesis = listOfFiles("finishedFileList.txt");
	std::set<std::string> result;
	result = setDifferences(initialFileList, afterSynthesis);
	deleteResources(result);
	try {
		boost::filesystem::remove_all("finishedFileList.txt");
	}
	catch (const std::exception& e) {

	}
}