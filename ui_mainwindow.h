/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *drawButton;
    QPushButton *Btn1;
    QPushButton *Btn2;
    QRadioButton *speed1;
    QRadioButton *speed2;
    QRadioButton *speed3;
    QLabel *label_3;
    QRadioButton *number3;
    QRadioButton *number1;
    QLabel *label_6;
    QRadioButton *number2;
    QPushButton *clear;
    QLabel *label;
    QRadioButton *display;
    QRadioButton *hidden;
    QPushButton *close;
    QPushButton *loadArm;
    QLabel *armLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawButton = new QPushButton(centralWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(20, 310, 111, 23));
        Btn1 = new QPushButton(centralWidget);
        Btn1->setObjectName(QStringLiteral("Btn1"));
        Btn1->setGeometry(QRect(490, 310, 101, 23));
        Btn2 = new QPushButton(centralWidget);
        Btn2->setObjectName(QStringLiteral("Btn2"));
        Btn2->setGeometry(QRect(490, 340, 101, 23));
        speed1 = new QRadioButton(centralWidget);
        speed1->setObjectName(QStringLiteral("speed1"));
        speed1->setGeometry(QRect(180, 330, 89, 16));
        speed2 = new QRadioButton(centralWidget);
        speed2->setObjectName(QStringLiteral("speed2"));
        speed2->setGeometry(QRect(180, 350, 89, 16));
        speed3 = new QRadioButton(centralWidget);
        speed3->setObjectName(QStringLiteral("speed3"));
        speed3->setGeometry(QRect(180, 370, 89, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 310, 54, 12));
        number3 = new QRadioButton(centralWidget);
        number3->setObjectName(QStringLiteral("number3"));
        number3->setGeometry(QRect(280, 370, 89, 16));
        number1 = new QRadioButton(centralWidget);
        number1->setObjectName(QStringLiteral("number1"));
        number1->setGeometry(QRect(280, 330, 89, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 310, 54, 12));
        number2 = new QRadioButton(centralWidget);
        number2->setObjectName(QStringLiteral("number2"));
        number2->setGeometry(QRect(280, 350, 89, 16));
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(20, 370, 111, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 310, 54, 12));
        display = new QRadioButton(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(380, 330, 89, 16));
        hidden = new QRadioButton(centralWidget);
        hidden->setObjectName(QStringLiteral("hidden"));
        hidden->setGeometry(QRect(380, 350, 89, 16));
        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(20, 340, 111, 23));
        loadArm = new QPushButton(centralWidget);
        loadArm->setObjectName(QStringLiteral("loadArm"));
        loadArm->setGeometry(QRect(370, 370, 75, 23));
        armLabel = new QLabel(centralWidget);
        armLabel->setObjectName(QStringLiteral("armLabel"));
        armLabel->setGeometry(QRect(160, 20, 321, 191));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        drawButton->setText(QApplication::translate("MainWindow", "\347\273\230\345\210\266\345\210\235\345\247\213\345\275\242\347\212\266", 0));
        Btn1->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\346\217\222\345\200\274", 0));
        Btn2->setText(QApplication::translate("MainWindow", "\347\237\242\351\207\217\347\272\277\346\200\247\346\217\222\345\200\274", 0));
        speed1->setText(QApplication::translate("MainWindow", "\345\277\253", 0));
        speed2->setText(QApplication::translate("MainWindow", "\344\270\255", 0));
        speed3->setText(QApplication::translate("MainWindow", "\346\205\242", 0));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246", 0));
        number3->setText(QApplication::translate("MainWindow", "\345\260\221", 0));
        number1->setText(QApplication::translate("MainWindow", "\345\244\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\217\222\345\200\274\346\225\260\351\207\217", 0));
        number2->setText(QApplication::translate("MainWindow", "\344\270\200\350\210\254", 0));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
        label->setText(QApplication::translate("MainWindow", "\346\217\222\345\200\274\345\233\276\345\275\242", 0));
        display->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", 0));
        hidden->setText(QApplication::translate("MainWindow", "\344\270\215\346\230\276\347\244\272", 0));
        close->setText(QApplication::translate("MainWindow", "\351\227\255\345\220\210\345\233\276\345\275\242", 0));
        loadArm->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\345\233\276\347\211\207", 0));
        armLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
