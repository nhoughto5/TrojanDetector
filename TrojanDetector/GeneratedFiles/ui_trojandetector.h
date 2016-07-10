/********************************************************************************
** Form generated from reading UI file 'trojandetector.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TROJANDETECTOR_H
#define UI_TROJANDETECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrojanDetectorClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *goldenFileBrowse;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrojanDetectorClass)
    {
        if (TrojanDetectorClass->objectName().isEmpty())
            TrojanDetectorClass->setObjectName(QStringLiteral("TrojanDetectorClass"));
        TrojanDetectorClass->resize(600, 400);
        centralWidget = new QWidget(TrojanDetectorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 296, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        goldenFileBrowse = new QPushButton(horizontalLayoutWidget);
        goldenFileBrowse->setObjectName(QStringLiteral("goldenFileBrowse"));

        horizontalLayout->addWidget(goldenFileBrowse);

        TrojanDetectorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TrojanDetectorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TrojanDetectorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrojanDetectorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrojanDetectorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrojanDetectorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrojanDetectorClass->setStatusBar(statusBar);

        retranslateUi(TrojanDetectorClass);
        QObject::connect(goldenFileBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_goldenFileBrowse_Clicked()));

        QMetaObject::connectSlotsByName(TrojanDetectorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrojanDetectorClass)
    {
        TrojanDetectorClass->setWindowTitle(QApplication::translate("TrojanDetectorClass", "TrojanDetector", 0));
        label->setText(QApplication::translate("TrojanDetectorClass", "Please Select the .bin file for the golden chip", 0));
        goldenFileBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
    } // retranslateUi

};

namespace Ui {
    class TrojanDetectorClass: public Ui_TrojanDetectorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TROJANDETECTOR_H
