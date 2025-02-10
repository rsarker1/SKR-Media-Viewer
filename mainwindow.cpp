#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("SKR");

    // int w = ui->label_picture->width();
    // int h = ui->label_picture->height();


    // QPixmap picture();
}

void MainWindow::on_browseButton_clicked() {
    fileWindow = new MediaDialog(this);
    qDebug() << "This should show";
    fileWindow->setAttribute(Qt::WA_DeleteOnClose);
    fileWindow->show();
}



// static void initMediaDialog()
// {
//     static bool firstDialog = true;

//     if (firstDialog) {
//         firstDialog = false;
//         const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
//         dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
//     }

//     QStringList mimeTypeFilters;
//     const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
//                                                   ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
//     for (const QByteArray &mimeTypeName : supportedMimeTypes)
//         mimeTypeFilters.append(mimeTypeName);
//     mimeTypeFilters.sort();
//     dialog.setMimeTypeFilters(mimeTypeFilters);
//     dialog.selectMimeTypeFilter("image/jpeg");
//     dialog.setAcceptMode(acceptMode);
//     if (acceptMode == QFileDialog::AcceptSave)
//         dialog.setDefaultSuffix("jpg");
// }

// void MainWindow::open()
// {
//     // QFileDialog dialog(this, tr("Open File"));
//     // initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

//     // while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
// }





MainWindow::~MainWindow()
{
    delete ui;
}
