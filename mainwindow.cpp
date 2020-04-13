#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <dialog.h>
#include <youwin.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Pig Pekin");
    setWindowIcon(QIcon(":/img/icon.jpg"));
    game = new GameCore();
    timeLabel = new QLabel(this);
    countLabel = new QLabel(this);
    timer = new QTimer(this); // Ê±¼ä´¥·¢Æ÷
    setFixedSize(3*blockSize+offsetX*2,3*blockSize+offsetY*2);
    timeLabel->setGeometry(100,660,300,35); timeLabel->setFont(QFont("Microsoft YaHei",10,75)); timeLabel->setText("Time-Consuming: " + QString::number(game->time_cnt));
    countLabel->setGeometry(350,660,300,35); countLabel->setFont(QFont("Microsoft YaHei",10,75));
    connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(onAboutClick()));
    connect(ui->actionRestart,SIGNAL(triggered(bool)),this,SLOT(onRestartClick()));
    connect(ui->actionClose,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTimer()));
    timer->start(1000);
}

void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    QPixmap pm[10];
    pm[2].load(":/img/2.jpg");
    pm[3].load(":/img/3.jpg");
    pm[4].load(":/img/4.jpg");
    pm[5].load(":/img/5.jpg");
    pm[6].load(":/img/6.jpg");
    pm[7].load(":/img/7.jpg");
    pm[8].load(":/img/8.jpg");
    pm[9].load(":/img/9.jpg");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if(game->Map[i][j] != 0) {
                int im = game->Map[i][j];
                QPixmap tmp(pm[im]);
                p.drawPixmap(offsetX+(i-1)*blockSize, offsetY+(j-1)*blockSize, tmp, 0, 0, blockSize, blockSize);
            }
        }
    }
    updateCount();
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    int x = e->x();
    int y = e->y();
    if (x >= offsetX && y >= offsetY && x <= offsetX+3*blockSize && y <= offsetY+3*blockSize) {
        int n = (y-offsetY) / blockSize + 1;
        int m = (x-offsetX) / blockSize + 1;
        game->move(m,n);
//        for (int i = 1; i <= 3; i++) {
//            for (int j = 1; j <= 3; j++) {
//                qDebug() << game->Map[j][i];
//            }
//            qDebug();
//        }
        update();
        if(game->check()) {
            timer->stop();
            youwin *win = new youwin;
            win->show();
        }
    }
}

void MainWindow::onAboutClick() {
    Dialog *log = new Dialog();
    log->show();
}

void MainWindow::onRestartClick() {
    game->restartGame();
    update();
}

void MainWindow::updateTimer() {
    game->time_cnt++;
    timeLabel->setText("Time-Consuming: " + QString::number(game->time_cnt));
}

void MainWindow::updateCount() {
    countLabel->setText("Step-Count: " + QString::number(game->step_cnt));
}

MainWindow::~MainWindow()
{
    delete ui;
}

