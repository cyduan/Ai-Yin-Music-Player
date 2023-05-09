#include "mainwindow.h"
#include "ui_mainwindow.h"
int flag_love=0;
int flag_play=0;
int flag_mode=0;
int flag_sound=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    switch (flag_love) {
    case 0:
        ui->pushButton_2->setToolTip("哼！不爱了！！！");
        ui->pushButton_2->setIcon(QIcon(":/new/prefix1/icons/love.png"));
        flag_love=(flag_love+1)%2;
        break;
    case 1:
        ui->pushButton_2->setToolTip("啊！好爱~~");
        ui->pushButton_2->setIcon(QIcon(":/new/prefix1/icons/dislike.png"));
        flag_love=(flag_love+1)%2;
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    switch (flag_play) {
    case 0:
        ui->pushButton_4->setToolTip("暂停");
        ui->pushButton_4->setStyleSheet(
        "QPushButton{"
        "icon:url(:/new/prefix1/icons/suspend.png);"
        "background-color:rgba(0,0,0,0);}"
        "QPushButton:hover{"
        "icon:url(:/new/prefix1/icons/suspend_blue.png);}"
        );
        flag_play=(flag_play+1)%2;
        break;
    case 1:
        ui->pushButton_4->setToolTip("播放");
        ui->pushButton_4->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/play.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/play_blue.png);}"
        );
        flag_play=(flag_play+1)%2;
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    switch (flag_sound) {
    case 0:
        ui->pushButton_8->setToolTip("声音");
        break;
    default:
        break;
    }
}

