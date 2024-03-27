#include "mycoin.h"

//MyCoin::MyCoin(QWidget *parent) : QWidget(parent)
//{

//}


MyCoin::MyCoin(QString btnimg)
{
    QPixmap pix;
    bool ret =  pix.load(btnimg);
    if(!ret)
    {
        qDebug() << btnimg << "載入图片失敗!";
    }

    this->setFixedSize( pix.width(), pix.height() );
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,&QTimer::timeout,[=]()
    {
        QPixmap pix;
        QString str = QString(":/Coin000%1").arg((this->min)++);
        pix.load(str);

        this->setFixedSize( pix.width(), pix.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断 如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->min = 1;
            this->isAnimation = false;

            timer1->stop();

        }


    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str = QString(":/Coin000%1.png").arg((this->max)-- );
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        if(this->max < this->min) //如果小於最小值，重置最大值，並停止計時器
        {
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });
}

void MyCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else //反面執行下列代碼
    {
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }

}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        return;
    }
    else
    {
         QPushButton::mousePressEvent(e);
    }
}
