#include "customfiletree.h"

CustomFileTree::CustomFileTree(QWidget *parent)
    : QTreeView{parent}
    , m_fsm(new CheckboxFileSystemModel(this))
    , m_fileManager(new FileManager(this))
    , m_sortProxy(new FolderOrderSort(this))
{
    QStringList mediaFilters = {
        "*.png", "*.jpg", "*.jpeg", "*.gif", "*.webp",          // Images
        "*.mp4", "*.mov", "*.avi", "*.mkv", "*.wmv", "*.m4v"    // Videos
    };

    m_fsm->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    m_fsm->setNameFilters(mediaFilters);
    m_fsm->setNameFilterDisables(false);
    m_fsm->setRootPath(QDir::rootPath());
    // m_fsm->setRootPath(QDir::currentPath());
    m_fsm->setReadOnly(true);

    m_sortProxy->setSourceModel(m_fsm);

    setModel(m_sortProxy);

    setSortingEnabled(true);
    sortByColumn(0, Qt::AscendingOrder);
}

void CustomFileTree::setRootPath(const QString &path) {
    // TRANSLATE THIS LINE TO THAT
    // ui->fileTree->setRootIndex(sortDirs->mapFromSource(fileModel->index(QDir::homePath())));

    QModelIndex rootIndex = m_fsm->setRootPath(path);
    setRootIndex(m_sortProxy->mapFromSource(rootIndex));
}

// add connector to FileManager here
