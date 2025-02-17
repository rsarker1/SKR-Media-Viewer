#include "filemanager.h"
#include <QCollator>

FileManager::FileManager(QObject *parent): QObject(parent) {}

void FileManager::addFile(const QString &path) {
    QFileInfo fileInfo(path);
    if (!pathIndexMap.contains(fileInfo.absoluteFilePath())) {
        fileInfoList.append(fileInfo);
        pathIndexMap[path] = fileInfoList.size() - 1;
    }
}

void FileManager::removeFile(const QString &path) {
    if (pathIndexMap.contains(path)) {
        int index = pathIndexMap[path];
        fileInfoList.removeAt(index);
        pathIndexMap.remove(path);

        // Update paths after removal
        for (int i = index; i < fileInfoList.size() - 1; ++i) {
            pathIndexMap[fileInfoList[i].absoluteFilePath()] = i;
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

