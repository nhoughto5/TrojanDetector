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
#include "Synthesizer.h"
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
	bool parseDirectoryChosen, libraryFileLoaded, goldenChipFileAnalyzed, targetFileLoaded, synthPathSet;
	BitStreamAnalyzer goldenBitReader, targetBitReader;
	std::vector<Device> statisticTestDevices;
	std::vector<std::string> definedModels, definedOperations;
	Device goldenDevice, targetDevice;
	QStringList statFileNames;
	QString dir, synthesisDir;
	BitStreamParser parser;
	DeviceModel Model;
	Synthesizer syn;
private slots:
	void updateParseProgress(double percent);
	void updateProgress(double p);
	void on_goldenFileBrowse_Clicked();
	void on_singleTrojanBrowse_Clicked();
	void on_libraryFileBrowse_Clicked();
	void on_analyzeBtn_Clicked();
	void on_multipleTargetBrowse_Clicked();
	void on_analyzeStatBtn_Clicked();
	void on_xilinxDirectoryBrowse_Clicked();
	void on_parseBtn_Clicked();
	void on_selectSynthesisFolder_Btn_Clicked();
	void on_synthesizeBtn_Clicked();
	void on_clearFolderBtn_Clicked();
};

#endif // TROJANDETECTOR_H
