#include "filemanager.h"
#include <QCollator>

FileManager::FileManager(QObject *parent): QObject(parent) {}

void FileManager::addFile(const QString &path) {
    qDebug() << "Test";
    QFileInfo fileInfo(path);
    if (!m_pathIndexMap.contains(fileInfo.absoluteFilePath())) {
        m_files.append(fileInfo);
        m_pathIndexMap[path] = m_files.size() - 1;
    }
}

void FileManager::removeFile(const QString &path) {
    if (m_pathIndexMap.contains(path)) {
        int index = m_pathIndexMap[path];
        m_files.removeAt(index);
        m_pathIndexMap.remove(path);

        // Update paths after removal
        for (int i = index; i < m_files.size() - 1; ++i) {
            m_pathIndexMap[m_files[i].absoluteFilePath()] = i;
        }
    }
}

void FileManager::sortBy(SortCriteria sortType) {
    // TODO

    switch (sortType) {
    case Name:

        break;
    case Modified:

        break;
    case Random:

        break;
    default:
        break;
    }
}

