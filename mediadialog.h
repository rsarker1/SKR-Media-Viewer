#ifndef MEDIADIALOG_H
#define MEDIADIALOG_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class MediaDialog;
}

class MediaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediaDialog(QWidget *parent = nullptr);
    ~MediaDialog();

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::MediaDialog *ui;
    QFileSystemModel *fileModel;
    void setupFileSysModel();
};

#endif // MEDIADIALOG_H

