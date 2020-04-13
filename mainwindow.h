#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GameCore.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int blockSize = 194;
const int offsetX = 30;
const int offsetY = 70;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    GameCore *game;
    QTimer *timer;
    QLabel *timeLabel;
    QLabel *countLabel;

private slots:
    void onAboutClick();
    void onRestartClick();
    void updateTimer();
    void updateCount();
};
#endif // MAINWINDOW_H
