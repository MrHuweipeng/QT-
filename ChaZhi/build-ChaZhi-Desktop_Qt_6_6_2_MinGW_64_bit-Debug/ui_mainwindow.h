/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QChartView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_oneX1;
    QLabel *label_2;
    QLineEdit *lineEdit_oneY1;
    QLabel *label_4;
    QLineEdit *lineEdit_oneX2;
    QLabel *label_3;
    QLineEdit *lineEdit_oneY2;
    QPushButton *pushButton_oneOK;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLineEdit *lineEdit_twoX1;
    QLabel *label_7;
    QLineEdit *lineEdit_twoY1;
    QLabel *label_5;
    QLineEdit *lineEdit_twoX2;
    QLabel *label_6;
    QLineEdit *lineEdit_twoY2;
    QLabel *label_9;
    QLineEdit *lineEdit_twoX3;
    QLabel *label_10;
    QLineEdit *lineEdit_twoY3;
    QPushButton *pushButton_twoOK;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLineEdit *lineEdit_threeX1;
    QLabel *label_12;
    QLineEdit *lineEdit_threeY1;
    QLabel *label_13;
    QLineEdit *lineEdit_threeX2;
    QLabel *label_14;
    QLineEdit *lineEdit_threeY2;
    QLabel *label_15;
    QLineEdit *lineEdit_threeX3;
    QLabel *label_16;
    QLineEdit *lineEdit_threeY3;
    QLabel *label_18;
    QLineEdit *lineEdit_threeX4;
    QLabel *label_17;
    QLineEdit *lineEdit_threeY4;
    QPushButton *pushButton_threeOK;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_result221;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QChartView *graphicsView_651;
    QWidget *tab_3;
    QGridLayout *gridLayout_8;
    QChartView *graphicsView_robot;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QChartView *graphicsView_RungeKutta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1424, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName("gridLayout_5");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        graphicsView = new QChartView(tab);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 30, 1001, 851));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(1020, 30, 91, 182));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_oneX1 = new QLineEdit(groupBox);
        lineEdit_oneX1->setObjectName("lineEdit_oneX1");

        gridLayout->addWidget(lineEdit_oneX1, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_oneY1 = new QLineEdit(groupBox);
        lineEdit_oneY1->setObjectName("lineEdit_oneY1");

        gridLayout->addWidget(lineEdit_oneY1, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_oneX2 = new QLineEdit(groupBox);
        lineEdit_oneX2->setObjectName("lineEdit_oneX2");

        gridLayout->addWidget(lineEdit_oneX2, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_oneY2 = new QLineEdit(groupBox);
        lineEdit_oneY2->setObjectName("lineEdit_oneY2");

        gridLayout->addWidget(lineEdit_oneY2, 3, 1, 1, 1);

        pushButton_oneOK = new QPushButton(groupBox);
        pushButton_oneOK->setObjectName("pushButton_oneOK");

        gridLayout->addWidget(pushButton_oneOK, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(1030, 240, 91, 240));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_twoX1 = new QLineEdit(groupBox_2);
        lineEdit_twoX1->setObjectName("lineEdit_twoX1");

        gridLayout_2->addWidget(lineEdit_twoX1, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_twoY1 = new QLineEdit(groupBox_2);
        lineEdit_twoY1->setObjectName("lineEdit_twoY1");

        gridLayout_2->addWidget(lineEdit_twoY1, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_twoX2 = new QLineEdit(groupBox_2);
        lineEdit_twoX2->setObjectName("lineEdit_twoX2");

        gridLayout_2->addWidget(lineEdit_twoX2, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_twoY2 = new QLineEdit(groupBox_2);
        lineEdit_twoY2->setObjectName("lineEdit_twoY2");

        gridLayout_2->addWidget(lineEdit_twoY2, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 4, 0, 1, 1);

        lineEdit_twoX3 = new QLineEdit(groupBox_2);
        lineEdit_twoX3->setObjectName("lineEdit_twoX3");

        gridLayout_2->addWidget(lineEdit_twoX3, 4, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        lineEdit_twoY3 = new QLineEdit(groupBox_2);
        lineEdit_twoY3->setObjectName("lineEdit_twoY3");

        gridLayout_2->addWidget(lineEdit_twoY3, 5, 1, 1, 1);

        pushButton_twoOK = new QPushButton(groupBox_2);
        pushButton_twoOK->setObjectName("pushButton_twoOK");

        gridLayout_2->addWidget(pushButton_twoOK, 6, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(1170, 20, 111, 298));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        lineEdit_threeX1 = new QLineEdit(groupBox_3);
        lineEdit_threeX1->setObjectName("lineEdit_threeX1");

        gridLayout_3->addWidget(lineEdit_threeX1, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        lineEdit_threeY1 = new QLineEdit(groupBox_3);
        lineEdit_threeY1->setObjectName("lineEdit_threeY1");

        gridLayout_3->addWidget(lineEdit_threeY1, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        lineEdit_threeX2 = new QLineEdit(groupBox_3);
        lineEdit_threeX2->setObjectName("lineEdit_threeX2");

        gridLayout_3->addWidget(lineEdit_threeX2, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");

        gridLayout_3->addWidget(label_14, 3, 0, 1, 1);

        lineEdit_threeY2 = new QLineEdit(groupBox_3);
        lineEdit_threeY2->setObjectName("lineEdit_threeY2");

        gridLayout_3->addWidget(lineEdit_threeY2, 3, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");

        gridLayout_3->addWidget(label_15, 4, 0, 1, 1);

        lineEdit_threeX3 = new QLineEdit(groupBox_3);
        lineEdit_threeX3->setObjectName("lineEdit_threeX3");

        gridLayout_3->addWidget(lineEdit_threeX3, 4, 1, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");

        gridLayout_3->addWidget(label_16, 5, 0, 1, 1);

        lineEdit_threeY3 = new QLineEdit(groupBox_3);
        lineEdit_threeY3->setObjectName("lineEdit_threeY3");

        gridLayout_3->addWidget(lineEdit_threeY3, 5, 1, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");

        gridLayout_3->addWidget(label_18, 6, 0, 1, 1);

        lineEdit_threeX4 = new QLineEdit(groupBox_3);
        lineEdit_threeX4->setObjectName("lineEdit_threeX4");

        gridLayout_3->addWidget(lineEdit_threeX4, 6, 1, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");

        gridLayout_3->addWidget(label_17, 7, 0, 1, 1);

        lineEdit_threeY4 = new QLineEdit(groupBox_3);
        lineEdit_threeY4->setObjectName("lineEdit_threeY4");

        gridLayout_3->addWidget(lineEdit_threeY4, 7, 1, 1, 1);

        pushButton_threeOK = new QPushButton(groupBox_3);
        pushButton_threeOK->setObjectName("pushButton_threeOK");

        gridLayout_3->addWidget(pushButton_threeOK, 8, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1150, 570, 132, 65));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName("gridLayout_4");
        lineEdit_result221 = new QLineEdit(groupBox_4);
        lineEdit_result221->setObjectName("lineEdit_result221");

        gridLayout_4->addWidget(lineEdit_result221, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setObjectName("gridLayout_6");
        graphicsView_651 = new QChartView(tab_2);
        graphicsView_651->setObjectName("graphicsView_651");

        gridLayout_6->addWidget(graphicsView_651, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_8 = new QGridLayout(tab_3);
        gridLayout_8->setObjectName("gridLayout_8");
        graphicsView_robot = new QChartView(tab_3);
        graphicsView_robot->setObjectName("graphicsView_robot");

        gridLayout_8->addWidget(graphicsView_robot, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setObjectName("gridLayout_7");
        graphicsView_RungeKutta = new QChartView(tab_4);
        graphicsView_RungeKutta->setObjectName("graphicsView_RungeKutta");

        gridLayout_7->addWidget(graphicsView_RungeKutta, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_5->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1424, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\200\346\254\241\346\233\262\347\272\277", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x2:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "y2:", nullptr));
        pushButton_oneOK->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\272\214\346\254\241\346\233\262\347\272\277", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "x2:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "y2:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "x3:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "y3:", nullptr));
        pushButton_twoOK->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\344\270\211\346\254\241\346\233\262\347\272\277", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "x1:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "y1:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "x2:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "y2:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "x3:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "y3:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "x4:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "y4:", nullptr));
        pushButton_threeOK->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\344\276\2132.2.1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\346\254\241\350\257\276\357\274\210\346\217\222\345\200\274\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\346\254\241\350\257\276\357\274\210\346\213\237\345\220\210\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\347\254\254\344\270\211\346\254\241\350\257\276\357\274\210\346\225\260\345\200\274\347\247\257\345\210\206\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\347\254\254\345\233\233\346\254\241\350\257\276\357\274\210Runge-Kutta\346\263\225\350\247\243\345\276\256\345\210\206\346\226\271\347\250\213\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
