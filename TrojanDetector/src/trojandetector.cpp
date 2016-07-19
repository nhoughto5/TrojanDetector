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
		bool test = Analyzer::analyzeSingle(targetDevice, goldenDevice, deviceLib.getLibrary());
		if (test) {
			ui.singleTrojanResponse->setText("This target contains a trojan");
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