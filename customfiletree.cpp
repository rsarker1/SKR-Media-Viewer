#include "customfiletree.h"

CustomFileTree::CustomFileTree(QWidget *parent)
    : QTreeView{parent}
{
    QStringList mediaFilters = {
        "*.png", "*.jpg", "*.jpeg", "*.gif", "*.webp",          // Images
        "*.mp4", "*.mov", "*.avi", "*.mkv", "*.wmv", "*.m4v"    // Videos
    };
    m_fsm = new CheckboxFileSystemModel();
    m_sortProxy = new FolderOrderSort();

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
// void CustomFileTree::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
//     QTreeView::selectionChanged(selected, deselected);

//     // Toggle checkboxes based on selection (assuming model supports CheckStateRole)
//     QAbstractItemModel *model = this->model();
//     if (!model) return;

//     // Deselected items: Uncheck
//     for (const QModelIndex &index : deselected.indexes()) {
//         model->setData(index, Qt::Unchecked, Qt::CheckStateRole);
//     }

//     // Selected items: Check
//     for (const QModelIndex &index : selected.indexes()) {
//         model->setData(index, Qt::Checked, Qt::CheckStateRole);
//     }
// }
