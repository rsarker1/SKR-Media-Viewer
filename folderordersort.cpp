#include "folderordersort.h"

FolderOrderSort::FolderOrderSort(QObject *parent) : QSortFilterProxyModel(parent) {}

bool lessThan(const QModelIndex &left, const QModelIndex &right) const {
    QFileSystemModel *fsm = qobject_cast<QFileSystemModel*>(sourceModel());
    if (!fsm) return QSortFilterProxyModel::lessThan(left, right);

    const QFileInfo leftInfo = fsm->fileInfo(left);
    const QFileInfo rightInfo = fsm->fileInfo(right);

    if (leftInfo.isDir() && !rightInfo.isDir()) return true;
    if (!leftInfo.isDir() && rightInfo.isDir()) return false;

    // Alphabetical sorting within directories or files
    return leftInfo.fileName().compare(rightInfo.fileName(),
                                       Qt::CaseInsensitive) < 0;
}
