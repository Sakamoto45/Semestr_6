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

//void MainWindow::DrawHistogram(std::vector<int> frequency)
//{
//    QPainter painter;
//    painter.begin(this);

//    if (frequency.size() == 0) {
//        return ;
//    }
//    int x_0 = 100;
//    int y_0 = height() - 100;
//    double scale_x = width() - 200;
//    double scale_y = -(height() - 280);

//    double x_min = 0;
//    double x_max = frequency.size();
//    double y_min = 0;
//    double y_max = *max_element(frequency.begin(), frequency.end()) / 0.8;

// //    painter.drawText(x_0+scale_x, y_0, QString::number(x_max));
// //    painter.drawText(x_0, y_0+scale_y, QString::number(y_max));

//    for (double i = 0; i < y_max; i += 10) {
//        painter.drawText(x_0+3, y_0+i/y_max*scale_y, QString::number(i));
//    }

//    painter.drawRect(x_0, y_0, 1*scale_x, 1*scale_y);
//    int n = (int)frequency.size();
//    for (int i = 0; i < n; ++i) {
//        painter.drawRect(x_0 + (double)i/n*scale_x, y_0, 1.0/n*scale_x, frequency[i]/y_max*scale_y);
//        if (i % 5 == 0) {
//            painter.drawText(x_0+(double)i/n*scale_x, y_0+12, QString::number(i));
//        }
//    }

//    painter.end();
//}

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
    if (dialog->show_part(false, true, false)) {
        displayed = Displayed::SampleHistogram;
        document->GenerateSampleHistogram();
        repaint();
    }
}

void MainWindow::on_action_p_value_dialog_triggered()
{
    if (dialog->show_part(true, true, true)) {
        displayed = Displayed::PvalueDistribution;
        document->GenerateSampleHistogram();
        repaint();
    }
}


void MainWindow::on_action_power_triggered()
{

}


void MainWindow::on_action_refresh_last_triggered()
{
    switch (displayed) {
    case Displayed::SampleHistogram:
        document->GenerateSampleHistogram();
        repaint();
        break;
    default:
        break;
    }
}

