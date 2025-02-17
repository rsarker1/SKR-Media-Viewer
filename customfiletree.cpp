#include "customfiletree.h"

CustomFileTree::CustomFileTree(QWidget *parent)
    : QTreeView{parent}
    , fileSystemModel(new CheckboxFileSystemModel(this))
    , fileManager(new FileManager(this))
    , sortProxy(new FolderOrderSort(this))
{
    initCheckboxFileSystem();

    sortProxy->setSourceModel(fileSystemModel);
    setModel(sortProxy);
    setSortingEnabled(true);
    sortByColumn(0, Qt::AscendingOrder);

    connect(fileSystemModel, &CheckboxFileSystemModel::fileChecked, fileManager, &FileManager::addFile);
}

void CustomFileTree::initCheckboxFileSystem() {
    QStringList mediaFilters = {
        "*.png", "*.jpg", "*.jpeg", "*.gif", "*.webp",          // Images
        "*.mp4", "*.mov", "*.avi", "*.mkv", "*.wmv", "*.m4v"    // Videos
    };

    fileSystemModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    fileSystemModel->setNameFilters(mediaFilters);
    fileSystemModel->setNameFilterDisables(false);
    fileSystemModel->setRootPath(QDir::rootPath());
    // fileSystemModel->setRootPath(QDir::currentPath());
    fileSystemModel->setReadOnly(true);
}

void CustomFileTree::setRootPath(const QString &path) {
    // TRANSLATE THIS LINE TO THAT
    // ui->fileTree->setRootIndex(sortDirs->mapFromSource(fileModel->index(QDir::homePath())));

    QModelIndex rootIndex = fileSystemModel->setRootPath(path);
    setRootIndex(sortProxy->mapFromSource(rootIndex));
}

