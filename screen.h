#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
class Gun;
class QImage;
class QGraphicsPixmapItem;

class Screen : public QObject {
    Q_OBJECT
private:
    QImage* img;
    QGraphicsPixmapItem* item;
    Gun* gun;
    int m_speed;
    double m_keep;

public:
    Screen(int w, int h);
    ~Screen();
    int width() const;
    int height() const;
    QImage& image();
    QGraphicsPixmapItem* graphicsPixmapItem();

    void setGun(Gun* gun);
    void put(int x, int y, uint rgb);
    void setSpeed(int speed);
    int speed() const;
    void setKeep(double keep);
    double keep() const;

public slots:
    void pass();
};

#endif // SCREEN_H
