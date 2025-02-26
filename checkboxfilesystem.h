#ifndef CHECKBOXFILESYSTEM_H
#define CHECKBOXFILESYSTEM_H

#include <QFileSystemModel>
#include <QHash>

class CheckboxFileSystemModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit CheckboxFileSystemModel(QObject *parent = nullptr);
    // Overrides for checkboxes
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    // Add the checkbox flag to items
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // Access checkbox state
    Qt::CheckState checkState(const QString &path) const;
    void setCheckState(const QString &path, Qt::CheckState state);

    // Helper
    QModelIndex indexFromPath(const QString &path) const;

public slots:
    // Dynamically update checkboxes of children
    void onRowsInserted(const QModelIndex &parent, int first, int last);

signals:
    void fileChecked(const QString &path);
    void fileUnchecked(const QString &path);

private:
    // Track checkboxes by file path
    QHash<QString, Qt::CheckState> checkStates;

    // Update checkboxes recursively when loaded in model view
    void propagateToChildren(const QModelIndex &parent, Qt::CheckState state);
};

#endif // CHECKBOXFILESYSTEM_H
