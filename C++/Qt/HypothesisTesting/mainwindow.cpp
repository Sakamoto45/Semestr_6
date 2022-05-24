#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , document(new Document)
    , displayed(Displayed::None)
    , dialog(new Dialog(document, this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete document;
}

void MainWindow::DrawSampleHistogram(std::vector<int> emperical_frequency,
                                     std::vector<double> theoretical_frequency)
{
    QPainter painter;
    QBrush brush;
    QPen pen;
    painter.begin(this);

    int x_0 = 50;
    int y_0 = height() - 50;
    double x_scale = width() - 100;
    double y_scale = -(height() - 180);

    QString text =
            QString::fromStdString(document->get_distribution_name()) +
            " with p = " +
            QString::number(document->get_p1()) +
            " k = " +
            QString::number(document->get_k1()) +
            " sample size = " +
            QString::number(document->get_sample_size()) +
            " test statistica = " +
            QString::number(document->get_test_stat()) +
            " degree of freedom = " +
            QString::number(document->get_degree_of_freedom()) +
            " p-value = " +
            QString::number(document->get_p_value());
    painter.drawText(50, 125, text);

    painter.drawRect(x_0, y_0, 1*x_scale, 1*y_scale);

    double x_max = emperical_frequency.size();
    int emperical_max = *max_element(emperical_frequency.begin(),
                                     emperical_frequency.end());
    double theoretical_max = *max_element(theoretical_frequency.begin(),
                                          theoretical_frequency.end());
    double y_max = std::max((double) emperical_max,
                            theoretical_max) / 0.9;
    int n = theoretical_frequency.size();


    painter.drawText(x_0 + 0.5 / n * x_scale, y_0 + 12, "0");
    painter.drawText(x_0 - 12, y_0, "0");
    painter.drawText(x_0 + (1 - 0.5 / n) * x_scale, y_0 + 12, QString::number(x_max));
    painter.drawText(x_0 - 20, y_0 + emperical_max / y_max * y_scale, QString::number(emperical_max));
    painter.drawText(x_0 - 20, y_0 + theoretical_max / y_max * y_scale, QString::number((int)theoretical_max));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    pen.setColor(Qt::red);
    painter.setBrush(brush);
    painter.setPen(pen);

    for (int i = 0; i < n; ++i) {
        painter.drawRect(x_0 + (double)i / n * x_scale, y_0,
                         1.0 / n * x_scale, theoretical_frequency[i] / y_max * y_scale);
    }
    brush.setColor(Qt::green);
    pen.setColor(Qt::green);
    painter.setBrush(brush);
    painter.setPen(pen);
    for (int i = 0; i < n; ++i) {
        painter.drawRect(x_0 + (i + 0.2) / n * x_scale, y_0,
                         0.6 / n * x_scale, emperical_frequency[i] / y_max * y_scale);

    }

    painter.end();
}

void MainWindow::DrawPvalueDistribution()
{
    QPainter painter;
    QPen pen;
    painter.begin(this);

    int x_0 = 50;
    int y_0 = height() - 50;
    double x_scale = width() - 100;
    double y_scale = -(height() - 180);

    QString text =
            "P-value distribution with p0 = " +
            QString::number(document->get_p0()) +
            " k0 = " +
            QString::number(document->get_k0()) +
            " p1 = " +
            QString::number(document->get_p1()) +
            " k1 = " +
            QString::number(document->get_k1()) +
            " sample size = " +
            QString::number(document->get_sample_size()) +
            " p sample size = " +
            QString::number(document->get_p_sample_size());
    painter.drawText(50, 125, text);

    painter.drawRect(x_0, y_0, 1*x_scale, 1*y_scale);
    painter.drawLine(x_0, y_0, x_0 + x_scale, y_0 + y_scale);

    painter.drawText(x_0 + 12, y_0 + 12, "0");
    painter.drawText(x_0 - 12, y_0, "0");
    painter.drawText(x_0 + x_scale, y_0 + 12, "1");
    painter.drawText(x_0 - 12, y_0 + y_scale, "1");

    pen.setColor(Qt::red);
    painter.setPen(pen);

    std::vector<double> distribution = document->get_p_distribution();


    for (int i = 0; i < 100; ++i) {
        painter.drawLine(x_0 + 0.01 * i * x_scale,
                         y_0 + distribution[i] * y_scale,
                         x_0 + 0.01 * (i + 1) * x_scale,
                         y_0 + distribution[i + 1] * y_scale);
    }

    painter.end();
}

void MainWindow::DrawPowerRelation()
{
    QPainter painter;
    QPen pen;
    painter.begin(this);

    int x_0 = 50;
    int y_0 = height() - 50;
    double x_scale = width() - 100;
    double y_scale = -(height() - 180);

    QString text =
            "Power relation to sample size with p0 " +
            QString::number(document->get_p0()) +
            " k0 = " +
            QString::number(document->get_k0()) +
            " p1 = " +
            QString::number(document->get_p1()) +
            " k1 = " +
            QString::number(document->get_k1()) +
            " significance level = " +
            QString::number(document->get_significance_level());
    painter.drawText(50, 125, text);

    painter.drawRect(x_0, y_0, 1*x_scale, 1*y_scale);

    painter.drawText(x_0 + 0.1 * x_scale, y_0 + 12, "100");
    painter.drawText(x_0 - 12, y_0, "0");
    painter.drawText(x_0 + x_scale, y_0 + 12, "1000");
    painter.drawText(x_0 - 12, y_0 + y_scale, "1");

    pen.setColor(Qt::red);
    painter.setPen(pen);

    const std::vector<double>& power = document->get_power_relation();


    for (int i = 1; i < 10; ++i) {
        painter.drawLine(x_0 + 0.1 * i * x_scale,
                         y_0 + power[i - 1] * y_scale,
                         x_0 + 0.1 * (i + 1) * x_scale,
                         y_0 + power[i] * y_scale);
    }

    painter.end();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    switch (displayed) {
    case Displayed::SampleHistogram:
        DrawSampleHistogram(document->get_emperical_frequency(),
                            document->get_theoretical_frequency());
        break;
    case Displayed::PvalueDistribution:
        DrawPvalueDistribution();
        break;
    case Displayed::PowerRelation:
        DrawPowerRelation();
        break;
    default:
        break;
    }

}

void MainWindow::on_action_sample_gialog_triggered()
{
    if (dialog->show_part(false, true, false, false)) {
        displayed = Displayed::SampleHistogram;
        document->GenerateSampleHistogram();
        repaint();
    }
}

void MainWindow::on_action_p_value_dialog_triggered()
{
    if (dialog->show_part(true, true, true, false)) {
        displayed = Displayed::PvalueDistribution;
        document->GeneratePvalueDistribution();
        repaint();
    }
}


void MainWindow::on_action_power_triggered()
{
    if (dialog->show_part(true, true, false, true)) {
        displayed = Displayed::PowerRelation;
        document->GeneratePowerRelation();
        repaint();
    }
}


void MainWindow::on_action_refresh_last_triggered()
{
    switch (displayed) {
    case Displayed::SampleHistogram:
        document->GenerateSampleHistogram();
        break;
    case Displayed::PvalueDistribution:
        document->GeneratePvalueDistribution();
        break;
    case Displayed::PowerRelation:
        document->GeneratePowerRelation();
        break;
    default:
        break;
    }
    repaint();
}

