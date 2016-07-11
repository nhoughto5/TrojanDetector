#ifndef TROJANDETECTOR_H
#define TROJANDETECTOR_H

#include <QtWidgets/QMainWindow>
#include "ui_trojandetector.h"
#include "Library.h"
#include <iostream>
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
private slots:
	
	void on_goldenFileBrowse_Clicked();
	void on_singleTrojanBrowse_Clicked();
	void on_libraryFileBrowse_Clicked();
	void on_analyzeBtn_Clicked();
};

#endif // TROJANDETECTOR_H
