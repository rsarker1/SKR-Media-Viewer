#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <QMainWindow>

namespace Ui {
class Slideshow;
}

class Slideshow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Slideshow(QWidget *parent = nullptr);
    ~Slideshow();

private:
    Ui::Slideshow *ui;
};

#endif // SLIDESHOW_H
