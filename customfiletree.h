#ifndef CUSTOMFILETREE_H
#define CUSTOMFILETREE_H

#include <QTreeView>
#include "checkboxfilesystem.h"
#include "folderordersort.h"
#include "filemanager.h"

class CustomFileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit CustomFileTree(QWidget *parent = nullptr);

    void setRootPath(const QString &path);
    FileManager *getFileManager() { return fileManager; }

private:
    CheckboxFileSystemModel *fileSystemModel;
    FileManager *fileManager;
    FolderOrderSort *sortProxy;

    void initCheckboxFileSystem();
};

#endif // CUSTOMFILETREE_H
