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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrojanDetectorClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *SingleTrojanTest;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *singleTrojanBrowse;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QWidget *StatTest;
    QWidget *widget1;
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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrojanDetectorClass)
    {
        if (TrojanDetectorClass->objectName().isEmpty())
            TrojanDetectorClass->setObjectName(QStringLiteral("TrojanDetectorClass"));
        TrojanDetectorClass->resize(717, 400);
        centralWidget = new QWidget(TrojanDetectorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 110, 701, 241));
        tabWidget->setAutoFillBackground(true);
        SingleTrojanTest = new QWidget();
        SingleTrojanTest->setObjectName(QStringLiteral("SingleTrojanTest"));
        widget = new QWidget(SingleTrojanTest);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 394, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        singleTrojanBrowse = new QPushButton(widget);
        singleTrojanBrowse->setObjectName(QStringLiteral("singleTrojanBrowse"));
        singleTrojanBrowse->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(singleTrojanBrowse);

        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        tabWidget->addTab(SingleTrojanTest, QString());
        StatTest = new QWidget();
        StatTest->setObjectName(QStringLiteral("StatTest"));
        tabWidget->addTab(StatTest, QString());
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 689, 60));
        horizontalLayout_8 = new QHBoxLayout(widget1);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(widget1);
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
        groupBox_3 = new QGroupBox(widget1);
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
        groupBox->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(TrojanDetectorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
        TrojanDetectorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrojanDetectorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrojanDetectorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrojanDetectorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrojanDetectorClass->setStatusBar(statusBar);

        retranslateUi(TrojanDetectorClass);
        QObject::connect(goldenFileBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_goldenFileBrowse_Clicked()));
        QObject::connect(libraryFileBrowse, SIGNAL(clicked()), TrojanDetectorClass, SLOT(on_libraryFileBrowse_Clicked()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TrojanDetectorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrojanDetectorClass)
    {
        TrojanDetectorClass->setWindowTitle(QApplication::translate("TrojanDetectorClass", "TrojanDetector", 0));
        label_2->setText(QApplication::translate("TrojanDetectorClass", "Please Select the .bin file for the trojan", 0));
        singleTrojanBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        pushButton->setText(QApplication::translate("TrojanDetectorClass", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(SingleTrojanTest), QApplication::translate("TrojanDetectorClass", "Single Trojan Test", 0));
        tabWidget->setTabText(tabWidget->indexOf(StatTest), QApplication::translate("TrojanDetectorClass", "Automated Statistic Test", 0));
        groupBox->setTitle(QApplication::translate("TrojanDetectorClass", "Golden Chip", 0));
        label->setText(QApplication::translate("TrojanDetectorClass", "Please Select the .bin file for the golden chip", 0));
        goldenFileBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
        groupBox_3->setTitle(QApplication::translate("TrojanDetectorClass", "Library File", 0));
        label_3->setText(QApplication::translate("TrojanDetectorClass", "Add the Library File for the chosen device", 0));
        libraryFileBrowse->setText(QApplication::translate("TrojanDetectorClass", "Open", 0));
    } // retranslateUi

};

namespace Ui {
    class TrojanDetectorClass: public Ui_TrojanDetectorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TROJANDETECTOR_H
