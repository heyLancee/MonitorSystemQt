/********************************************************************************
** Form generated from reading UI file 'visualWin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALWIN_H
#define UI_VISUALWIN_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visualWin
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *Layout1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *BindPortspinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *TargetAddresslineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *TargetPortspinBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_20;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *StartButton;
    QPushButton *StopButton;
    QPushButton *RunPlatformButton;
    QPushButton *StopPlatformButton;
    QPushButton *OpenNewWidgetButton_2;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_5;
    QDoubleSpinBox *simulationTimeSpin;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QPlainTextEdit *plainUdpClientTextEdit;
    QPushButton *ClearUdpClientTextButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QChartView *chartView_WX;
    QChartView *chartView_WY;
    QHBoxLayout *horizontalLayout_18;
    QChartView *chartView_WZ;
    QChartView *chartView_tmp;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QChartView *chartView_q0;
    QChartView *chartView_q1;
    QHBoxLayout *horizontalLayout_8;
    QChartView *chartView_q2;
    QChartView *chartView_q3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QChartView *chartView_RX;
    QChartView *chartView_RY;
    QHBoxLayout *horizontalLayout_10;
    QChartView *chartView_RZ;
    QChartView *graphicsView_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_11;
    QChartView *chartView_VX;
    QChartView *chartView_VY;
    QHBoxLayout *horizontalLayout_12;
    QChartView *chartView_VZ;
    QChartView *graphicsView_3;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_13;
    QChartView *chartView_WboX;
    QChartView *chartView_WboY;
    QHBoxLayout *horizontalLayout_14;
    QChartView *chartView_WboZ;
    QChartView *graphicsView_4;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QChartView *chartView_qbo0;
    QChartView *chartView_qbo1;
    QHBoxLayout *horizontalLayout_16;
    QChartView *chartView_qbo2;
    QChartView *chartView_qbo3;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout_17;
    QChartView *chartView_zAngular;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *visualWin)
    {
        if (visualWin->objectName().isEmpty())
            visualWin->setObjectName("visualWin");
        visualWin->resize(1767, 780);
        centralwidget = new QWidget(visualWin);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(451, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/res/images/hit.jpg")));

        horizontalLayout_21->addWidget(label_4);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        Layout1 = new QVBoxLayout();
        Layout1->setObjectName("Layout1");
        Layout1->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        BindPortspinBox = new QSpinBox(groupBox);
        BindPortspinBox->setObjectName("BindPortspinBox");
        BindPortspinBox->setMaximum(65535);
        BindPortspinBox->setValue(1200);

        horizontalLayout->addWidget(BindPortspinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        Layout1->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        TargetAddresslineEdit = new QLineEdit(groupBox);
        TargetAddresslineEdit->setObjectName("TargetAddresslineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TargetAddresslineEdit->sizePolicy().hasHeightForWidth());
        TargetAddresslineEdit->setSizePolicy(sizePolicy1);
        TargetAddresslineEdit->setMaximumSize(QSize(151, 16777215));

        horizontalLayout_2->addWidget(TargetAddresslineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        Layout1->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        TargetPortspinBox = new QSpinBox(groupBox);
        TargetPortspinBox->setObjectName("TargetPortspinBox");
        TargetPortspinBox->setMaximum(65535);
        TargetPortspinBox->setValue(5010);

        horizontalLayout_3->addWidget(TargetPortspinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        Layout1->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(Layout1, 0, 0, 1, 1);


        horizontalLayout_21->addWidget(groupBox);


        verticalLayout_6->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        StartButton = new QPushButton(groupBox_2);
        StartButton->setObjectName("StartButton");
        StartButton->setEnabled(true);
        StartButton->setMinimumSize(QSize(116, 40));

        verticalLayout_2->addWidget(StartButton);

        StopButton = new QPushButton(groupBox_2);
        StopButton->setObjectName("StopButton");
        StopButton->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(StopButton);

        RunPlatformButton = new QPushButton(groupBox_2);
        RunPlatformButton->setObjectName("RunPlatformButton");
        RunPlatformButton->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(RunPlatformButton);

        StopPlatformButton = new QPushButton(groupBox_2);
        StopPlatformButton->setObjectName("StopPlatformButton");
        StopPlatformButton->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(StopPlatformButton);

        OpenNewWidgetButton_2 = new QPushButton(groupBox_2);
        OpenNewWidgetButton_2->setObjectName("OpenNewWidgetButton_2");
        OpenNewWidgetButton_2->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(OpenNewWidgetButton_2);


        verticalLayout_7->addLayout(verticalLayout_2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout_19->addWidget(label_5);

        simulationTimeSpin = new QDoubleSpinBox(groupBox_2);
        simulationTimeSpin->setObjectName("simulationTimeSpin");
        simulationTimeSpin->setMaximum(99999.000000000000000);
        simulationTimeSpin->setValue(100.000000000000000);

        horizontalLayout_19->addWidget(simulationTimeSpin);


        verticalLayout_7->addLayout(horizontalLayout_19);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");
        checkBox->setChecked(true);

        verticalLayout_7->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setChecked(false);

        verticalLayout_7->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setChecked(false);

        verticalLayout_7->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setChecked(false);

        verticalLayout_7->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setChecked(false);

        verticalLayout_7->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setChecked(false);

        verticalLayout_7->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setChecked(false);

        verticalLayout_7->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName("checkBox_8");
        QFont font;
        font.setBold(true);
        checkBox_8->setFont(font);
        checkBox_8->setChecked(false);

        verticalLayout_7->addWidget(checkBox_8);


        verticalLayout_11->addLayout(verticalLayout_7);

        verticalLayout_11->setStretch(0, 1);

        gridLayout->addLayout(verticalLayout_11, 0, 0, 1, 1);


        horizontalLayout_20->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);

        plainUdpClientTextEdit = new QPlainTextEdit(groupBox_3);
        plainUdpClientTextEdit->setObjectName("plainUdpClientTextEdit");
        sizePolicy.setHeightForWidth(plainUdpClientTextEdit->sizePolicy().hasHeightForWidth());
        plainUdpClientTextEdit->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(plainUdpClientTextEdit);

        ClearUdpClientTextButton = new QPushButton(groupBox_3);
        ClearUdpClientTextButton->setObjectName("ClearUdpClientTextButton");
        ClearUdpClientTextButton->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(ClearUdpClientTextButton);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 100);
        verticalLayout_3->setStretch(2, 1);

        horizontalLayout_20->addLayout(verticalLayout_3);

        horizontalLayout_20->setStretch(0, 1);
        horizontalLayout_20->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_20);


        horizontalLayout_4->addWidget(groupBox_3);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        chartView_WX = new QChartView(tab);
        chartView_WX->setObjectName("chartView_WX");

        horizontalLayout_5->addWidget(chartView_WX);

        chartView_WY = new QChartView(tab);
        chartView_WY->setObjectName("chartView_WY");

        horizontalLayout_5->addWidget(chartView_WY);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        chartView_WZ = new QChartView(tab);
        chartView_WZ->setObjectName("chartView_WZ");

        horizontalLayout_18->addWidget(chartView_WZ);

        chartView_tmp = new QChartView(tab);
        chartView_tmp->setObjectName("chartView_tmp");

        horizontalLayout_18->addWidget(chartView_tmp);


        verticalLayout_4->addLayout(horizontalLayout_18);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_9 = new QHBoxLayout(tab_2);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        chartView_q0 = new QChartView(tab_2);
        chartView_q0->setObjectName("chartView_q0");

        horizontalLayout_7->addWidget(chartView_q0);

        chartView_q1 = new QChartView(tab_2);
        chartView_q1->setObjectName("chartView_q1");

        horizontalLayout_7->addWidget(chartView_q1);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        chartView_q2 = new QChartView(tab_2);
        chartView_q2->setObjectName("chartView_q2");

        horizontalLayout_8->addWidget(chartView_q2);

        chartView_q3 = new QChartView(tab_2);
        chartView_q3->setObjectName("chartView_q3");

        horizontalLayout_8->addWidget(chartView_q3);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        chartView_RX = new QChartView(tab_3);
        chartView_RX->setObjectName("chartView_RX");

        horizontalLayout_6->addWidget(chartView_RX);

        chartView_RY = new QChartView(tab_3);
        chartView_RY->setObjectName("chartView_RY");

        horizontalLayout_6->addWidget(chartView_RY);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        chartView_RZ = new QChartView(tab_3);
        chartView_RZ->setObjectName("chartView_RZ");

        horizontalLayout_10->addWidget(chartView_RZ);

        graphicsView_2 = new QChartView(tab_3);
        graphicsView_2->setObjectName("graphicsView_2");

        horizontalLayout_10->addWidget(graphicsView_2);


        verticalLayout_8->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        chartView_VX = new QChartView(tab_4);
        chartView_VX->setObjectName("chartView_VX");

        horizontalLayout_11->addWidget(chartView_VX);

        chartView_VY = new QChartView(tab_4);
        chartView_VY->setObjectName("chartView_VY");

        horizontalLayout_11->addWidget(chartView_VY);


        verticalLayout_9->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        chartView_VZ = new QChartView(tab_4);
        chartView_VZ->setObjectName("chartView_VZ");

        horizontalLayout_12->addWidget(chartView_VZ);

        graphicsView_3 = new QChartView(tab_4);
        graphicsView_3->setObjectName("graphicsView_3");

        horizontalLayout_12->addWidget(graphicsView_3);


        verticalLayout_9->addLayout(horizontalLayout_12);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        verticalLayout_10 = new QVBoxLayout(tab_5);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        chartView_WboX = new QChartView(tab_5);
        chartView_WboX->setObjectName("chartView_WboX");

        horizontalLayout_13->addWidget(chartView_WboX);

        chartView_WboY = new QChartView(tab_5);
        chartView_WboY->setObjectName("chartView_WboY");

        horizontalLayout_13->addWidget(chartView_WboY);


        verticalLayout_10->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        chartView_WboZ = new QChartView(tab_5);
        chartView_WboZ->setObjectName("chartView_WboZ");

        horizontalLayout_14->addWidget(chartView_WboZ);

        graphicsView_4 = new QChartView(tab_5);
        graphicsView_4->setObjectName("graphicsView_4");

        horizontalLayout_14->addWidget(graphicsView_4);


        verticalLayout_10->addLayout(horizontalLayout_14);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        verticalLayout = new QVBoxLayout(tab_6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        chartView_qbo0 = new QChartView(tab_6);
        chartView_qbo0->setObjectName("chartView_qbo0");

        horizontalLayout_15->addWidget(chartView_qbo0);

        chartView_qbo1 = new QChartView(tab_6);
        chartView_qbo1->setObjectName("chartView_qbo1");

        horizontalLayout_15->addWidget(chartView_qbo1);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        chartView_qbo2 = new QChartView(tab_6);
        chartView_qbo2->setObjectName("chartView_qbo2");

        horizontalLayout_16->addWidget(chartView_qbo2);

        chartView_qbo3 = new QChartView(tab_6);
        chartView_qbo3->setObjectName("chartView_qbo3");

        horizontalLayout_16->addWidget(chartView_qbo3);


        verticalLayout->addLayout(horizontalLayout_16);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        horizontalLayout_17 = new QHBoxLayout(tab_7);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        chartView_zAngular = new QChartView(tab_7);
        chartView_zAngular->setObjectName("chartView_zAngular");

        horizontalLayout_17->addWidget(chartView_zAngular);

        tabWidget->addTab(tab_7, QString());

        horizontalLayout_4->addWidget(tabWidget);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        visualWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(visualWin);
        statusbar->setObjectName("statusbar");
        visualWin->setStatusBar(statusbar);

        retranslateUi(visualWin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(visualWin);
    } // setupUi

    void retranslateUi(QMainWindow *visualWin)
    {
        visualWin->setWindowTitle(QCoreApplication::translate("visualWin", "Software", nullptr));
        groupBox_3->setTitle(QString());
        label_4->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("visualWin", "Communication Module", nullptr));
        label->setText(QCoreApplication::translate("visualWin", "<html><head/><body><p>Bind Port</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("visualWin", "<html><head/><body><p>Target Address</p></body></html>", nullptr));
        TargetAddresslineEdit->setText(QCoreApplication::translate("visualWin", "127.0.0.1", nullptr));
        label_3->setText(QCoreApplication::translate("visualWin", "<html><head/><body><p>Target Port</p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("visualWin", "Control Module", nullptr));
        StartButton->setText(QCoreApplication::translate("visualWin", "Start Communication", nullptr));
        StopButton->setText(QCoreApplication::translate("visualWin", "Stop Communication", nullptr));
        RunPlatformButton->setText(QCoreApplication::translate("visualWin", "Start Platform", nullptr));
        StopPlatformButton->setText(QCoreApplication::translate("visualWin", "Stop Platform", nullptr));
        OpenNewWidgetButton_2->setText(QCoreApplication::translate("visualWin", "Diagnosis Window", nullptr));
        label_5->setText(QCoreApplication::translate("visualWin", "<html><head/><body><p>Simulation Time(s)</p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("visualWin", "Angular Velocity", nullptr));
        checkBox_2->setText(QCoreApplication::translate("visualWin", "Qb", nullptr));
        checkBox_3->setText(QCoreApplication::translate("visualWin", "Orbital Position", nullptr));
        checkBox_4->setText(QCoreApplication::translate("visualWin", "Orbital Velocity", nullptr));
        checkBox_5->setText(QCoreApplication::translate("visualWin", "MFS", nullptr));
        checkBox_6->setText(QCoreApplication::translate("visualWin", "Qo", nullptr));
        checkBox_7->setText(QCoreApplication::translate("visualWin", "Angle", nullptr));
        checkBox_8->setText(QCoreApplication::translate("visualWin", "Select All", nullptr));
        label_6->setText(QCoreApplication::translate("visualWin", "<html><head/><body><p>Results</p></body></html>", nullptr));
        ClearUdpClientTextButton->setText(QCoreApplication::translate("visualWin", "Clear Text", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("visualWin", "Angular Velocity", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("visualWin", "Quaternion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("visualWin", "Orbital Position", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("visualWin", "Orbital Velocity", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("visualWin", "Magnetic Field Strength under Orbital Frame", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("visualWin", "Quaternion under Orbital Frame", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("visualWin", "Sun-pointing Angle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class visualWin: public Ui_visualWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALWIN_H
