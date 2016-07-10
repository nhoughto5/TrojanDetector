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
