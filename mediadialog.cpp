#include "mediadialog.h"
#include "ui_mediadialog.h"

#include <QDir>
#include <QStringList>

MediaDialog::MediaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MediaDialog)
{
    ui->setupUi(this);

    connect(, &CheckboxFileSystemModel::fileChecked, mediaManager, &FileManager::addFile);
    // connect(fileModel, &CheckboxFileSystemModel::fileUnchecked, mediaManager, &FileManager::removeFile);
    ui->fileTree->setRootPath(QDir::homePath());
}

void MediaDialog::on_buttonBox_accepted() {
    // QSet<QString> allPaths;
    qDebug() << "Accepted";
    emit selectedFiles(mediaManager->files());
}

void MediaDialog::on_buttonBox_rejected() {
    qDebug() << "Rejected";
}

MediaDialog::~MediaDialog()
{
    delete ui;
}

// Use qSet to store file path strings
