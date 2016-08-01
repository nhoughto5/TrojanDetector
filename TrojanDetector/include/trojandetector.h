#ifndef TROJANDETECTOR_H
#define TROJANDETECTOR_H

#include <QtWidgets/QMainWindow>
#include <iostream>
#include "Library.h"
#include "ui_trojandetector.h"
#include "BitStreamAnalyzer.h"
#include "Device.h"
#include "Analyzer.h"
#include "BitStreamParser.h"
#include "DeviceModel.h"
//Test Change
class TrojanDetector : public QMainWindow
{
	Q_OBJECT

public:
	TrojanDetector(QWidget *parent = 0);
	~TrojanDetector();
private:
	Ui::TrojanDetectorClass ui;
	Library deviceLib;
	bool libraryFileLoaded, goldenChipFileAnalyzed, targetFileLoaded;
	BitStreamAnalyzer goldenBitReader, targetBitReader;
	std::vector<Device> statisticTestDevices;
	std::vector<std::string> definedModels, definedOperations;
	Device goldenDevice, targetDevice;
	QStringList statFileNames;
	QString dir;
	BitStreamParser parser;
	DeviceModel Model;
private slots:
	void updateMessage(double percent);
	void on_goldenFileBrowse_Clicked();
	void on_singleTrojanBrowse_Clicked();
	void on_libraryFileBrowse_Clicked();
	void on_analyzeBtn_Clicked();
	void on_multipleTargetBrowse_Clicked();
	void on_analyzeStatBtn_Clicked();
	void on_xilinxDirectoryBrowse_Clicked();
	void on_parseBtn_Clicked();
};

#endif // TROJANDETECTOR_H
