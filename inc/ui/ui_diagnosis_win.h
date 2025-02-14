/********************************************************************************
** Form generated from reading UI file 'faultDiagnosis.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTDIAGNOSIS_H
#define UI_FAULTDIAGNOSIS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diagnosisWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *faultTimeDoubleSpin;
    QLabel *label_7;
    QDoubleSpinBox *faultTimeDoubleSpin_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *faultAttDoubleSpin;
    QLabel *label_9;
    QDoubleSpinBox *faultAttDoubleSpin_2;
    QLabel *label_2;
    QComboBox *faultTypeCombo;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *gyroGroupSpin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpinBox *gyroIDSpin;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rateDampRadio;
    QRadioButton *sunPointRadio;
    QRadioButton *starModeRadio;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *cmdInjectButton;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_8;
    QCheckBox *gyroCheckBox;
    QLabel *label_10;
    QCheckBox *starCheckBox;
    QLabel *label_22;
    QCheckBox *sunCheckBox;
    QLabel *label_24;
    QCheckBox *rwCheckBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *saveDataButton;
    QSpacerItem *horizontalSpacer_6;
    QTabWidget *tabWidgetdia;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QChartView *chartView_Algo1;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QChartView *chartView_Algo2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *diagnosisWin)
    {
        if (diagnosisWin->objectName().isEmpty())
            diagnosisWin->setObjectName("diagnosisWin");
        diagnosisWin->resize(1767, 780);
        centralwidget = new QWidget(diagnosisWin);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(291, 16777215));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        faultTimeDoubleSpin = new QDoubleSpinBox(groupBox_2);
        faultTimeDoubleSpin->setObjectName("faultTimeDoubleSpin");
        faultTimeDoubleSpin->setDecimals(3);
        faultTimeDoubleSpin->setMaximum(999999999.000000000000000);
        faultTimeDoubleSpin->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(faultTimeDoubleSpin);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        faultTimeDoubleSpin_2 = new QDoubleSpinBox(groupBox_2);
        faultTimeDoubleSpin_2->setObjectName("faultTimeDoubleSpin_2");
        faultTimeDoubleSpin_2->setDecimals(3);
        faultTimeDoubleSpin_2->setMaximum(999999999.000000000000000);
        faultTimeDoubleSpin_2->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(faultTimeDoubleSpin_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        faultAttDoubleSpin = new QDoubleSpinBox(groupBox_2);
        faultAttDoubleSpin->setObjectName("faultAttDoubleSpin");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(faultAttDoubleSpin->sizePolicy().hasHeightForWidth());
        faultAttDoubleSpin->setSizePolicy(sizePolicy2);
        faultAttDoubleSpin->setDecimals(3);
        faultAttDoubleSpin->setMinimum(-9999.000000000000000);
        faultAttDoubleSpin->setMaximum(9999.000000000000000);
        faultAttDoubleSpin->setValue(0.100000000000000);

        horizontalLayout_6->addWidget(faultAttDoubleSpin);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_9);

        faultAttDoubleSpin_2 = new QDoubleSpinBox(groupBox_2);
        faultAttDoubleSpin_2->setObjectName("faultAttDoubleSpin_2");
        sizePolicy2.setHeightForWidth(faultAttDoubleSpin_2->sizePolicy().hasHeightForWidth());
        faultAttDoubleSpin_2->setSizePolicy(sizePolicy2);
        faultAttDoubleSpin_2->setDecimals(3);
        faultAttDoubleSpin_2->setMinimum(-9999.000000000000000);
        faultAttDoubleSpin_2->setMaximum(9999.000000000000000);
        faultAttDoubleSpin_2->setValue(0.100000000000000);

        horizontalLayout_6->addWidget(faultAttDoubleSpin_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 1);

        gridLayout_3->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        faultTypeCombo = new QComboBox(groupBox_2);
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->addItem(QString());
        faultTypeCombo->setObjectName("faultTypeCombo");

        gridLayout_3->addWidget(faultTypeCombo, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        gyroGroupSpin = new QSpinBox(groupBox_2);
        gyroGroupSpin->setObjectName("gyroGroupSpin");
        gyroGroupSpin->setMinimum(1);

        horizontalLayout->addWidget(gyroGroupSpin);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        gyroIDSpin = new QSpinBox(groupBox_2);
        gyroIDSpin->setObjectName("gyroIDSpin");
        gyroIDSpin->setMinimum(1);

        horizontalLayout_4->addWidget(gyroIDSpin);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_8->addWidget(groupBox_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        rateDampRadio = new QRadioButton(groupBox_3);
        rateDampRadio->setObjectName("rateDampRadio");
        rateDampRadio->setChecked(true);

        verticalLayout_3->addWidget(rateDampRadio);

        sunPointRadio = new QRadioButton(groupBox_3);
        sunPointRadio->setObjectName("sunPointRadio");

        verticalLayout_3->addWidget(sunPointRadio);

        starModeRadio = new QRadioButton(groupBox_3);
        starModeRadio->setObjectName("starModeRadio");

        verticalLayout_3->addWidget(starModeRadio);


        verticalLayout_6->addWidget(groupBox_3);


        verticalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_7 = new QSpacerItem(44, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        cmdInjectButton = new QPushButton(groupBox);
        cmdInjectButton->setObjectName("cmdInjectButton");

        horizontalLayout_8->addWidget(cmdInjectButton);

        horizontalSpacer_8 = new QSpacerItem(44, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);
        horizontalLayout_8->setStretch(2, 1);

        verticalLayout_8->addLayout(horizontalLayout_8);

        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName("groupBox_9");
        verticalLayout_4 = new QVBoxLayout(groupBox_9);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_16 = new QLabel(groupBox_9);
        label_16->setObjectName("label_16");
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        label_17 = new QLabel(groupBox_9);
        label_17->setObjectName("label_17");
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_17, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_9);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        gyroCheckBox = new QCheckBox(groupBox_9);
        gyroCheckBox->setObjectName("gyroCheckBox");
        gyroCheckBox->setLayoutDirection(Qt::LeftToRight);
        gyroCheckBox->setChecked(true);

        gridLayout->addWidget(gyroCheckBox, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_9);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        starCheckBox = new QCheckBox(groupBox_9);
        starCheckBox->setObjectName("starCheckBox");

        gridLayout->addWidget(starCheckBox, 2, 1, 1, 1);

        label_22 = new QLabel(groupBox_9);
        label_22->setObjectName("label_22");
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_22, 3, 0, 1, 1);

        sunCheckBox = new QCheckBox(groupBox_9);
        sunCheckBox->setObjectName("sunCheckBox");

        gridLayout->addWidget(sunCheckBox, 3, 1, 1, 1);

        label_24 = new QLabel(groupBox_9);
        label_24->setObjectName("label_24");
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_24, 4, 0, 1, 1);

        rwCheckBox = new QCheckBox(groupBox_9);
        rwCheckBox->setObjectName("rwCheckBox");

        gridLayout->addWidget(rwCheckBox, 4, 1, 1, 1);

        gridLayout->setRowStretch(0, 5);
        gridLayout->setRowStretch(1, 5);
        gridLayout->setRowStretch(2, 5);
        gridLayout->setRowStretch(3, 5);
        gridLayout->setRowStretch(4, 5);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_5 = new QSpacerItem(44, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        saveDataButton = new QPushButton(groupBox_9);
        saveDataButton->setObjectName("saveDataButton");

        horizontalLayout_7->addWidget(saveDataButton);

        horizontalSpacer_6 = new QSpacerItem(44, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalLayout_4->setStretch(0, 10);

        verticalLayout_8->addWidget(groupBox_9);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        tabWidgetdia = new QTabWidget(centralwidget);
        tabWidgetdia->setObjectName("tabWidgetdia");
        tabWidgetdia->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidgetdia->sizePolicy().hasHeightForWidth());
        tabWidgetdia->setSizePolicy(sizePolicy3);
        tabWidgetdia->setIconSize(QSize(16, 16));
        tabWidgetdia->setUsesScrollButtons(true);
        tabWidgetdia->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        chartView_Algo1 = new QChartView(tab);
        chartView_Algo1->setObjectName("chartView_Algo1");

        verticalLayout->addWidget(chartView_Algo1);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidgetdia->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        chartView_Algo2 = new QChartView(tab_2);
        chartView_Algo2->setObjectName("chartView_Algo2");

        horizontalLayout_3->addWidget(chartView_Algo2);

        tabWidgetdia->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidgetdia, 0, 1, 1, 1);

        diagnosisWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(diagnosisWin);
        statusbar->setObjectName("statusbar");
        diagnosisWin->setStatusBar(statusbar);

        retranslateUi(diagnosisWin);

        tabWidgetdia->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(diagnosisWin);
    } // setupUi

    void retranslateUi(QMainWindow *diagnosisWin)
    {
        diagnosisWin->setWindowTitle(QCoreApplication::translate("diagnosisWin", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QCoreApplication::translate("diagnosisWin", "Fault Injection", nullptr));
        label->setText(QCoreApplication::translate("diagnosisWin", "Time(s)", nullptr));
        label_7->setText(QCoreApplication::translate("diagnosisWin", "~", nullptr));
        label_3->setText(QCoreApplication::translate("diagnosisWin", "Attitude", nullptr));
        label_9->setText(QCoreApplication::translate("diagnosisWin", "~", nullptr));
        label_2->setText(QCoreApplication::translate("diagnosisWin", "Type", nullptr));
        faultTypeCombo->setItemText(0, QCoreApplication::translate("diagnosisWin", "Gyro-Abrupt Fault", nullptr));
        faultTypeCombo->setItemText(1, QCoreApplication::translate("diagnosisWin", "Gyro-Slow Fault", nullptr));
        faultTypeCombo->setItemText(2, QCoreApplication::translate("diagnosisWin", "Gyro-Constant Fault", nullptr));
        faultTypeCombo->setItemText(3, QCoreApplication::translate("diagnosisWin", "\346\230\237\346\225\217\346\204\237\345\231\250\346\201\222\345\200\274\346\225\205\351\232\234", nullptr));
        faultTypeCombo->setItemText(4, QCoreApplication::translate("diagnosisWin", "\346\230\237\346\225\217\346\204\237\345\231\250\351\227\264\346\255\207\346\225\205\351\232\234", nullptr));
        faultTypeCombo->setItemText(5, QCoreApplication::translate("diagnosisWin", "\345\244\252\351\230\263\346\225\217\346\204\237\345\231\250\346\201\222\345\200\274\346\225\205\351\232\234", nullptr));
        faultTypeCombo->setItemText(6, QCoreApplication::translate("diagnosisWin", "\345\244\252\351\230\263\346\225\217\346\204\237\345\231\250\351\227\264\346\255\207\346\225\205\351\232\234", nullptr));
        faultTypeCombo->setItemText(7, QCoreApplication::translate("diagnosisWin", "\346\227\240\346\225\205\351\232\234", nullptr));

        label_4->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p align=\"center\">Gyroscope ID</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Group</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Gyro ID</p></body></html>", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("diagnosisWin", "Run Mode", nullptr));
        rateDampRadio->setText(QCoreApplication::translate("diagnosisWin", "Initial Rate Damping", nullptr));
        sunPointRadio->setText(QCoreApplication::translate("diagnosisWin", "Sun-pointing", nullptr));
        starModeRadio->setText(QCoreApplication::translate("diagnosisWin", "Staring Mdoe", nullptr));
        cmdInjectButton->setText(QCoreApplication::translate("diagnosisWin", "Command Inject", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("diagnosisWin", "Data ", nullptr));
        label_16->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Data Type</p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Save</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Gyroscope</p></body></html>", nullptr));
        gyroCheckBox->setText(QString());
        label_10->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Star Sensor</p></body></html>", nullptr));
        starCheckBox->setText(QString());
        label_22->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Sun Sensor</p></body></html>", nullptr));
        sunCheckBox->setText(QString());
        label_24->setText(QCoreApplication::translate("diagnosisWin", "<html><head/><body><p>Reaction Wheel</p></body></html>", nullptr));
        rwCheckBox->setText(QString());
        saveDataButton->setText(QCoreApplication::translate("diagnosisWin", "Save Button", nullptr));
        tabWidgetdia->setTabText(tabWidgetdia->indexOf(tab), QCoreApplication::translate("diagnosisWin", "Algorithm-1", nullptr));
        tabWidgetdia->setTabText(tabWidgetdia->indexOf(tab_2), QCoreApplication::translate("diagnosisWin", "Algorithm-2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diagnosisWin: public Ui_diagnosisWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTDIAGNOSIS_H
