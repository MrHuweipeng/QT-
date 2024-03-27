#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QString>
#include <mycoin.h>
#include "dataconfig.h"
#include <QSound>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene (int levelNum);
    void paintEvent(QPaintEvent *);
    int levelIndex;

    int gameArray[4][4];
    MyCoin * coinBtn[4][4]; //金幣按鈕陣列
    bool isWin;//是否胜利标志

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
