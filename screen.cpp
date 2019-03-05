#include "screen.h"
#include "gun.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Screen::Screen(int w, int h) :
    img(new QImage(w, h, QImage::Format_RGB888)),
    item(new QGraphicsPixmapItem),
    gun(),
    m_speed(3000),
    m_keep(0.8) {
    item->setPixmap(QPixmap::fromImage(*img));
}

Screen::~Screen() {
    delete item;
    delete img;
}

int Screen::width() const {
    return img->width();
}

int Screen::height() const {
    return img->height();
}

QImage& Screen::image() {
    return *img;
}

QGraphicsPixmapItem* Screen::graphicsPixmapItem() {
    return item;
}

void Screen::setSpeed(int speed) {
    m_speed = speed;
}

int Screen::speed() const {
    return m_speed;
}

void Screen::setKeep(double keep) {
    m_keep = keep;
}

double Screen::keep() const {
    return m_keep;
}

void Screen::pass() {
    unsigned char* row_data = img->bits();
    for(int h = 0; h < img->height(); h++) {
        int a = h * img->bytesPerLine();
        for(int x = 0; x < img->width(); x++) {
            unsigned char* p = row_data + a + x * 3;
            p[0] = 255 - (255 - p[0]) * m_keep;
            p[1] = 255 - (255 - p[1]) * m_keep;
            p[2] = 255 - (255 - p[2]) * m_keep;
        }
    }
    int x;
    int y;
    uint rgb;
    if(gun) {
        for(int i = 0; i < m_speed; i++) {
            gun->fire(x, y, rgb);
            put(x, y, rgb);
        }
    }
    item->setPixmap(QPixmap::fromImage(*img));
}

void Screen::put(int x, int y, uint rgb) {
    img->setPixel(x, y, rgb);
}

void Screen::setGun(Gun *gun) {
    this->gun = gun;
}
