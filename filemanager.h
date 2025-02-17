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
    const QList<QFileInfo> getFiles() { return m_files; }

public slots:
    void addFile(const QString &path);
    void removeFile(const QString &path);

private:
    QList<QFileInfo> m_files;
    QHash<QString, int> m_pathIndexMap;
};

#endif // FILEMANAGER_H
