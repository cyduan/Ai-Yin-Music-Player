#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QDir>
#include <QRandomGenerator64>

int flag_love=0;
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
    //设置默认音量
    audioOutput->setVolume(0.5);
    ui->volumeSpacer->setRange(0,100);
    ui->volumeSpacer->setValue(50);

    //获取音乐总长度,同时显示音乐名称
    connect(mediaPlayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration){
        ui->totalLabel->setText(QString("%1：%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
        ui->playSpacer->setRange(0,duration);
        ui->songNameLabel->setText(ui->listWidget->currentItem()->text());
    });
    //获取当前时长
    connect(mediaPlayer,&QMediaPlayer::positionChanged,this,[=](qint64 now){
        ui->curLabel->setText(QString("%1：%2").arg(now/1000/60,2,10,QChar('0')).arg(now/1000%60,2,10,QChar('0')));
        ui->playSpacer->setValue(now);
    });
    //拖动进度条
    connect(ui->playSpacer,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);
    //自动播放下一首
    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, [=](){
        if(mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::StoppedState)
        {   //筛选播放模式
            if(flag_mode==0){//列表循环
            curPlayIndex = (curPlayIndex +1 )%playList.size();
            ui->listWidget->setCurrentRow(curPlayIndex);
            mediaPlayer->setSource  (playList[curPlayIndex]);
            mediaPlayer->play();
            setButtonToPause();}
            else if(flag_mode==1){//单曲循环
            /*ui->listWidget->setCurrentRow(curPlayIndex);
            mediaPlayer->setSource(playList[curPlayIndex]);*/
            mediaPlayer->play();
            setButtonToPause();}
            else if(flag_mode==2){//随机播放
            int number=0;
            while (true) {
                number=QRandomGenerator::global()->bounded(0,playList.size());
                if(number!=curPlayIndex)
                    break;
            }
            curPlayIndex = number;
            ui->listWidget->setCurrentRow(curPlayIndex);
            mediaPlayer->setSource(playList[curPlayIndex]);
            mediaPlayer->play();
            setButtonToPause();}
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: setButtonToPause() //将按钮设置为暂停样式
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
        if(playList.size() == 0)
        {
            break;
        }
        setButtonToPause();
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
        mediaPlayer->pause();
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState:
        setButtonToPause();
        mediaPlayer->play();
        break;

    default:
        break;
    }
}


void MainWindow::on_pushButton_8_clicked() //声音按钮
{
    switch (flag_sound) {
    case 0:
        ui->pushButton_8->setToolTip("取消静音");
        ui->pushButton_8->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/soundoff.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/soundoff_blue.png);}"
        );
        ui->volumeSpacer->setValue(0);
        break;
    case 1:
        ui->pushButton_8->setToolTip("静音");
        ui->pushButton_8->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/sound.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/sound_blue.png);}"
        );
        ui->volumeSpacer->setValue(20);
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButton_clicked() //添加文件按钮
{
    //qInfo()<<"Hello, Qt";

    //打开文件对话框，让用户选择音乐所在的目录
    auto path = QFileDialog::getExistingDirectory(this,"请选择音乐所在目录","C:\\");
    //qInfo()<<path;
    //根据所给路径，获取其中所有的常见音乐格式文件
    QDir dir(path);
    auto musicList = dir.entryList(QStringList()<<"*.mp3"<<"*.wav"<<"*.flac"<<"*.wma"<<"*.m4a");
    //qInfo()<<musicList;
    //将音乐名字放在listWidget中展示
    ui->listWidget->addItems(musicList);
    //默认选中第一个
    ui->listWidget->setCurrentRow(0);

    //将音乐的完整路径保存起来
    for(auto file : musicList)
    {
        playList.append(QUrl::fromLocalFile(path + "/" + file));
    }
}


void MainWindow::on_pushButton_3_clicked() //上一首按钮
{
    if(playList.size() == 0)
    {
        return;
    }
    //让listWiget选中上一行
    curPlayIndex = (curPlayIndex - 1+playList.size())%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
    setButtonToPause();
}


void MainWindow::on_pushButton_5_clicked() //下一首按钮
{
    if(playList.size() == 0)
    {
        return;
    }
    //让listWiget选中下一行

    curPlayIndex = (curPlayIndex +1 )%playList.size();
    ui->listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
    setButtonToPause();
}






void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)//双击播放
{
    curPlayIndex=index.row();
    mediaPlayer->setSource(playList[curPlayIndex]);
    mediaPlayer->play();
    setButtonToPause();
}



/*void MainWindow::on_volumeSpacer_sliderMoved(int position)//修改音量大小
{
    float vol=(float)position/(float)100;
    if(vol==0){
        flag_sound=1;
    }
    audioOutput->setVolume(vol);
}*/



/*void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    deleteIndex=index.row();
}*/

void MainWindow::on_volumeSpacer_valueChanged(int value)
{
    float vol=(float)value/(float)100;
    if(vol==0){
        ui->pushButton_8->setToolTip("取消静音");

        ui->pushButton_8->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/soundoff.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/soundoff_blue.png);}"
        );
        flag_sound=1;
    }
    else{
        ui->pushButton_8->setToolTip("静音");

        ui->pushButton_8->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/sound.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/sound_blue.png);}"
        );
        flag_sound=0;
    }
    audioOutput->setVolume(vol);
}


void MainWindow::on_pushButton_7_clicked()//删除功能
{

    auto item=ui->listWidget->currentItem();
    if (!item)
    {
        return;
    }
    auto index=ui->listWidget->row(item);
    playList.removeAt(index);
    ui->listWidget->takeItem(index);
}




void MainWindow::on_pushButton_6_clicked()//播放模式调整
{
    switch (flag_mode) {
    case 0:
        ui->pushButton_6->setToolTip("单曲循环");
        ui->pushButton_6->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/singleCirculation.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/singleCirculation_blue.png);}"
            );
        flag_mode=1;
        break;
    case 1:
        ui->pushButton_6->setToolTip("随机播放");
        ui->pushButton_6->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/random.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/random_blue.png);}"
            );
        flag_mode=2;
        break;
    case 2:
        ui->pushButton_6->setToolTip("列表循环");
        ui->pushButton_6->setStyleSheet(
                    "QPushButton{"
                    "icon:url(:/new/prefix1/icons/listCirculation.png);"
                    "background-color:rgba(0,0,0,0);}"
                    "QPushButton:hover{"
                    "icon:url(:/new/prefix1/icons/listCirculation_blue.png);}"
            );
        flag_mode=0;
        break;
    default:
        break;
    }
}

