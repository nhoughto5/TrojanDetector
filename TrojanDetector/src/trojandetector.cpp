#include "trojandetector.h"
#include <QFileDialog>
TrojanDetector::TrojanDetector(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

TrojanDetector::~TrojanDetector()
{

}

void TrojanDetector::on_goldenFileBrowse_Clicked() {
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Golden Chip"),
		"C://", //Default Open
		"Bin File (*.bin)" //File Filters
		);
}

void TrojanDetector::on_singleTrojanBrowse_Clicked() {
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Trojan File"),
		"C://", //Default Open
		"Bin File (*.bin)" //File Filters
		);
}

void TrojanDetector::on_libraryFileBrowse_Clicked() {
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Library File"),
		"C://", //Default Open
		"Text File (*.txt)" //File Filters
		);

	//Convert QString to std::string and send to Library;
	deviceLib.readLibrary(fileName.toLocal8Bit().constData());
}

void TrojanDetector::on_analyzeBtn_Clicked() {
	ui.singleTrojanResponse->setText("Hello");
}