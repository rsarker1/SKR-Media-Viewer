#include "mediadialog.h"
#include "customfiletree.h"
#include "ui_mediadialog.h"

#include <QDir>
#include <QStringList>

MediaDialog::MediaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MediaDialog)
    , fileModel(new QFileSystemModel(this))
{
    ui->setupUi(this);
    setupFileSysModel();
}

void MediaDialog::setupFileSysModel() {
    ui->fileTree->setRootPath(QDir::homePath());
}

void MediaDialog::on_buttonBox_accepted() {
    // QSet<QString> allPaths;
    qDebug() << "Accepted";
}

void MediaDialog::on_buttonBox_rejected() {
    qDebug() << "Rejected";
}

MediaDialog::~MediaDialog()
{
    delete ui;
}

// Use qSet to store file path strings
