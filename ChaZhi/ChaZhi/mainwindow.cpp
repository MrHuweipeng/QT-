#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_oneX1->setText("0");
    ui->lineEdit_oneY1->setText("0");
    ui->lineEdit_oneX2->setText("1");
    ui->lineEdit_oneY2->setText("1");

    ui->lineEdit_twoX1->setText("0");
    ui->lineEdit_twoY1->setText("0");
    ui->lineEdit_twoX2->setText("1");
    ui->lineEdit_twoY2->setText("1");
    ui->lineEdit_twoX3->setText("2");
    ui->lineEdit_twoY3->setText("4");

    ui->lineEdit_threeX1->setText("0");
    ui->lineEdit_threeY1->setText("0");
    ui->lineEdit_threeX2->setText("1");
    ui->lineEdit_threeY2->setText("1");
    ui->lineEdit_threeX3->setText("2");
    ui->lineEdit_threeY3->setText("8");
    ui->lineEdit_threeX4->setText("3");
    ui->lineEdit_threeY4->setText("27");

    m_painter = new QPainter();

    m_cszjs = new CSZJS();


    this->saveLineEditData();
    m_cszjs->CountAll();
    m_cszjs->CountLP();
    initCharts();
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    m_cszjs->Draw(m_painter);

    m_painter->end();
}

void MainWindow::saveLineEditData()
{
    // 一次
    m_cszjs->m_dataKnown1[0].setX(ui->lineEdit_oneX1->text().toFloat());
    m_cszjs->m_dataKnown1[0].setY(ui->lineEdit_oneY1->text().toFloat());
    m_cszjs->m_dataKnown1[1].setX(ui->lineEdit_oneX2->text().toFloat());
    m_cszjs->m_dataKnown1[1].setY(ui->lineEdit_oneY2->text().toFloat());

    // 二次
    m_cszjs->m_dataKnown2[0].setX(ui->lineEdit_twoX1->text().toFloat());
    m_cszjs->m_dataKnown2[0].setY(ui->lineEdit_twoY1->text().toFloat());
    m_cszjs->m_dataKnown2[1].setX(ui->lineEdit_twoX2->text().toFloat());
    m_cszjs->m_dataKnown2[1].setY(ui->lineEdit_twoY2->text().toFloat());
    m_cszjs->m_dataKnown2[2].setX(ui->lineEdit_twoX3->text().toFloat());
    m_cszjs->m_dataKnown2[2].setY(ui->lineEdit_twoY3->text().toFloat());

    // 三次
    m_cszjs->m_dataKnown3[0].setX(ui->lineEdit_threeX1->text().toFloat());
    m_cszjs->m_dataKnown3[0].setY(ui->lineEdit_threeY1->text().toFloat());
    m_cszjs->m_dataKnown3[1].setX(ui->lineEdit_threeX2->text().toFloat());
    m_cszjs->m_dataKnown3[1].setY(ui->lineEdit_threeY2->text().toFloat());
    m_cszjs->m_dataKnown3[2].setX(ui->lineEdit_threeX3->text().toFloat());
    m_cszjs->m_dataKnown3[2].setY(ui->lineEdit_threeY3->text().toFloat());
    m_cszjs->m_dataKnown3[3].setX(ui->lineEdit_threeX4->text().toFloat());
    m_cszjs->m_dataKnown3[3].setY(ui->lineEdit_threeY4->text().toFloat());
}

void MainWindow::initCharts()
{
    // 插值数据表
    ui->graphicsView->chart()->addSeries(m_cszjs->m_series1);
    ui->graphicsView->chart()->addSeries(m_cszjs->m_series2);
    ui->graphicsView->chart()->addSeries(m_cszjs->m_series3);
    ui->graphicsView->chart()->createDefaultAxes();
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->chart()->setTitle("插值法图像");


    // 拟合曲线表
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_serInitData651);
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_seriesOne651);
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_seriesTwo651);
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_seriesThree651);
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_seriesFour651);
    ui->graphicsView_651->chart()->addSeries(m_cszjs->m_seriesFive651);

    ui->graphicsView_651->chart()->createDefaultAxes();
    ui->graphicsView_651->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_651->chart()->setTitle("例6.5.1拟合图像");

    // 机器人运动状态表
    ui->graphicsView_robot->chart()->addSeries(m_cszjs->m_serRec);
    ui->graphicsView_robot->chart()->addSeries(m_cszjs->m_serTra);
    ui->graphicsView_robot->chart()->addSeries(m_cszjs->m_serSim);
    ui->graphicsView_robot->chart()->addSeries(m_cszjs->m_serNew);
    ui->graphicsView_robot->chart()->addSeries(m_cszjs->m_serCot);

    //ui->graphicsView_robot->chart()->createDefaultAxes();
    ui->graphicsView_robot->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_robot->chart()->setTitle("机器人运动状态表");

    QValueAxis * xAxis = new QValueAxis();
    QValueAxis * yAxis = new QValueAxis();
    xAxis->setTitleText("时间");
    yAxis->setTitleText("位移");
    xAxis->setRange(0, 10);
    yAxis->setRange(0, 20);
    xAxis->setTickCount(11);
    ui->graphicsView_robot->chart()->addAxis(xAxis, Qt::AlignBottom);
    ui->graphicsView_robot->chart()->addAxis(yAxis, Qt::AlignLeft);
    m_cszjs->m_serRec->attachAxis(xAxis);
    m_cszjs->m_serRec->attachAxis(yAxis);
    m_cszjs->m_serTra->attachAxis(xAxis);
    m_cszjs->m_serTra->attachAxis(yAxis);
    m_cszjs->m_serSim->attachAxis(xAxis);
    m_cszjs->m_serSim->attachAxis(yAxis);
    m_cszjs->m_serNew->attachAxis(xAxis);
    m_cszjs->m_serNew->attachAxis(yAxis);
    m_cszjs->m_serCot->attachAxis(xAxis);
    m_cszjs->m_serCot->attachAxis(yAxis);

    // Runge-Kutta法解微分方程
    ui->graphicsView_RungeKutta->chart()->addSeries(m_cszjs->m_serRKX);
    ui->graphicsView_RungeKutta->chart()->addSeries(m_cszjs->m_serRKY);
    ui->graphicsView_RungeKutta->chart()->addSeries(m_cszjs->m_serRKVx);
    ui->graphicsView_RungeKutta->chart()->addSeries(m_cszjs->m_serRKVy);

    ui->graphicsView_RungeKutta->chart()->createDefaultAxes();
    ui->graphicsView_RungeKutta->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_RungeKutta->chart()->setTitle("x,y,vx,vy变化轨迹");

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_oneOK_clicked()
{
    saveLineEditData();
    m_cszjs->CountAll();
    update();
}


void MainWindow::on_pushButton_twoOK_clicked()
{
    saveLineEditData();
    m_cszjs->CountAll();

    ui->lineEdit_result221->setText(QString("%1").arg(m_cszjs->m_result221));

    update();
}


void MainWindow::on_pushButton_threeOK_clicked()
{
    saveLineEditData();
    m_cszjs->CountAll();
    update();
}

