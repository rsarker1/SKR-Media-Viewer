#include "slideshow.h"
#include "ui_slideshow.h"

Slideshow::Slideshow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Slideshow)
{
    ui->setupUi(this);
    setWindowTitle("Slideshow");
    setAttribute(Qt::WA_DeleteOnClose);
    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // setWindowState(Qt::WindowFullScreen);
}

Slideshow::~Slideshow()
{
    delete ui;
}
