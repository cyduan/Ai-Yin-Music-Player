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
    //如何播放音乐
    //初始化output对象
    audioOutput = new QAudioOutput(this);
    //初始化媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked() //喜不喜欢按钮
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


void MainWindow::on_pushButton_4_clicked() //播放和暂停按钮
{
    switch (mediaPlayer->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        ui->pushButton_4->setToolTip("暂停");
        ui->pushButton_4->setStyleSheet(
        "QPushButton{"
        "icon:url(:/new/prefix1/icons/suspend.png);"
        "background-color:rgba(0,0,0,0);}"
        "QPushButton:hover{"
        "icon:url(:/new/prefix1/icons/suspend_blue.png);}"
        );
        flag_play=(flag_play+1)%2;
        if(playList.size() == 0)
        {
            break;
        }
        //播放当前选中的音乐
        curPlayIndex = ui->listWidget->currentRow();
        //给播放器设置音乐
        mediaPlayer->setSource(playList[curPlayIndex]);
        //播放
        mediaPlayer->play();

        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState:
    {
        ui->pushButton_4->setToolTip("播放");
        ui->pushButton_4->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/play.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/play_blue.png);}"
        );
        flag_play=(flag_play+1)%2;
        mediaPlayer->pause();
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState:
    {
        ui->pushButton_4->setToolTip("暂停");
        ui->pushButton_4->setStyleSheet(
            "QPushButton{"
            "icon:url(:/new/prefix1/icons/suspend.png);"
            "background-color:rgba(0,0,0,0);}"
            "QPushButton:hover{"
            "icon:url(:/new/prefix1/icons/suspend_blue.png);}"
            );
        mediaPlayer->play();
        break;
    }
    default:
        break;
    }
}


void MainWindow::on_pushButton_8_clicked() //声音按钮
{
    switch (flag_sound) {
    case 0:
        ui->pushButton_8->setToolTip("声音");
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButton_clicked() //添加文件按钮
{
    //qInfo()<<"Hello, Qt";

    //打开文件对话框，让用户选择音乐所在的目录
    auto path = QFileDialog::getExistingDirectory(this,"请选择音乐所在目录","D:\\music");
    //qInfo()<<path;
    //根据所给路径，获取其中所有的.mp3和.wav文件
    QDir dir(path);
    auto musicList = dir.entryList(QStringList()<<"*.mp3"<<"*.wav");
    //qInfo()<<musicList;
    //将音乐名字放在listWidget中展示
    ui->listWidget->addItems(musicList);
    //默认选中第一个
    ui->listWidget->setCurrentRow(0);

    //将音乐的完整路径保存起来
    //中文路径问题暂未解决
    for(auto file : musicList)
    {
        QUrl loadFile = QUrl::fromLocalFile(path + "/" + file);
        playList.append((QUrl)loadFile);
    }
    qInfo()<<playList;
}


void MainWindow::on_pushButton_3_clicked() //上一首按钮
{

    //让listWiget选中上一行
    curPlayIndex = (curPlayIndex - 1  + playList.size())%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    //mediaPlayer->stop();
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}


void MainWindow::on_pushButton_5_clicked() //下一首按钮
{
    //让listWiget选中下一行
    curPlayIndex = (curPlayIndex +1 )%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    //mediaPlayer->stop();
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();

}




void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    curPlayIndex = index.row();
    if(mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::PausedState ||
        mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::StoppedState  )
    {
        ui->pushButton_4->setToolTip("暂停");
        ui->pushButton_4->setStyleSheet(
            "QPushButton{"
            "icon:url(:/new/prefix1/icons/suspend.png);"
            "background-color:rgba(0,0,0,0);}"
            "QPushButton:hover{"
            "icon:url(:/new/prefix1/icons/suspend_blue.png);}"
            );
    }
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
}

