#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fileWindow(new MediaDialog(this))
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("SKR");
    connect(fileWindow, &MediaDialog::selectedFiles, this, &MainWindow::on_files_selected);
    // int w = ui->label_picture->width();
    // int h = ui->label_picture->height();
}

void MainWindow::on_browseButton_clicked() {
    fileWindow->setWindowModality(Qt::ApplicationModal);
    fileWindow->setAttribute(Qt::WA_DeleteOnClose);
    fileWindow->show();
}

void MainWindow::on_files_selected(const QList<QFileInfo>& files) {
    for (const QFileInfo &media : files) {
        qDebug() << media.absoluteFilePath();
        QPixmap picture(media.absoluteFilePath());
        ui->label_picture->setPixmap(picture);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
