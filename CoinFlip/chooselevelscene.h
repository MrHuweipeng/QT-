#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include "playscene.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    PlayScene *pScene = NULL;
signals:
    //写自定义信号到主场景
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
