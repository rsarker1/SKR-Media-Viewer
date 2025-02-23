#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("SKR");
    // int w = ui->label_picture->width();
    // int h = ui->label_picture->height();
}

void MainWindow::on_browseButton_clicked() {
    fileWindow = new MediaDialog(this);
    connect(fileWindow, &MediaDialog::selectedFiles, this, &MainWindow::on_files_selected);
    fileWindow->show();
}

void MainWindow::on_files_selected(const QList<QFileInfo>& files) {
    // Picture testing
    // for (const QFileInfo &media : files) {
    //     qDebug() << media.absoluteFilePath();
    //     QPixmap picture(media.absoluteFilePath());
    //     ui->label_picture->setPixmap(picture);
    // }
    hide();
    // Restore main window when slideshow closes
    slideshowWindow = new Slideshow(this);
    connect(slideshowWindow, &Slideshow::destroyed, this, [this]() {
        show();
        slideshowWindow = nullptr;
    });
    slideshowWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
