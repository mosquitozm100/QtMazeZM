/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *show_maze;
    QPushButton *generate_maze;
    QPushButton *generate_answer1;
    QPushButton *generate_answer2;
    QLineEdit *row_input;
    QLineEdit *col_input;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *time1;
    QLineEdit *time2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1064, 676);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        show_maze = new QGraphicsView(centralWidget);
        show_maze->setObjectName(QStringLiteral("show_maze"));
        show_maze->setGeometry(QRect(450, 30, 600, 600));
        generate_maze = new QPushButton(centralWidget);
        generate_maze->setObjectName(QStringLiteral("generate_maze"));
        generate_maze->setGeometry(QRect(90, 160, 93, 28));
        generate_answer1 = new QPushButton(centralWidget);
        generate_answer1->setObjectName(QStringLiteral("generate_answer1"));
        generate_answer1->setGeometry(QRect(90, 220, 93, 28));
        generate_answer2 = new QPushButton(centralWidget);
        generate_answer2->setObjectName(QStringLiteral("generate_answer2"));
        generate_answer2->setGeometry(QRect(280, 220, 93, 28));
        row_input = new QLineEdit(centralWidget);
        row_input->setObjectName(QStringLiteral("row_input"));
        row_input->setGeometry(QRect(90, 90, 111, 22));
        col_input = new QLineEdit(centralWidget);
        col_input->setObjectName(QStringLiteral("col_input"));
        col_input->setGeometry(QRect(90, 120, 111, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 41, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 41, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 120, 111, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 90, 111, 21));
        time1 = new QLineEdit(centralWidget);
        time1->setObjectName(QStringLiteral("time1"));
        time1->setGeometry(QRect(90, 270, 71, 22));
        time2 = new QLineEdit(centralWidget);
        time2->setObjectName(QStringLiteral("time2"));
        time2->setGeometry(QRect(280, 270, 71, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 270, 41, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 270, 41, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 270, 41, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(360, 270, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1064, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        generate_maze->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\350\277\267\345\256\253", Q_NULLPTR));
        generate_answer1->setText(QApplication::translate("MainWindow", "\346\261\202\350\247\243\357\274\210DFS\357\274\211", Q_NULLPTR));
        generate_answer2->setText(QApplication::translate("MainWindow", "\346\261\202\350\247\243\357\274\210BFS\357\274\211", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\241\214\346\225\260</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\210\227\346\225\260</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\357\274\210\350\257\267\350\276\223\345\205\245\345\245\207\346\225\260\357\274\211</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\357\274\210\350\257\267\350\276\223\345\205\245\345\245\207\346\225\260\357\274\211</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\346\227\266\351\227\264</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\346\227\266\351\227\264</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">ms</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">ms</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
