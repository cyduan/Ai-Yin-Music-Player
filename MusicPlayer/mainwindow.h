#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setButtonToPause();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    //void on_volumeSpacer_sliderMoved(int position);

    void on_volumeSpacer_valueChanged(int value);

    void on_pushButton_7_clicked();



    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QList<QUrl> playList; //播放列表
    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;
    int curPlayIndex = 0;
    int deleteIndex=0;
};
#endif // MAINWINDOW_H
