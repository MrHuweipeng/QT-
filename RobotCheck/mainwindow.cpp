#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pDC = new CDC;
    m_DT = new CDiTu;
    m_NC = new CNoBodyCar;
    m_WRJ = new CWRJ;
    m_PSO = new PSO;
    m_carPSO= new Car_PSO;
    m_timer1 = new QTimer;
    m_timer2 = new QTimer;
    connect(ui->actionSFYD,SIGNAL(triggered()), this, SLOT(DiTuGongNeng()));
    connect(m_timer1, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(m_timer2, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(ui->actionkaishi, SIGNAL(triggered()), this, SLOT(StartClock()));
    connect(ui->actionjieshu, SIGNAL(triggered()), this, SLOT(StopClock()));
    connect(ui->actionKaiShi, SIGNAL(triggered()), this, SLOT(CarStartClock()));
    connect(ui->actionJieShu, SIGNAL(triggered()), this, SLOT(CarStopClock()));
    connect(ui->action_DNDN, SIGNAL(triggered()), this, SLOT(DianNaDaoNa()));
    connect(ui->action_GJYD, SIGNAL(triggered()), this, SLOT(GuiJiYunDong()));
    connect(ui->action_YSYD, SIGNAL(triggered()), this, SLOT(YunSuYunDong()));
    connect(ui->action_ZXLD, SIGNAL(triggered()), this, SLOT(ZhaoXieLouDian()));
    connect(ui->action_ALXYD, SIGNAL(triggered()), this, SLOT(AnLuXianYunDong()));
    connect(ui->actionCND, SIGNAL(triggered()), this, SLOT(CeShiNongDu()));

    connect(this,SIGNAL(CanShuSignal(float,float,float,float)),&m_dlg,SLOT(CanShuSlot(float,float,float,float)));
    connect(&m_dlg,SIGNAL(CanShuSignal(float,float,float,float)),this,SLOT(CanShuSlot(float,float,float,float)));

    m_LBup = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    pDC->begin(this);
    m_DT->Draw(pDC);
    m_NC->Draw(pDC);
    m_WRJ->Draw(pDC);
//    m_carPSO->Draw(pDC);
    m_PSO->Draw(pDC);
    update();
    pDC->end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(m_DTBJ == 1&&m_LBup == 0)
    {
        if (event->button() == Qt::LeftButton)
        {
            // 记录鼠标点击位置
            m_LBuD.x = event->pos().x();
            m_LBuD.y = event->pos().y();

            m_tempD = m_DT->m_YD;
        }
    }
    m_LBup = 0;
    m_NC->ChuLiLBD(event->pos().x(),event->pos().y());
    update();


}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_LBup = 1;
    qDebug("111");
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_DTBJ == 1&&m_LBup == 0)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            // 获取鼠标拖动的偏移量，并更新窗口位置
            m_DT->m_YD.x = m_tempD.x + event->pos().x() - m_LBuD.x;
            m_DT->m_YD.y = m_tempD.y + event->pos().y() - m_LBuD.y;
        }
    }
    update();

}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(m_DTBJ == 1)
    {
        if(event->delta() > 0)
        {
            m_DT->m_kx *= 1.1;
            m_DT->m_ky *= 1.1;
            m_NC->m_kx *= 1.1;
            m_NC->m_ky *= 1.1;
            m_WRJ->m_kWRJ *= 1.1;
            m_WRJ->m_WJ_r *= 1.1;
            m_WRJ->m_LXJ_L *= 1.1;
            m_WRJ->m_WRJL *= 1.1;

            m_NC->m_kCar *= 1.1;
        }

        if(event->delta() < 0)
        {
            m_DT->m_kx *= 0.9;
            m_DT->m_ky *= 0.9;
            m_NC->m_kx *= 0.9;
            m_NC->m_ky *= 0.9;
            m_WRJ->m_kWRJ *= 0.9;
            m_WRJ->m_WJ_r *= 0.9;
            m_WRJ->m_LXJ_L *= 0.9;
            m_WRJ->m_WRJL *= 0.9;

            m_NC->m_kCar *= 0.9;
        }
        update();
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_NC->m_x = m_NC->m_LX[0][0];
        m_NC->m_y = m_NC->m_LX[0][1];
        m_NC->m_nMBD = 0;
        update();
    }
}
void MainWindow::OnTimer()
{
    QTimer* senderTimer = qobject_cast<QTimer*>(QObject::sender());

    if(senderTimer == m_timer1)
    {
        m_DT->CreateLiZi();
        m_DT->MoveLiZi();
    }
    else if(senderTimer == m_timer2)
    {
        m_NC->Move();
        if(m_NC->m_BJ == 1)
        {
            m_timer2->stop();
            m_NC->m_BJ = 0;
        }
        else if(m_NC->m_CarZT == XZXLD)
        {
            m_NC->ZhuanQuanSearchXieLou();
        }

        for(int i = 0;i<N;i++)
        {
            m_PSO->m_lz[i].ND = m_DT->QiuND(m_PSO->m_lz[i].x,m_PSO->m_lz[i].y);
            qDebug()<<m_PSO->m_lz[i].ND;
        }
//        for (int i = 0; i < m_carPSO->m_carPSO.count(); i++)
//        {
//            m_carPSO->m_carPSO[i].nd = m_DT->QiuND(m_carPSO->m_carPSO[i].pos.x(),
//                                                        m_carPSO->m_carPSO[i].pos.y());
//        }

//        m_carPSO->Move();
        m_WRJ->MoveLXJ();
        m_PSO->UpDate();

    }
    m_NC->m_ND = m_DT->QiuND(m_NC->m_x,m_NC->m_y);
    m_WRJ->m_WRJ_ND = m_DT->QiuND(m_WRJ->m_WJ_x,m_WRJ->m_WJ_y);

    update();

}
void MainWindow::DiTuGongNeng()
{
    m_DTBJ = 1;
    m_timer1->stop();
    m_timer2->stop();
}

void MainWindow::StartClock()
{
    m_timer1->start(100);
}

void MainWindow::StopClock()
{
    m_timer1->stop();
}

void MainWindow::CarStartClock()
{
    m_timer2->start(100);
    m_NC->QiuCircleDot();
}

void MainWindow::CarStopClock()
{
   m_timer2->stop();
}

void MainWindow::DianNaDaoNa()
{
    m_DTBJ = 0;
    m_NC->m_CarZT = DNDN;
    m_LBup = 1;
}

void MainWindow::GuiJiYunDong()
{
    m_DTBJ = 0;
    m_NC->m_CarZT = GJYD;
    float r,wz,fx,jsd;
    wz = m_NC->m_WZ;
    r = m_NC->m_CirR;
    fx = m_NC->m_FX;
    jsd = m_NC->m_JSD;
    emit(CanShuSignal(wz,r,fx,jsd));

    m_dlg.show();

}

void MainWindow::YunSuYunDong()
{
    m_NC->m_CarZT = YSYD;
    m_DTBJ = 0;
}

void MainWindow::ZhaoXieLouDian()
{
    m_DTBJ = 0;
    m_NC->m_CarZT = XZXLD;
}

void MainWindow::AnLuXianYunDong()
{
    m_NC->m_CarZT = LUXIAN;
    m_DTBJ = 0;
}

void MainWindow::CeShiNongDu()
{
    m_DTBJ = 0;
    m_NC->InitialCirND();
    m_NC->m_CarZT = CSND;
}

void MainWindow::CanShuSlot(float wz,float fx,float r,float jsd)
{
    m_NC->m_WZ = wz;
    m_NC->m_CirR = r;
    m_NC->m_FX = fx;
    m_NC->m_JSD = jsd;
    m_dlg.close();

    m_NC->QiuCircleDot();
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key())
    {//对蛇头方向进行判断
        case Qt::Key_Left:
            if(Qt::Key_Left == ev->key())
                m_WRJ->m_WJ_x -= 6;
            break;
        case Qt::Key_Up:
            if(Qt::Key_Up == ev->key())
                m_WRJ->m_WJ_y += 6;
            break;
        case Qt::Key_Right:
            if(Qt::Key_Right == ev->key())
                m_WRJ->m_WJ_x += 6;
            break;
        case Qt::Key_Down:
            if(Qt::Key_Down == ev->key())
                m_WRJ->m_WJ_y -= 6;
            break;
    }
}

void MainWindow::on_actionwlkaishi_triggered()
{

}

void MainWindow::on_actionwljieshu_triggered()
{

}
