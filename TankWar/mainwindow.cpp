#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer1 = new QTimer;
    m_timer2 = new QTimer;
    connect(m_timer1, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(m_timer2, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(ui->actionkaishi, SIGNAL(triggered()), this, SLOT(StartClock()));
    connect(ui->actionzanting, SIGNAL(triggered()), this, SLOT(StopClock()));
    connect(ui->actionInitial, SIGNAL(triggered()), this, SLOT(Initial()));
    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    m_TK.Draw(&painter);
    update();
}
void MainWindow::OnTimer()
{
    QTimer* senderTimer = qobject_cast<QTimer*>(QObject::sender());
    if (senderTimer == m_timer1)
    {
        m_TK.MoveBullet();
        m_TK.MoveBlock();
        m_TK.MoveTank();
        if (1 == m_TK.BlockHitTank())
        {
            m_timer1->stop();
            m_timer2->stop();
            QMessageBox::about(this, "您被击中！", QString("得分为 %1").arg(m_TK.m_Score));
        }

    }
    else if (senderTimer == m_timer2)
    {
        m_TK.CreateBlock();
    }



   update();
}
void MainWindow::StartClock()
{
    m_timer1->start(80);
    m_timer2->start(1000);
}

void MainWindow::StopClock()
{
    m_timer1->stop();
    m_timer2->stop();
}
void MainWindow::Initial()
{
    m_TK.InitGame();
}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key())
    {
        case Qt::Key_Left:
            if(Qt::Key_Left == ev->key())
                m_TK.m_direct = 37;
            break;
        case Qt::Key_Up:
            if(Qt::Key_Up == ev->key())
                m_TK.m_direct = 38;
            break;
        case Qt::Key_Right:
            if(Qt::Key_Right == ev->key())
                m_TK.m_direct = 39;
            break;
        case Qt::Key_Down:
            if(Qt::Key_Down == ev->key())
                m_TK.m_direct = 40;
            break;
        case Qt::Key_Space:
            m_TK.CreateBullet();
    }
    update();
}
