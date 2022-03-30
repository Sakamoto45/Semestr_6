#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "document.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LeftButton_clicked();

    void on_RighrButton_clicked();

    void on_actionopen_dialog_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    Document *doc;
};
#endif // MAINWINDOW_H
