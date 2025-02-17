#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QFileDialog>

#include "mediadialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_browseButton_clicked();
    void on_files_selected(const QList<QFileInfo>& files);

private:
    Ui::MainWindow *ui;
    MediaDialog *fileWindow;
};
#endif // MAINWINDOW_H
