/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QSlider *verticalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 605);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(2, 504, 791, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setToolTipDuration(-1);
        pushButton->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:rgba(0,0,0,0);}\n"
"QPushButton:hover{\n"
"icon:url(:/new/prefix1/icons/add_blue.png);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(50, 50));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setToolTipDuration(-1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgba(0, 0, 0,0);\n"
"}\n"
"QPushButton:pressed{\n"
"icon:url(:/new/prefix1/icons/love.png);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/dislike.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoExclusive(false);
        pushButton_2->setFlat(false);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"icon:url(:/new/prefix1/icons/previous_blue.png);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"QPushButton:hover{\n"
"icon:url(:/new/prefix1/icons/play_blue.png);}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"QPushButton:hover{\n"
"icon:url(:/new/prefix1/icons/next_blue.png);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(50, 50));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"QPushButton:hover{\n"
"icon:url(:/new/prefix1/icons/delete_red.png)\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);
        pushButton_7->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/listCirculation.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon6);
        pushButton_6->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(50, 50));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
"\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icons/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon7);
        pushButton_8->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_8);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(720, 330, 18, 160));
        verticalSlider->setMouseTracking(false);
        verticalSlider->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\267\273\345\212\240</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MainWindow", "\345\225\212\357\274\201\345\245\275\347\210\261~~", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\222\255\346\224\276</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_7->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
