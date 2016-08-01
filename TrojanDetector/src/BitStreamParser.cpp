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
		bitAnalyzer.getWordList(goldenPath);
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
	makeDirectories();
	makeInitFiles();
	locateLUTs();
	std::set<std::string> afterNGD = listOfFiles("finishedFileList.txt");
	std::set<std::string> result;
	result = setDifferences(initialFileList, afterNGD);
	deleteResources(result);
}
void BitStreamParser::makeDirectories(){
	std::string outputFolder = path + "xst";
	CreateDirectoryA(outputFolder.c_str(), NULL);
	outputFolder = path + "xst/projnav.tmp";
	CreateDirectoryA(outputFolder.c_str(), NULL);
}

std::vector<std::string> BitStreamParser::getDefinedParseOperations() {
	definedParseOperations.push_back("LUT");
	definedParseOperations.push_back("IOB");
	definedParseOperations.push_back("Interconnect Resources");
	definedParseOperations.push_back("Word Map");
	return definedParseOperations;
}
void BitStreamParser::initialSynthesis() {
	synthesizer.convertSchematicToHDL(path);
	std::wstring xstPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\xst.exe";
	std::wstring xstArgs = L"-intstyle silent -ifn " + wPath + L"/item.xst -ofn "+ wPath +L"/item.syr";
	synthesizer.ExecuteProcess(xstPath, xstArgs, 10, wPath);
}
void sendUpdatePercentSignal(double percent) {
	emit percent;
}
void BitStreamParser::locateLUTs() {
	std::vector<Coordinate> LUTCoordinates = Model.getLUTCoordinates();
	initialSynthesis();

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
		sendUpdatePercentSignal(double(i / numberOfLUTS));
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
	std::wstring ngdPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\ngdbuild.exe";
	std::wstring mapPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\map.exe";
	std::wstring trcePath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\trce.exe";
	std::wstring parPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\par.exe";
	std::wstring bitgenPath = L"C:\\Xilinx\\14.7\\ISE_DS\\ISE\\bin\\nt\\bitgen.exe";
	std::wstring ngdArgs = L"-intstyle silent -quiet -dd _ngo -nt timestamp -uc item.ucf -p xa3s100e-vqg100-4 item.ngc item.ngd";
	std::wstring mapArgs = L"-intstyle silent -p xa3s100e-vqg100-4 -cm area -ir off -pr off -c 100 -o item_map.ncd item.ngd item.pcf";
	std::wstring parArgs = L"-intstyle silent -ol high -t 1 item_map.ncd item.ncd item.pcf";
	std::wstring trceArgs = L"-intstyle silent -v 3 -s 4 -n 3 -fastpaths -xml item.twx item.ncd -o item.twr item.pcf -ucf item.ucf";
	std::wstring bitgenArgs = L"-intstyle silent -f item.ut item.ncd";
	synthesizer.ExecuteProcess(ngdPath, ngdArgs, 10, wPath);
	synthesizer.ExecuteProcess(mapPath, mapArgs, 10, wPath);
	synthesizer.ExecuteProcess(parPath, parArgs, 10, wPath);
	synthesizer.ExecuteProcess(trcePath, trceArgs, 10, wPath);
	synthesizer.ExecuteProcess(bitgenPath, bitgenArgs, 10, wPath);
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

	////Update PCF
	//std::ofstream pcfFile;
	//pcfFile.open(path + "item.pcf");
	//pcfFile << "SCHEMATIC START;\n";
	//pcfFile << "COMP \"XLXN_6\" LOCATE = SITE \"P98\" LEVEL 1;\n";
	//pcfFile << "COMP \"XLXN_7\" LOCATE = SITE \"P3\" LEVEL 1;\n";
	//pcfFile << "COMP \"XLXN_8\" LOCATE = SITE \"P2\" LEVEL 1;\n";
	//pcfFile << "COMP \"XLXN_8_OBUF\" LOCATE = SITE \"SLICE_X0Y42\" LEVEL 1;\n";
	//pcfFile << "SCHEMATIC END;\n";
	//pcfFile.close();

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

void BitStreamParser::makeInitFiles() {
	std::ofstream schematicFile;
	std::fstream xml;
	xml.open("Extra/schematicTemplate.xml");
	schematicFile.open(path + "item.sch");
	std::string line;
	while (xml.good())
	{
		getline(xml, line);
		schematicFile << line << "\n";
	}
	schematicFile.close();
	xml.close();



	std::ofstream sch2HdlBatchFile;
	sch2HdlBatchFile.open(path + "sch2HdlBatchFile");
	sch2HdlBatchFile << "sch2hdl,-intstyle,ise,-family,aspartan3e,-flat,-suppress,-vhdl," + path + "item.vhf,-w," + path + "item.sch";
	sch2HdlBatchFile.close();

	std::ofstream prjFile;
	prjFile.open(path + "item.prj");
	prjFile << "vhdl work \"item.vhf\"";
	prjFile.close();

	std::ofstream syrFile;
	syrFile.open(path + "item.syr");
	syrFile.close();

	std::ofstream xstFile;
	xstFile.open(path + "item.xst");
	xstFile << "set -tmpdir \"xst/projnav.tmp\"\n";
	xstFile << "set -xsthdpdir \"xst\"\n";
	xstFile << "run\n";
	xstFile << ("-ifn " + path + "item.prj\n").c_str();
	xstFile << "-ifmt mixed\n";
	xstFile << "-ofn item\n";
	xstFile << "-ofmt NGC\n";
	xstFile << "-p xa3s100e-4-vqg100\n";
	xstFile << "-top item\n";
	xstFile << "-opt_mode Speed\n";
	xstFile << "-opt_level 1\n";
	xstFile << "-iuc NO\n";
	xstFile << "-keep_hierarchy No\n";
	xstFile << "-netlist_hierarchy As_Optimized\n";
	xstFile << "-rtlview Yes\n";
	xstFile << "-glob_opt AllClockNets\n";
	xstFile << "-read_cores YES\n";
	xstFile << "-write_timing_constraints NO\n";
	xstFile << "-cross_clock_analysis NO\n";
	xstFile << "-hierarchy_separator /\n";
	xstFile << "-bus_delimiter <>\n";
	xstFile << "-case Maintain\n";
	xstFile << "-slice_utilization_ratio 100\n";
	xstFile << "-bram_utilization_ratio 100\n";
	xstFile << "-verilog2001 YES\n";
	xstFile << "-fsm_extract YES -fsm_encoding Auto\n";
	xstFile << "-safe_implementation No\n";
	xstFile << "-fsm_style LUT\n";
	xstFile << "-ram_extract Yes\n";
	xstFile << "-ram_style Auto\n";
	xstFile << "-rom_extract Yes\n";
	xstFile << "-mux_style Auto\n";
	xstFile << "-decoder_extract YES\n";
	xstFile << "-priority_extract Yes\n";
	xstFile << "-shreg_extract YES\n";
	xstFile << "-shift_extract YES\n";
	xstFile << "-xor_collapse YES\n";
	xstFile << "-rom_style Auto\n";
	xstFile << "-auto_bram_packing NO\n";
	xstFile << "-mux_extract Yes\n";
	xstFile << "-resource_sharing YES\n";
	xstFile << "-async_to_sync NO\n";
	xstFile << "-mult_style Auto\n";
	xstFile << "-iobuf YES\n";
	xstFile << "-max_fanout 100000\n";
	xstFile << "-bufg 24\n";
	xstFile << "-register_duplication YES\n";
	xstFile << "-register_balancing No\n";
	xstFile << "-slice_packing YES\n";
	xstFile << "-optimize_primitives NO\n";
	xstFile << "-use_clock_enable Yes\n";
	xstFile << "-use_sync_set Yes\n";
	xstFile << "-use_sync_reset Yes\n";
	xstFile << "-iob Auto\n";
	xstFile << "-equivalent_register_removal YES\n";
	xstFile << "-slice_utilization_ratio_maxmargin 5\n";
	xstFile.close();

	std::ofstream utFile;
	utFile.open(path + "item.ut");
	utFile << "-w\n";
	utFile << "-g DebugBitstream:No\n";
	utFile << "-g Binary:yes\n";
	utFile << "-g CRC:Enable\n";
	utFile << "-g ConfigRate:1\n";
	utFile << "-g ProgPin:PullUp\n";
	utFile << "-g DonePin:PullUp\n";
	utFile << "-g TckPin:PullUp\n";
	utFile << "-g TdiPin:PullUp\n";
	utFile << "-g TdoPin:PullUp\n";
	utFile << "-g TmsPin:PullUp\n";
	utFile << "-g UnusedPin:PullDown\n";
	utFile << "-g UserID:0xFFFFFFFF\n";
	utFile << "-g DCMShutdown:Disable\n";
	utFile << "-g StartUpClk:CClk\n";
	utFile << "-g DONE_cycle:4\n";
	utFile << "-g GTS_cycle:5\n";
	utFile << "-g GWE_cycle:6\n";
	utFile << "-g LCK_cycle:NoWait\n";
	utFile << "-g Security:None\n";
	utFile << "-g DonePipe:Yes\n";
	utFile << "-g DriveDone:No\n";
	utFile.close();
}