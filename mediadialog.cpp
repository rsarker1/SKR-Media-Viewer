#include "mediadialog.h"
#include "ui_mediadialog.h"

MediaDialog::MediaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MediaDialog)
{
    ui->setupUi(this);
}

MediaDialog::~MediaDialog()
{
    delete ui;
}
