#pragma once
#include <QDialog>

namespace Ui {
class GenerateSample;
}

class GenerateSample : public QDialog
{
    Q_OBJECT

public:
    double realProb = 0.2;
    int sizeOfGeomSample = 100;
    std::string method = "bernoulli";
    bool isOK = false;


    explicit GenerateSample(QWidget *parent = nullptr);
    ~GenerateSample();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::GenerateSample *ui;
};
