#ifndef MEDIADIALOG_H
#define MEDIADIALOG_H

#include <QDialog>
#include "customfiletree.h"

namespace Ui {
class MediaDialog;
}

class MediaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediaDialog(QWidget *parent = nullptr);
    ~MediaDialog();

public slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

signals:
    void selectedFiles(const QList<QFileInfo>& files);

private:
    Ui::MediaDialog *ui;
};

#endif // MEDIADIALOG_H

