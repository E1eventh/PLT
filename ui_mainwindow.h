/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(841, 440);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 271, 371));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 131, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 141, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 111, 16));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 100, 141, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 111, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 180, 191, 16));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(10, 210, 141, 17));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 240, 131, 17));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 150, 69, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 340, 91, 23));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(30, 300, 69, 22));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(170, 300, 69, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 270, 111, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(140, 270, 121, 16));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(300, 30, 211, 321));
        textEdit->setUndoRedoEnabled(true);
        textEdit->setAcceptRichText(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 10, 131, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 10, 131, 16));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(530, 30, 301, 321));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(800, 360, 31, 23));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(530, 360, 171, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 360, 31, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(300, 360, 171, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\260\320\273\321\204\320\260\320\262\320\270\321\202:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\320\264\321\206\320\265\320\277\320\276\321\207\320\272\321\203:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\270\321\200\320\265\321\202\320\265 \320\272\321\200\320\260\321\202\320\275\320\276\321\201\321\202\321\214: ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\270\321\200\320\265\321\202\320\265 \321\200\320\265\320\263\321\203\320\273\321\217\321\200\320\275\321\203\321\216 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\321\203:", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\320\276\320\273\320\270\320\275\320\265\320\271\320\275\320\260\321\217", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\276\320\273\320\270\320\275\320\265\320\271\320\275\320\260\321\217", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        comboBox->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));
        comboBox->setItemText(10, QApplication::translate("MainWindow", "10", nullptr));

        pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("MainWindow", "5", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("MainWindow", "6", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("MainWindow", "7", nullptr));
        comboBox_2->setItemText(7, QApplication::translate("MainWindow", "8", nullptr));
        comboBox_2->setItemText(8, QApplication::translate("MainWindow", "9", nullptr));
        comboBox_2->setItemText(9, QApplication::translate("MainWindow", "10", nullptr));

        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        comboBox_3->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));
        comboBox_3->setItemText(4, QApplication::translate("MainWindow", "5", nullptr));
        comboBox_3->setItemText(5, QApplication::translate("MainWindow", "6", nullptr));
        comboBox_3->setItemText(6, QApplication::translate("MainWindow", "7", nullptr));
        comboBox_3->setItemText(7, QApplication::translate("MainWindow", "8", nullptr));
        comboBox_3->setItemText(8, QApplication::translate("MainWindow", "9", nullptr));
        comboBox_3->setItemText(9, QApplication::translate("MainWindow", "10", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\275\320\260", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\275\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\277\320\276\321\207\320\272\320\270:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\262 \321\204\320\260\320\271\320\273: ", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
