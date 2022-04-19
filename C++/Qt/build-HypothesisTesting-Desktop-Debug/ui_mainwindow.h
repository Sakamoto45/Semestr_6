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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSample;
    QAction *actionHistogram_sample;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuGenerate;
    QMenu *menuDisplay;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionSample = new QAction(MainWindow);
        actionSample->setObjectName(QString::fromUtf8("actionSample"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/menu/blank.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSample->setIcon(icon);
        actionHistogram_sample = new QAction(MainWindow);
        actionHistogram_sample->setObjectName(QString::fromUtf8("actionHistogram_sample"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/menu/repeat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistogram_sample->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuGenerate = new QMenu(menubar);
        menuGenerate->setObjectName(QString::fromUtf8("menuGenerate"));
        menuDisplay = new QMenu(menubar);
        menuDisplay->setObjectName(QString::fromUtf8("menuDisplay"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuGenerate->menuAction());
        menubar->addAction(menuDisplay->menuAction());
        menuGenerate->addAction(actionSample);
        menuDisplay->addAction(actionHistogram_sample);
        toolBar->addAction(actionSample);
        toolBar->addAction(actionHistogram_sample);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSample->setText(QCoreApplication::translate("MainWindow", "Sample", nullptr));
        actionHistogram_sample->setText(QCoreApplication::translate("MainWindow", "Histogram (sample)", nullptr));
        menuGenerate->setTitle(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        menuDisplay->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
