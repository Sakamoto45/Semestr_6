/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGenerate_sample;
    QAction *actionP_values;
    QAction *actionPower;
    QAction *actionTime;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuGenerate_sample;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        actionGenerate_sample = new QAction(MainWindow);
        actionGenerate_sample->setObjectName(QString::fromUtf8("actionGenerate_sample"));
        actionP_values = new QAction(MainWindow);
        actionP_values->setObjectName(QString::fromUtf8("actionP_values"));
        actionPower = new QAction(MainWindow);
        actionPower->setObjectName(QString::fromUtf8("actionPower"));
        actionTime = new QAction(MainWindow);
        actionTime->setObjectName(QString::fromUtf8("actionTime"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menuGenerate_sample = new QMenu(menubar);
        menuGenerate_sample->setObjectName(QString::fromUtf8("menuGenerate_sample"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuGenerate_sample->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGenerate_sample->addAction(actionGenerate_sample);
        menuGenerate_sample->addAction(actionP_values);
        menuGenerate_sample->addAction(actionPower);
        menuGenerate_sample->addAction(actionTime);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGenerate_sample->setText(QCoreApplication::translate("MainWindow", "Generate sample", nullptr));
        actionP_values->setText(QCoreApplication::translate("MainWindow", "P-values", nullptr));
        actionPower->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        actionTime->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuGenerate_sample->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
