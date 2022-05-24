#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "document.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Document* doc, QWidget *parent = nullptr);
    ~Dialog();

    int show_part(bool H0, bool H1, bool Pvalue, bool Power);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_H0_input_p_editingFinished();
    void on_H1_input_p_editingFinished();

    void on_Power_input_significance_level_editingFinished();

private:
    Ui::Dialog *ui;
    Document *document;
    void reset();
};

#endif // DIALOG_H
