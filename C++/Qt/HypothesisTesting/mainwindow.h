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
        SampleHistogram,
        PvalueDistribution,
        PowerRelation
    } displayed;
    Dialog *dialog;

    void DrawSampleHistogram(std::vector<int> emperical_frequency,
                             std::vector<double> theoretical_frequency);
    void DrawPvalueDistribution();
    void DrawPowerRelation();

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_action_sample_gialog_triggered();
    void on_action_p_value_dialog_triggered();
    void on_action_power_triggered();
    void on_action_refresh_last_triggered();
};
#endif // MAINWINDOW_H
