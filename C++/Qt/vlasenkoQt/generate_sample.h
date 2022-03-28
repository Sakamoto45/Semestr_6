#ifndef GENERATE_SAMPLE_H
#define GENERATE_SAMPLE_H

#include <QDialog>

namespace Ui {
class Generate_sample;
}

class Generate_sample : public QDialog
{
    Q_OBJECT

public:
    explicit Generate_sample(QWidget *parent = nullptr);
    ~Generate_sample();

private:
    Ui::Generate_sample *ui;
};

#endif // GENERATE_SAMPLE_H
