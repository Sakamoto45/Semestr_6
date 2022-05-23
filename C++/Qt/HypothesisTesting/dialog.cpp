#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(Document* doc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    document(doc)
{
    ui->setupUi(this);
    reset();
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::show_part(bool H0, bool H1, bool Pvalue)
{
    ui->H0->setEnabled(H0);
    ui->H1->setEnabled(H1);
    ui->Pvalue->setEnabled(Pvalue);
    return exec();
}

void Dialog::reset()
{
    ui->H0_input_p->setValue(document->get_p0());
    ui->H0_input_k->setValue(document->get_k0());

    ui->H1_input_p->setValue(document->get_p1());
    ui->H1_input_k->setValue(document->get_k1());
    ui->H1_input_sample_size->setValue(document->get_sample_size());
    switch (document->method) {
    case Document::Method::Bernulli:
        ui->H1_radio_Bernulli->setChecked(true);
        ui->H1_radio_Table->setChecked(false);
        break;
    case Document::Method::Table:
        ui->H1_radio_Bernulli->setChecked(false);
        ui->H1_radio_Table->setChecked(true);
        break;
    }

    ui->P_input_sample_size->setValue(document->get_p_sample_size());
}

void Dialog::on_buttonBox_accepted()
{
    if (ui->H0->isEnabled()) {
        document->set_distribution_0(ui->H0_input_p->value(),
                                     ui->H0_input_k->value());
    }
    if (ui->H1->isEnabled()) {
        if (ui->H1_radio_Bernulli->isChecked()) {
            document->method = Document::Method::Bernulli;
        } else if (ui->H1_radio_Table->isChecked()) {
            document->method = Document::Method::Table;
        }
        document->set_distribution_1(ui->H1_input_p->value(),
                                     ui->H1_input_k->value(),
                                     ui->H1_input_sample_size->value());
    }
    if (ui->Pvalue->isEnabled()) {
        document->set_p_sample_size(ui->P_input_sample_size->value());
    }
    done(1);
}


void Dialog::on_buttonBox_rejected()
{
    reset();
    done(0);
}

void Dialog::on_H0_input_p_editingFinished()
{
    double new_p = ui->H0_input_p->value();
    if (new_p < 0 || new_p > 1) {
        ui->H0_input_p->setValue(document->get_p0());
    }
}

void Dialog::on_H1_input_p_editingFinished()
{
    double new_p = ui->H1_input_p->value();
    if (new_p < 0 || new_p > 1) {
        ui->H1_input_p->setValue(document->get_p1());
    }
}



