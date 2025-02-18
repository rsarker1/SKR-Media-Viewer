#include "slideshow.h"
#include "ui_slideshow.h"

Slideshow::Slideshow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Slideshow)
{
    ui->setupUi(this);
}

Slideshow::~Slideshow()
{
    delete ui;
}
