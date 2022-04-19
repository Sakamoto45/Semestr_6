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
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setup(Document* doc);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    Document *document;
};

#endif // DIALOG_H