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
    const FileManager* getFileManager() { return m_fileManager; }

private:
    CheckboxFileSystemModel *m_fsm;
    FileManager *m_fileManager;
    FolderOrderSort *m_sortProxy;
};

#endif // CUSTOMFILETREE_H
