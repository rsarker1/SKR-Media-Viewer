#include "mediadialog.h"
#include "ui_mediadialog.h"

#include <QDir>
#include <QStringList>

MediaDialog::MediaDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MediaDialog)
{
    ui->setupUi(this);
    ui->fileTree->setRootPath(QDir::homePath());
}

void MediaDialog::on_buttonBox_accepted() {
    // QSet<QString> allPaths;
    qDebug() << "Accepted";
    FileManager *treeFileManager = ui->fileTree->getFileManager();
    const QList<QFileInfo> checkedFiles = treeFileManager->getFiles();

    emit selectedFiles(checkedFiles);
}

void MediaDialog::on_buttonBox_rejected() {
    qDebug() << "Rejected";
}

MediaDialog::~MediaDialog()
{
    delete ui;
}
