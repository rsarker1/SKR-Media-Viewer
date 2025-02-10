#include "checkboxfilesystem.h"

CheckboxFileSystemModel::CheckboxFileSystemModel(QObject *parent): QFileSystemModel{parent} {}

QVariant CheckboxFileSystemModel::data(const QModelIndex &index, int role) const { // maybe set role default value to Viewable
    if (role == Qt::CheckStateRole) {
        QString path = filePath(index);
        return m_checkStates.value(path, Qt::Unchecked);
    }
    return QFileSystemModel::data(index, role);
}

bool CheckboxFileSystemModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::CheckStateRole) {
        QString path = filePath(index);
        m_checkStates[path] = static_cast<Qt::CheckState>(value.toInt());
        emit dataChanged(index, index, {Qt::CheckStateRole});
        return true;
    }
    return QFileSystemModel::setData(index, value, role);
}

Qt::ItemFlags CheckboxFileSystemModel::flags(const QModelIndex &index) const {
    return QFileSystemModel::flags(index) | Qt::ItemIsUserCheckable;
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

QModelIndex CheckboxFileSystemModel::indexFromPath(const QString &path) const {
    return index(QDir(rootPath()).relativeFilePath(path));
}
