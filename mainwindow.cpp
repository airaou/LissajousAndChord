#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTime>
#include "screen.h"
#include "gun.h"
#include <QTimer>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene),
    item(new QGraphicsPixmapItem),
    screen(new Screen(600, 600)),
    gun(new Gun()),
    timer(new QTimer) {
    ui->setupUi(this);
    scene->addItem(screen->graphicsPixmapItem());
    ui->graphicsView->setScene(scene);

    timer->setInterval(20);
    screen->setGun(gun);
    connect(timer, SIGNAL(timeout()), screen, SLOT(pass()));
}

MainWindow::~MainWindow() {
    delete timer;
    delete screen;
    delete gun;
    delete scene;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    timer->start();
}

void MainWindow::on_pushButton_2_clicked() {
    screen->put(3, 3, qRgb(0, 0, 0));
}

void MainWindow::on_keepSlider_valueChanged(int value) {
    screen->setKeep((double)value / ui->keepSlider->maximum());
}

void MainWindow::on_speedSlider_valueChanged(int value) {
    screen->setSpeed(value);
}

void MainWindow::on_divSlider_valueChanged(int value) {
    gun->setDiv(value * 2 * M_PI / 100);
}
