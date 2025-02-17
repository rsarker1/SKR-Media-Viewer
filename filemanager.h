#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFileInfo>
#include <QList>
#include <QHash>

class FileManager: public QObject
{
    Q_OBJECT

public:
    explicit FileManager(QObject *parent = nullptr);

    enum SortCriteria { Name, Modified, Random };
    Q_ENUM(SortCriteria);
    // Add Filter later?
    void sortBy(SortCriteria sortType);
    const QList<QFileInfo> getFiles() { return fileInfoList; }

public slots:
    void addFile(const QString &path);
    void removeFile(const QString &path);

private:
    QList<QFileInfo> fileInfoList;
    QHash<QString, int> pathIndexMap;
};

#endif // FILEMANAGER_H
