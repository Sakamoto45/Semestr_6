#pragma once
#include <QMainWindow>
#include "generatesample.h"
#include "pvalues.h"
#include "about.h"
#include "math.h"


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
    void on_actionGenerate_sample_triggered();

    void on_actionP_values_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};
