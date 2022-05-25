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

int Dialog::show_part(bool H0, bool H1, bool Pvalue, bool Power)
{
    ui->H0->setEnabled(H0);
    ui->H1->setEnabled(H1);
    ui->Pvalue->setEnabled(Pvalue);
    ui->Power->setEnabled(Power);
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
        break;
    case Document::Method::Table:
        ui->H1_radio_Table->setChecked(true);
        break;
    case Document::Method::Inverse:
        ui->H1_radio_Inverse->setChecked(true);
        break;
    }

    ui->P_input_sample_size->setValue(document->get_p_sample_size());

    ui->Power_input_significance_level->setValue(document->get_significance_level());
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
        } else if (ui->H1_radio_Inverse->isChecked()) {
            document->method = Document::Method::Inverse;
        }
        document->set_distribution_1(ui->H1_input_p->value(),
                                     ui->H1_input_k->value(),
                                     ui->H1_input_sample_size->value());
    }
    if (ui->Pvalue->isEnabled()) {
        document->set_p_sample_size(ui->P_input_sample_size->value());
    }
    if (ui->Power->isEnabled()) {
        document->set_significance_level(ui->Power_input_significance_level->value());
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

void Dialog::on_Power_input_significance_level_editingFinished()
{
    double new_significance_level = ui->Power_input_significance_level->value();
    if (new_significance_level < 0 || new_significance_level > 1) {
        ui->Power_input_significance_level->setValue(document->get_significance_level());
    }
}

