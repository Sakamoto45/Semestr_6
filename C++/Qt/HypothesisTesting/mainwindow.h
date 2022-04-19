#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "document.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Document *document;
    enum class Displayed {
        None,
        Histogram
    } displayed;
    Dialog *dialog;

    void DrawHistogram(std::vector<double> density);

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_actionSample_triggered();
    void on_actionHistogram_sample_triggered();
};
#endif // MAINWINDOW_H
