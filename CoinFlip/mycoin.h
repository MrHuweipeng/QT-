#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QIcon>
#include <QDebug>
#include <QTimer>



class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);

      MyCoin(QString butImg);
      void mousePressEvent(QMouseEvent *e);

        int posX,posY;
        bool flag,isAnimation = false;//正反面

        void changeFlag();
        QTimer *timer1,*timer2;
        int min = 1;
        int max = 8;
        bool isWin = false;//是否胜利标志


signals:

};

#endif // MYCOIN_H
