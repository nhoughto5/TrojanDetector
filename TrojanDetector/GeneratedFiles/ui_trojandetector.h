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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrojanDetectorClass
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *SingleTrojanTest;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *singleTrojanBrowse;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *analyzeBtn;
    QLabel *label_2;
    QTextBrowser *singleTrojanResponse;
    QWidget *StatTest;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *multipleTargetBrowse;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *analyzeStatBtn;
    QLabel *label_4;
    QTextBrowser *binFileViewer;
    QGroupBox *groupBox_2;
    QWidget *tab;
    QTextBrowser *bitstreamParseTextBox;
    QPushButton *parseBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *xilinxDirectoryBrowse;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *deviceModelComboBox;
    QLabel *label_7;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *parseTargetComboBox;
    QLabel *label_6;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *goldenFileBrowse;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *libraryFileBrowse;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrojanDetectorClass)
    {
        if (TrojanDetectorClass->objectName().isEmpty())
            TrojanDetectorClass->setObjectName(QStringLiteral("TrojanDetectorClass"));
        TrojanDetectorClass->resize(717, 400);
        actionExit = new QAction(TrojanDetectorClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(TrojanDetectorClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(TrojanDetectorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 110, 701, 241));
        tabWidget->setAutoFillBackground(true);
        SingleTrojanTest = new QWidget();
        SingleTrojanTest->setObjectName(QStringLiteral("SingleTrojanTest"));
        horizontalLayoutWidget_2 = new QWidget(SingleTrojanTest);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 10, 381, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        singleTrojanBrowse = new QPushButton(horizontalLayoutWidget_2);
        singleTrojanBrowse->setObjectName(QStringLiteral("singleTrojanBrowse"));
        singleTrojanBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(singleTrojanBrowse);

        horizontalSpacer_3 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        analyzeBtn = new QPushButton(horizontalLayoutWidget_2);
        analyzeBtn->setObjectName(QStringLiteral("analyzeBtn"));

        horizontalLayout_4->addWidget(analyzeBtn);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        singleTrojanResponse = new QTextBrowser(SingleTrojanTest);
        singleTrojanResponse->setObjectName(QStringLiteral("singleTrojanResponse"));
        singleTrojanResponse->setGeometry(QRect(0, 60, 691, 151));
        singleTrojanResponse->setUndoRedoEnabled(false);
        tabWidget->addTab(SingleTrojanTest, QString());
        StatTest = new QWidget();
        StatTest->setObjectName(QStringLiteral("StatTest"));
        horizontalLayoutWidget_3 = new QWidget(StatTest);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(12, 12, 381, 25));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        multipleTargetBrowse = new QPushButton(horizontalLayoutWidget_3);
        multipleTargetBrowse->setObjectName(QStringLiteral("multipleTargetBrowse"));
        multipleTargetBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(multipleTargetBrowse);

        horizontalSpacer_6 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        analyzeStatBtn = new QPushButton(horizontalLayoutWidget_3);
        analyzeStatBtn->setObjectName(QStringLiteral("analyzeStatBtn"));

        horizontalLayout_5->addWidget(analyzeStatBtn);

        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        binFileViewer = new QTextBrowser(StatTest);
        binFileViewer->setObjectName(QStringLiteral("binFileViewer"));
        binFileViewer->setGeometry(QRect(11, 40, 381, 171));
        groupBox_2 = new QGroupBox(StatTest);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 10, 291, 201));
        tabWidget->addTab(StatTest, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        bitstreamParseTextBox = new QTextBrowser(tab);
        bitstreamParseTextBox->setObjectName(QStringLiteral("bitstreamParseTextBox"));
        bitstreamParseTextBox->setGeometry(QRect(0, 71, 691, 141));
        parseBtn = new QPushButton(tab);
        parseBtn->setObjectName(QStringLiteral("parseBtn"));
        parseBtn->setGeometry(QRect(610, 40, 75, 23));
        parseBtn->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(401, 11, 283, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(6, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        xilinxDirectoryBrowse = new QPushButton(layoutWidget);
        xilinxDirectoryBrowse->setObjectName(QStringLiteral("xilinxDirectoryBrowse"));
        xilinxDirectoryBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(xilinxDirectoryBrowse);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 301, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        deviceModelComboBox = new QComboBox(layoutWidget1);
        deviceModelComboBox->setObjectName(QStringLiteral("deviceModelComboBox"));

        horizontalLayout_9->addWidget(deviceModelComboBox);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 301, 22));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        parseTargetComboBox = new QComboBox(layoutWidget2);
        parseTargetComboBox->setObjectName(QStringLiteral("parseTargetComboBox"));

        horizontalLayout_10->addWidget(parseTargetComboBox);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        tabWidget->addTab(tab, QString());
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 689, 60));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(layoutWidget3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(28, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        goldenFileBrowse = new QPushButton(groupBox);
        goldenFileBrowse->setObjectName(QStringLiteral("goldenFileBrowse"));
        goldenFileBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(goldenFileBrowse);


        horizontalLayout_2->addWidget(groupBox);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_3 = new QGroupBox(layoutWidget3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(6, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        libraryFileBrowse = new QPushButton(groupBox_3);
        libraryFileBrowse->setObjectName(QStringLiteral("libraryFileBrowse"));
        libraryFileBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(libraryFileBrowse);


        horizontalLayout_6->addWidget(groupBox_3);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        TrojanDetectorClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(TrojanDetectorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        TrojanDetectorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrojanDetectorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrojanDetectorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrojanDetectorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrojanDetectorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(TrojanDetectorClass);
        QObject::connect(goldenFileBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_goldenFileBrowse_Clicked()));
        QObject::connect(libraryFileBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_libraryFileBrowse_Clicked()));
        QObject::connect(analyzeBtn, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_analyzeBtn_Clicked()));
        QObject::connect(actionExit, SIGNAL(triggered()), TrojanDetectorClass, SLOT(close()));
        QObject::connect(singleTrojanBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_singleTrojanBrowse_Clicked()));
        QObject::connect(multipleTargetBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_multipleTargetBrowse_Clicked()));
        QObject::connect(analyzeStatBtn, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_analyzeStatBtn_Clicked()));
        QObject::connect(parseBtn, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_parseBtn_Clicked()));
        QObject::connect(xilinxDirectoryBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_xilinxDirectoryBrowse_Clicked()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TrojanDetectorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrojanDetectorClass)
    {
        TrojanDetectorClass->setWindowTitle(QApplication::translate("TrojanDetectorClass", "Trojan Detector", 0));
        actionExit->setText(QApplication::translate("TrojanDetectorClass", "Exit", 0));
        actionAbout->setText(QApplication::translate("TrojanDetectorClass", "About", 0));
        singleTrojanBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        analyzeBtn->setText(QApplication::translate("TrojanDetectorClass", "Analyze", 0));
        label_2->setText(QApplication::translate("TrojanDetectorClass", "Please Select the .bin file for the trojan", 0));
        tabWidget->setTabText(tabWidget->indexOf(SingleTrojanTest), QApplication::translate("TrojanDetectorClass", "Single Trojan Test", 0));
        multipleTargetBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        analyzeStatBtn->setText(QApplication::translate("TrojanDetectorClass", "Analyze", 0));
        label_4->setText(QApplication::translate("TrojanDetectorClass", "Select a foldercontaining target .bin files", 0));
        groupBox_2->setTitle(QApplication::translate("TrojanDetectorClass", "Statistics", 0));
        tabWidget->setTabText(tabWidget->indexOf(StatTest), QApplication::translate("TrojanDetectorClass", "Automated Statistic Test", 0));
        parseBtn->setText(QApplication::translate("TrojanDetectorClass", "Parse", 0));
        label_5->setText(QApplication::translate("TrojanDetectorClass", "Choose Directory Containing Xilinx Files", 0));
        xilinxDirectoryBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        label_7->setText(QApplication::translate("TrojanDetectorClass", "Select Device Model", 0));
        label_6->setText(QApplication::translate("TrojanDetectorClass", "Select Parse Target", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TrojanDetectorClass", "Bitstream Parser", 0));
        groupBox->setTitle(QApplication::translate("TrojanDetectorClass", "Golden Chip", 0));
        label->setText(QApplication::translate("TrojanDetectorClass", "Please Select the .bin file for the golden chip", 0));
        goldenFileBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        groupBox_3->setTitle(QApplication::translate("TrojanDetectorClass", "Library File", 0));
        label_3->setText(QApplication::translate("TrojanDetectorClass", "Add the Library File for the chosen device", 0));
        libraryFileBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        menuFile->setTitle(QApplication::translate("TrojanDetectorClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("TrojanDetectorClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class TrojanDetectorClass: public Ui_TrojanDetectorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TROJANDETECTOR_H
