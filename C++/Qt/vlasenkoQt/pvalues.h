#ifndef PVALUES_H
#define PVALUES_H

#include <QDialog>

namespace Ui {
class PValues;
}

class PValues : public QDialog
{
    Q_OBJECT

public:
    double realProb = 0.2, hypotheticalProb = 0.2;
    int sizeOfGeomSample = 100, sizeOfPValueSample = 500;
    std::string method = "bernoulli";
    bool isOK = false;

    explicit PValues(QWidget *parent = nullptr);
    ~PValues();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::PValues *ui;
};

#endif // PVALUES_H
