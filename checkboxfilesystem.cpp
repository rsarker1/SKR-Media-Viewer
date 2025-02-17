#include "checkboxfilesystem.h"

CheckboxFileSystemModel::CheckboxFileSystemModel(QObject *parent): QFileSystemModel(parent) {
    connect(this, &QFileSystemModel::rowsInserted, this, &CheckboxFileSystemModel::onRowsInserted);
}

QVariant CheckboxFileSystemModel::data(const QModelIndex &index, int role) const { // maybe set role default value to Viewable
    if (role == Qt::CheckStateRole && index.column() == 0) {
        QString path = filePath(index);
        return m_checkStates.value(path, Qt::Unchecked);
    }
    return QFileSystemModel::data(index, role);
}

bool CheckboxFileSystemModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::CheckStateRole && index.column() == 0) {
        QString path = filePath(index);
        Qt::CheckState changeState = static_cast<Qt::CheckState>(value.toInt());
        m_checkStates[path] = changeState;
        emit dataChanged(index, index, {Qt::CheckStateRole});
        if (!isDir(index)) {
            if (changeState == Qt::Checked) {
                qDebug() << "Emited fileChecked";
                emit fileChecked(path);
            }
            else {
                qDebug() << "Emited fileUnchecked";
                emit fileUnchecked(path);
            }
        } else {
            propagateToChildren(index, changeState);
        }
        return true;
    }
    return QFileSystemModel::setData(index, value, role);
}

Qt::CheckState CheckboxFileSystemModel::checkState(const QString &path) const {
    return m_checkStates.value(path, Qt::Unchecked);
}

void CheckboxFileSystemModel::setCheckState(const QString &path, Qt::CheckState state) {
    m_checkStates[path] = state;
    QModelIndex index = indexFromPath(path);
    if (index.isValid()) {
        emit dataChanged(index, index, {Qt::CheckStateRole});
    }
}

Qt::ItemFlags CheckboxFileSystemModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags currFlags = QFileSystemModel::flags(index);
    if (index.column() == 0) {
        currFlags |= Qt::ItemIsUserCheckable;
    }
    return currFlags;
}

void CheckboxFileSystemModel::propagateToChildren(const QModelIndex &parent, Qt::CheckState state) {
    for (int row = 0; row < rowCount(parent); ++row) {
        QModelIndex child = index(row, 0, parent);
        QString childPath = filePath(child);
        m_checkStates[childPath] = state;
        emit dataChanged(child, child, {Qt::CheckStateRole});

        if (!isDir(child)) {
            if (state == Qt::Checked) {
                emit fileChecked(childPath);
            }
            else {
                emit fileUnchecked(childPath);
            }
        } else {
            propagateToChildren(child, state);
        }
    }
}

void CheckboxFileSystemModel::onRowsInserted(const QModelIndex &parent, int first, int last) {
    Qt::CheckState parentState = checkState(filePath(parent));
    if (parentState == Qt::Checked) {
        for (int row = first; row <= last; ++row) {
            QModelIndex child = index(row, 0, parent);
            QString childPath = filePath(child);
            setCheckState(childPath, parentState);
        }
    }
}

QModelIndex CheckboxFileSystemModel::indexFromPath(const QString &path) const {
    return index(QDir(rootPath()).relativeFilePath(path));
}
