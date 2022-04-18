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
    QAction *actionH_i;
    QAction *actionChange;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuH_i;
    QMenu *menuDraw;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionH_i = new QAction(MainWindow);
        actionH_i->setObjectName(QString::fromUtf8("actionH_i"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/hi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionH_i->setIcon(icon);
        actionChange = new QAction(MainWindow);
        actionChange->setObjectName(QString::fromUtf8("actionChange"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChange->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuH_i = new QMenu(menubar);
        menuH_i->setObjectName(QString::fromUtf8("menuH_i"));
        menuDraw = new QMenu(menubar);
        menuDraw->setObjectName(QString::fromUtf8("menuDraw"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuDraw->menuAction());
        menubar->addAction(menuH_i->menuAction());
        menuH_i->addAction(actionH_i);
        menuDraw->addAction(actionChange);
        toolBar->addAction(actionH_i);
        toolBar->addAction(actionChange);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionH_i->setText(QCoreApplication::translate("MainWindow", "H&i", nullptr));
#if QT_CONFIG(tooltip)
        actionH_i->setToolTip(QCoreApplication::translate("MainWindow", "Say hi", nullptr));
#endif // QT_CONFIG(tooltip)
        actionChange->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
#if QT_CONFIG(tooltip)
        actionChange->setToolTip(QCoreApplication::translate("MainWindow", "move \"Hello\"", nullptr));
#endif // QT_CONFIG(tooltip)
        menuH_i->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuDraw->setTitle(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
