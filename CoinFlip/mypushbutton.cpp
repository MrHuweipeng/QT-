#include "mypushbutton.h"

//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{

    normalImgPath = normalImg;

    pressedImgPath = pressImg;

    QPixmap pixmap;

    bool ret = pixmap.load(normalImgPath);
    if(!ret)
    {
        qDebug() << normalImg << "载入图片失败!";
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pixmap);

    this->setIconSize(QSize(pixmap.width(),pixmap.height()));



}
void MyPushButton::zoom1()
{

    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");//创建动画

    animation1->setDuration(200);//时间间隔

    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);//弹跳效果
    animation1->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation1 =  new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressedImgPath != "")
    {
        QPixmap pixmap;

        bool ret = pixmap.load(pressedImgPath);
        if(!ret)
        {
            qDebug() << pressedImgPath <<"载入图片失败!";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pixmap);

        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    }

    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->normalImgPath != "")
    {
        QPixmap pixmap;

        bool ret = pixmap.load(normalImgPath);
        if(!ret)
        {
            qDebug() <<normalImgPath <<"载入图片失败!";
        }

        this->setFixedSize( pixmap.width(), pixmap.height() );

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pixmap);

        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    }

    return QPushButton::mouseReleaseEvent(e);
}
