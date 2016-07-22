#include "trojandetector.h"
#include <QFileDialog>
TrojanDetector::TrojanDetector(QWidget *parent)	: 
	QMainWindow(parent),
	goldenChipFileAnalyzed(false),
	libraryFileLoaded(false),
	targetFileLoaded(false)
{
	ui.setupUi(this);
}

TrojanDetector::~TrojanDetector()
{

}

void TrojanDetector::on_goldenFileBrowse_Clicked() {
	goldenChipFileAnalyzed = true;
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Golden Chip"),
		"C://", //Default Open
		"Bin File (*.bin)" //File Filters
		);
	goldenBitReader.clear();
	goldenBitReader.readBitFile(fileName.toLocal8Bit().constData());
	ui.singleTrojanResponse->setText("Sucefully Read Golden Chip File");
}

void TrojanDetector::on_singleTrojanBrowse_Clicked() {
	targetFileLoaded = true;
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Trojan File"),
		"C://", //Default Open
		"Bin File (*.bin)" //File Filters
		);
	targetBitReader.clear();
	targetBitReader.readBitFile(fileName.toLocal8Bit().constData());
	ui.singleTrojanResponse->setText("Sucefully Read Test File");
}

void TrojanDetector::on_libraryFileBrowse_Clicked() {
	libraryFileLoaded = true;
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Library File"),
		"C://", //Default Open
		"Text File (*.txt)" //File Filters
		);
	//Convert QString to std::string and send to Library;
	deviceLib.readLibrary(fileName.toLocal8Bit().constData());
	ui.singleTrojanResponse->setText(QString::fromStdString("Sucesfully Read Library File"));
}

void TrojanDetector::on_multipleTargetBrowse_Clicked() {
	dir.clear();
	dir = QFileDialog::getExistingDirectory(
		this,
		tr("Target Files"),
		"C://",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	QStringList nameFilter("*.bin");
	QDir directory(dir);
	statFileNames = directory.entryList(nameFilter);
	for (int i = 0; i < statFileNames.length(); ++i) {
		ui.binFileViewer->append(QString::fromStdString(std::to_string(i + 1)) + ".)  " + statFileNames.at(i));
	}
}

void TrojanDetector::on_analyzeStatBtn_Clicked() {
	int numFiles = statFileNames.size();
	goldenDevice.loadDevice(goldenBitReader.getHexByteValues(), deviceLib.getLibrary());
	ui.binFileViewer->clear();
	for (QStringList::ConstIterator it = statFileNames.begin(); it != statFileNames.end(); ++it) {
		targetBitReader.clear();
		targetDevice.clear();
		targetBitReader.readBitFile(dir.toStdString() + "/" + it->toLocal8Bit().constData());
		targetDevice.loadDevice(targetBitReader.getHexByteValues(), deviceLib.getLibrary());
		targetDevice.setContainsTrojan(Analyzer::analyzeSingle(goldenDevice, targetDevice, deviceLib.getLibrary()));
		statisticTestDevices.push_back(targetDevice);

		//Contains Trojan, red font
		if (targetDevice.getContainsTrojan()) {
			ui.binFileViewer->append("<p><font color=\"red\">"+ *it + "</font></p>");

		}
		else {
			ui.binFileViewer->append("<p><font color=\"green\">" + *it + "</font></p>");
		}
	}
}

void TrojanDetector::on_analyzeBtn_Clicked() {
	//One of the necessary files has been loaded
	if (libraryFileLoaded && goldenChipFileAnalyzed) {
		ui.singleTrojanResponse->setText("Analyzing");
		targetDevice.loadDevice(targetBitReader.getHexByteValues(), deviceLib.getLibrary());
		goldenDevice.loadDevice(goldenBitReader.getHexByteValues(), deviceLib.getLibrary());
		bool test = Analyzer::analyzeSingle(goldenDevice, targetDevice, deviceLib.getLibrary());
		if (test) {
			ui.singleTrojanResponse->setText("This target contains a trojan");
			std::vector<LUT> infectedList = targetDevice.getInfectedList();
			if (infectedList.size() > 0) {
				ui.singleTrojanResponse->append("Modification found in: ");
				std::string temp, targetHex, goldenHex;
				for (std::vector<LUT>::const_iterator it = infectedList.begin(); it != infectedList.end(); ++it) {
					targetHex = it->hexCode;
					goldenHex = goldenDevice.getLutMap()->find(it->offset)->second.hexCode;
					std::transform(targetHex.begin(), targetHex.end(), targetHex.begin(), toupper);
					std::transform(goldenHex.begin(), goldenHex.end(), goldenHex.begin(), toupper);
					temp = "Slice_X" + std::to_string(it->xyCoordinate.X) + "Y" + std::to_string(it->xyCoordinate.Y) + "    ->  Target device contained: " + targetHex + "   Golden hex Value: " + goldenHex;
					ui.singleTrojanResponse->append(QString::fromStdString(temp));
					temp.clear(); targetHex.clear(); goldenHex.clear();
				}
			}
			else {
				ui.singleTrojanResponse->append("Error: Failed to retreive infected list");
			}

		}
		else {
			ui.singleTrojanResponse->setText("This target does not contain a trojan");
		}
		
	}
	else if (libraryFileLoaded && !targetFileLoaded) {
		ui.singleTrojanResponse->setText("Please load a test file");		
	}
	else if (goldenChipFileAnalyzed && !targetFileLoaded) {
		ui.singleTrojanResponse->setText("Please load a test file");
	}
	else {
		ui.singleTrojanResponse->setText("Error: Please load a library file or add a golden chip bin file for analysis");
	}
}