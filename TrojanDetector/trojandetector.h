#ifndef TROJANDETECTOR_H
#define TROJANDETECTOR_H

#include <QtWidgets/QMainWindow>
#include "ui_trojandetector.h"

class TrojanDetector : public QMainWindow
{
	Q_OBJECT

public:
	TrojanDetector(QWidget *parent = 0);
	~TrojanDetector();
	/*void on_goldenFileBrowse_Clicked();*/
private:
	Ui::TrojanDetectorClass ui;

private slots:
	void on_goldenFileBrowse_Clicked();
};

#endif // TROJANDETECTOR_H
