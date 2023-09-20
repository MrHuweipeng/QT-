#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer;
    m_nPic = 1;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(this,SIGNAL(CanShuSignal(float,float,float,float,float,float)),&m_dlg,SLOT(CanShuSlot(float,float,float,float,float,float)));
    connect(&m_dlg,SIGNAL(CanShuSignal(float,float,float,float,float,float)),this,SLOT(CanShuSlot(float,float,float,float,float,float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    m_PP.Draw(&painter,m_nPic);
    update();
}
void MainWindow::OnTimer()
{
    m_PP.Move();
}
void MainWindow::on_actionkaishi_triggered()
{
    m_timer->start(100);
}

void MainWindow::on_actionzanting_triggered()
{
    m_timer->stop();
}

void MainWindow::on_actionweiyi_triggered()
{
    m_nPic = 1;
}

void MainWindow::on_actionsudu_triggered()
{
    m_nPic = 2;
}


void MainWindow::CanShuSlot(float x,float y,float z,float vx,float vy,float vz)
{
    m_PP.m_x = x;
    m_PP.m_y = y;
    m_PP.m_z = z;
    m_PP.m_Vx = vx;
    m_PP.m_Vy = vy;
    m_PP.m_Vz = vz;

    m_dlg.close();

}

void MainWindow::on_actioncanshushezhi_triggered()
{
    float x,y,z,vx,vy,vz;
    x = m_PP.m_x;
    y = m_PP.m_y;
    z = m_PP.m_z;
    vx = m_PP.m_Vx;
    vy = m_PP.m_Vy;
    vz = m_PP.m_Vz;
    emit(CanShuSignal(x,y,z,vx,vy,vz));

    m_dlg.show();
}
