#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer;
    InitCanShu();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    connect(ui->start, SIGNAL(triggered()), this, SLOT(StartClock()));
    connect(ui->stop, SIGNAL(triggered()), this, SLOT(StopClock()));
    connect(ui->actioncanshushezhi, &QAction::triggered, this, &MainWindow::CanShuSheZhi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    m_TH.Draw(&painter);
    update();
}
void MainWindow::OnTimer()
{
    m_TH.Move();
}

void MainWindow::StartClock()
{
    m_timer->start(100);
}

void MainWindow::StopClock()
{
    m_timer->stop();
}

void MainWindow::CanShuSheZhi()
{
    //
//        m_dlg->ui->lineEdit_k->setText(QString::number(m_TH.m_m));
//     m_dlg->m_x= m_TH.m_YD.x();
//     m_dlg->m_ZN = m_TH.m_ZN;
//     m_dlg->m_TLK =m_TH.m_TLK;
//     m_dlg->m_y = m_TH.m_YD.y();
//     m_dlg->m_v = m_TH.m_v;
//     m_dlg->m_InitL = m_TH.m_InitL;

//    qDebug()<<m_dlg->m_m;
        m_dlg.exec();


}

void MainWindow::InitCanShu()
{
//    m_dlg->m_m= m_TH.m_m;
//    m_dlg->m_x= m_TH.m_YD.x();
//    m_dlg->m_ZN = m_TH.m_ZN;
//    m_dlg->m_TLK =m_TH.m_TLK;
//    m_dlg->m_y = m_TH.m_YD.y();
//    m_dlg->m_v = m_TH.m_v;
//    m_dlg->m_InitL = m_TH.m_InitL;
    ui->lineEdit_k->setText(QString::number(m_TH.m_TLK,'f',2));
    ui->lineEdit_x->setText(QString::number(m_TH.m_YD.x()));
    ui->lineEdit_y->setText(QString::number(m_TH.m_YD.y()));
    ui->lineEdit_v->setText(QString::number(m_TH.m_v,'f',2));
    ui->lineEdit_ZN->setText(QString::number(m_TH.m_ZN,'f',2));
    ui->lineEdit_l->setText(QString::number(m_TH.m_InitL,'f',2));
    ui->lineEdit_m->setText(QString::number(m_TH.m_m,'f',2));
}


void MainWindow::on_pushButton_XiuGai_clicked()
{

    m_TH.m_m = ui->lineEdit_m->text().toFloat();
    m_TH.m_YD.setX(ui->lineEdit_x->text().toInt());

    m_TH.m_ZN = ui->lineEdit_ZN->text().toFloat();
    m_TH.m_TLK = ui->lineEdit_k->text().toFloat();
    m_TH.m_YD.setY(ui->lineEdit_y->text().toInt());
    m_TH.m_v = ui->lineEdit_v->text().toFloat();
    m_TH.m_InitL = ui->lineEdit_l->text().toFloat();

//    qDebug()<<ui->lineEdit_k->text().toFloat();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_TH.m_YD.setX(400);
    m_TH.m_YD.setY(50);
    m_TH.m_k = 200;
    m_TH.m_TLK = 20;
    m_TH.m_InitL = 0.2;
    m_TH.m_l = 0.5;
    m_TH.m_Upl = 0.2;
    m_TH.m_Downl = 0.1;
    m_TH.m_m = 1.0;
    m_TH.m_ZN = 0.96;
    m_TH.m_v = 1;
    m_TH.m_WY = 0;
    m_TH.m_w = 0.2;
    m_TH.m_r = 0.05;
    m_TH.m_detatl = 0.1;
    m_TH.m_nvQX = 0;
    m_TH.m_naQX= 0;
    m_TH.m_nfQX = 0;
    m_TH.m_nwyQX = 0;
}
