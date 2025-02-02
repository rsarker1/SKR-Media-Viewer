#ifndef MEDIADIALOG_H
#define MEDIADIALOG_H

#include <QDialog>

namespace Ui {
class MediaDialog;
}

class MediaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediaDialog(QWidget *parent = nullptr);
    ~MediaDialog();

private:
    Ui::MediaDialog *ui;
};

#endif // MEDIADIALOG_H

