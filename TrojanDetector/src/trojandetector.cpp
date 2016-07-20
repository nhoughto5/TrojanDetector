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

void TrojanDetector::on_multipleTargetBrowse_Clicked() {

}