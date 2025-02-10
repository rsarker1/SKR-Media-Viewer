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
    // QStringList mediaFilters = {
    //     "*.png", "*.jpg", "*.jpeg", "*.gif", "*.webp",          // Images
    //     "*.mp4", "*.mov", "*.avi", "*.mkv", "*.wmv", "*.m4v"    // Videos
    // };
    // fileModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    // fileModel->setNameFilters(mediaFilters);
    // fileModel->setNameFilterDisables(false);
    // fileModel->setRootPath(QDir::currentPath());
    // fileModel->setReadOnly(true);

    // FolderOrderSort *sortDirs = new FolderOrderSort();
    // sortDirs->setSourceModel(fileModel);

    // ui->fileTree->setModel(sortDirs);
    // ui->fileTree->setSortingEnabled(true);
    // ui->fileTree->sortByColumn(0, Qt::AscendingOrder);


    // This sets the path to the parent directory of the project
    //ui->fileTree->setRootIndex(sortDirs->mapFromSource(fileModel->index(QDir::homePath())));
    ui->fileTree->setRootPath(QDir::homePath());
};


void MediaDialog::on_buttonBox_rejected() {
    qDebug() << "Rejected";
}

void MediaDialog::on_buttonBox_accepted() {
    qDebug() << "Accepted";
}








MediaDialog::~MediaDialog()
{
    delete ui;
}
