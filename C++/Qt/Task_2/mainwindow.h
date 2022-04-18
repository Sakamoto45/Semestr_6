#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include "document.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionH_i_triggered();

    void on_actionChange_triggered();

private:
    Ui::MainWindow *ui;
    Document *document;

protected:
    void paintEvent(QPaintEvent*) override;
};
#endif // MAINWINDOW_H
