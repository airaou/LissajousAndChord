#include "gun.h"
#include <QRgb>
#include <cstdlib>
#include <ctime>
#include <cmath>

Gun::Gun() :
    t(0) {
    srand(time(0));
    m_div = rand() / 32768.0;
}

Gun::~Gun() {

}

#define PURE

#ifdef AVE
#   define C pow(2, 0.0 / 12.0)
#   define D pow(2, 2.0 / 12.0)
#   define E pow(2, 4.0 / 12.0)
#   define F pow(2, 5.0 / 12.0)
#   define G pow(2, 7.0 / 12.0)
#   define A pow(2, 9.0 / 12.0)
#   define B pow(2, 11.0 / 12.0)
#else
#   ifdef FIVE
#      define C 1
#      define D (9.0/8)
#      define E (81.0/64)
#      define F (4.0/3)
#      define G (3.0/2)
#      define A (27.0/16)
#      define B (243.0/128)
#   else
#       ifdef PURE
#           define C 1
#           define D (9.0/8)
#           define E (5.0/4)
#           define F (4.0/3)
#           define G (3.0/2)
#           define A (5.0/3)
#           define B (15.0/8)
#       endif
#   endif
#endif

void Gun::fire(int& x, int& y, uint& rgb) {
    t++;

    double a =
            sin(440 * C * 2 * M_PI * t / 3e5 + m_div);
    double b = (
                sin(440 * C * 2 * M_PI * t / 3e5) +
                sin(440 * E * 2 * M_PI * t / 3e5) +
                sin(440 * G * 2 * M_PI * t / 3e5) +
                0) / 2;

    x = 300 + 100 * a;
    y = 300 + 100 * b;

    rgb = qRgb(0, 0, 0);
}

void Gun::setDiv(double div) {
    m_div = div;
}

double Gun::div() const {
    return m_div;
}
