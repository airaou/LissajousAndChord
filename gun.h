#ifndef GUN_H
#define GUN_H

#include <QObject>

class Gun : public QObject {
    Q_OBJECT

public:
    Gun();
    ~Gun();

    void fire(int& x, int& y, uint& rgb);
    void setDiv(double div);
    double div() const;

private:
    int t;

    double m_div;
};

#endif // GUN_H
