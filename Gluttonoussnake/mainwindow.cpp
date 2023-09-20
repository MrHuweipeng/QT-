#include "mainwindow.h"
#include "ui_mainwindow.h"

#define H_L 40
#define GZSIZE 20
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    m_ZSJx = 40;
    m_ZSJy = 40;
    InitialSnake();
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

    connect(ui->radioButton_ND1, &QRadioButton::clicked, this, [=](){
        m_timer->start(150);
        ui->radioButton_ND2->setChecked(false);
        ui->radioButton_ND3->setChecked(false);
    });
    connect(ui->radioButton_ND2, &QRadioButton::clicked, this, [=](){
        m_timer->start(200);
        ui->radioButton_ND1->setChecked(false);
        ui->radioButton_ND3->setChecked(false);
    });
    connect(ui->radioButton_ND3, &QRadioButton::clicked, this, [=](){
        m_timer->start(300);
        ui->radioButton_ND1->setChecked(false);
        ui->radioButton_ND2->setChecked(false);
    });
    ui->radioButton_ND1->setChecked(true);
    ui->radioButton_ND1->setAutoExclusive(false);
    ui->radioButton_ND2->setAutoExclusive(false);
    ui->radioButton_ND3->setAutoExclusive(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    QPixmap pixmap(":/Image/Background.jpg");
    pixmap = pixmap.scaled(39*20,39*20);//设置图片大小
    painter.drawPixmap(40, 40, pixmap);
    DrawBackground();
    DrawSnake();
    DrawFood();
    update();

    painter.end();
}
void MainWindow::InitialSnake()
{
    m_snake[0].x = 20;
    m_snake[0].y = 20;
    m_snake[1].x = 20;
    m_snake[1].y = 21;
    m_direct = 38;
    m_len = 2;
    srand(time(NULL));
    m_food.x = rand()%38;
    m_food.y = rand()%38;
    //蛇刚开始向下运动，40为键盘向下的ASCII码
    //初始化蛇的长度为2个小方格


}
void MainWindow::DrawBackground()
{
    //QPainter painter(this);

    QPen pen;//画笔
    pen.setColor(Qt::black);//定义画笔颜色
    pen.setWidth(2);//设置画笔的宽度
    painter.setPen(pen);//添加画笔

//    int i,j;
//    for(i=0;i<H_L;i++)
//    {
//        for(j=0;j<H_L;j++)
//        {
//            painter.drawLine(m_ZSJx+j*GZSIZE,m_ZSJy,m_ZSJx+j*GZSIZE,m_ZSJy + (H_L-1-i)*GZSIZE);
//        }

//    }
//    for(i=0;i<H_L;i++)
//    {
//        for(j=0;j<H_L;j++)
//        {
//            painter.drawLine(m_ZSJx,m_ZSJy+j*GZSIZE,m_ZSJx + (H_L-1-i)*GZSIZE,m_ZSJy+j*GZSIZE);
//        }

//    }
    painter.drawRect(m_ZSJx,m_ZSJy,39*GZSIZE,39*GZSIZE);
    str = QString(" 分数为 %1 ").arg(10 * (m_len - 2));
    ui->label->setText(str);
}
void MainWindow::DrawSnake()
{
    QBrush *b = new QBrush;//创建画刷对象

    b->setColor(Qt::red);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    painter.setBrush(*b);//将画刷交给画家
    for(int i = 0;i < m_len;i++)
    {
        painter.drawRect(m_ZSJx + m_snake[i].x * GZSIZE,m_ZSJy + m_snake[i].y * GZSIZE,GZSIZE,GZSIZE);
    }
}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key())
    {//对蛇头方向进行判断
        case Qt::Key_Left:
            if(Qt::Key_Left == ev->key() && m_direct != 39)
                m_direct = 37;
            break;
        case Qt::Key_Up:
            if(Qt::Key_Up == ev->key() && m_direct != 40)
                m_direct = 38;
            break;
        case Qt::Key_Right:
            if(Qt::Key_Right == ev->key() && m_direct != 37)
                m_direct = 39;
            break;
        case Qt::Key_Down:
            if(Qt::Key_Down == ev->key() && m_direct != 38)
                m_direct = 40;
            break;
    }
}

void MainWindow::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == m_id1)
    {
        JudgeCollide();
        MoveSnake();
//        FoodRondom();

    }
}
void MainWindow::on_pushButton_Start_clicked()
{

    m_timer->start(150);
}

void MainWindow::on_pushButton_Stop_clicked()
{
   m_timer->stop();
}
void MainWindow::JudgeSnakeHeadDirection()
{
    if(m_direct == 37)
        m_snake[0].x--; //向左
    if(m_direct == 38)
        m_snake[0].y--; //向上
    if(m_direct == 39)
        m_snake[0].x++; //向右
    if(m_direct == 40)
        m_snake[0].y++; //向下

}
void MainWindow::JudgeCollide()
{
    if(m_snake[0].x <= 0 || m_snake[0].y <= 0 || m_snake[0].x>= H_L - 2 || m_snake[0].y >= H_L - 2)
    {
        m_timer->stop();
        QMessageBox::about(this, "游戏结束", str);
    }
    if(m_len >=4)
    {
        for(int i = m_len -1;i > 0;i--)
        {
            if(m_snake[0].x == m_snake[i].x && m_snake[0].y == m_snake[i].y)
            {
                m_timer->stop();
                QMessageBox::about(this, "游戏结束", str);
            }
        }
    }
}
void MainWindow::MoveSnake()
{
    int i;

    for(i = m_len - 1;i > 0;i--)
    {
        m_snake[i].x = m_snake[i-1].x;//蛇尾处加了一节
        m_snake[i].y = m_snake[i-1].y;
    }
    JudgeSnakeHeadDirection();
    if(m_snake[0].x == m_food.x && m_snake[0].y == m_food.y) //如果食物被吃
    {
        srand(time(NULL));
        m_food.x = rand()%39;
        m_food.y = rand()%39;
        m_len++;
    }

}

void MainWindow::DrawFood()
{
    QBrush *b = new QBrush;//创建画刷对象

    b->setColor(Qt::blue);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    painter.setBrush(*b);//将画刷交给画家

    painter.drawEllipse(m_ZSJx + m_food.x * GZSIZE,m_ZSJy + m_food.y * GZSIZE,GZSIZE,GZSIZE);

}

void MainWindow::on_pushButton_clicked()
{
    InitialSnake();
}

void MainWindow::OnTimer()
{
    JudgeCollide();
    MoveSnake();
}
