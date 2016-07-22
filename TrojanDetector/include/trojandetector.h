#ifndef TROJANDETECTOR_H
#define TROJANDETECTOR_H

#include <QtWidgets/QMainWindow>
#include <iostream>
#include "Library.h"
#include "ui_trojandetector.h"
#include "BitStreamReader.h"
#include "Device.h"
#include "Analyzer.h"
//Test Change
class TrojanDetector : public QMainWindow
{
	Q_OBJECT

public:
	TrojanDetector(QWidget *parent = 0);
	~TrojanDetector();
	/*void on_goldenFileBrowse_Clicked();*/
private:
	Ui::TrojanDetectorClass ui;
	Library deviceLib;
	bool libraryFileLoaded, goldenChipFileAnalyzed, targetFileLoaded;
	BitStreamReader goldenBitReader, targetBitReader;
	std::vector<Device> statisticTestDevices;
	Device goldenDevice, targetDevice;
	QStringList statFileNames;
	QString dir;
private slots:
	
	void on_goldenFileBrowse_Clicked();
	void on_singleTrojanBrowse_Clicked();
	void on_libraryFileBrowse_Clicked();
	void on_analyzeBtn_Clicked();
	void on_multipleTargetBrowse_Clicked();
	void on_analyzeStatBtn_Clicked();
};

#endif // TROJANDETECTOR_H
