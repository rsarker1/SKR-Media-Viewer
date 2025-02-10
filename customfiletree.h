#ifndef CUSTOMFILETREE_H
#define CUSTOMFILETREE_H

#include <QTreeView>
#include "checkboxfilesystem.h"
#include "folderordersort.h"

class CustomFileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit CustomFileTree(QWidget *parent = nullptr);
    void setRootPath(const QString &path);

protected slots:
    // Handle selection changes (e.g., toggle checkboxes)
    //void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
private:
    CheckboxFileSystemModel *m_fsm;
    FolderOrderSort *m_sortProxy;
};

#endif // CUSTOMFILETREE_H
