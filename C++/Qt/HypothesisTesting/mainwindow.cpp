#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , document(new Document)
    , dialog(new Dialog(this))
{
    ui->setupUi(this);
    document->setup();
    displayed = Displayed::None;
    dialog->setup(document);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete document;
}

void MainWindow::DrawHistogram(std::vector<double> density)
{
    QPainter painter;
    painter.begin(this);

    double x_min = 0;
    double x_max = density.size();
    double y_min = 0;
    double y_max = *max_element(density.begin(), density.end()) / 0.8;

    int x_0 = 100;
    int y_0 = height() - 100;
    double scale_x = width() - 200;
    double scale_y = -(height() - 280);


//    painter.drawText(x_0+scale_x, y_0, QString::number(x_max));
//    painter.drawText(x_0, y_0+scale_y, QString::number(y_max));

    for (double i = 0; i < y_max; i += 0.01) {
        painter.drawText(x_0+3, y_0+i/y_max*scale_y, QString::number(i));
    }

    painter.drawRect(x_0, y_0, 1*scale_x, 1*scale_y);
    int n = (int)density.size();
    for (int i = 0; i < n; ++i) {
        painter.drawRect(x_0 + (double)i/n*scale_x, y_0, 1.0/n*scale_x, density[i]/y_max*scale_y);
        if (i % 5 == 0) {
            painter.drawText(x_0+(double)i/n*scale_x, y_0+12, QString::number(i));
        }
    }




//    int i = document->getI();

//    painter.drawText(i, i, "Hello");

    painter.end();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    switch (displayed) {
    case Displayed::Histogram:
        DrawHistogram(document->emperical_density);
        break;
    default:
        break;
    }

}


void MainWindow::on_actionSample_triggered()
{
    dialog->show();
}


void MainWindow::on_actionHistogram_sample_triggered()
{
    document->generateEmpericalDencity();
    displayed = Displayed::Histogram;
    repaint();
}

