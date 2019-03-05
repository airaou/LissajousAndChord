#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QGraphicsScene;
class QGraphicsPixmapItem;
class Screen;
class Gun;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_keepSlider_valueChanged(int value);

    void on_speedSlider_valueChanged(int value);

    void on_divSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* item;
    Screen* screen;
    Gun* gun;
    QTimer* timer;
};

#endif // MAINWINDOW_H
