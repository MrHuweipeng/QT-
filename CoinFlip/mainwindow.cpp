#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chooseScene = new ChooseLevelScene;
    this->setFixedSize(320,588);//修改固定大小
    this->setWindowIcon(QPixmap(":/Coin0001.png"));

    //设置视窗标题
    this->setWindowTitle("老帮主带你翻金币");

    connect(ui->actionQuit,&QAction::triggered,[=](){this->close();});//关闭窗口

    //音效
    QSound *startSound = new QSound(":/TapButtonSound.wav",this);
    MyPushButton * startBtn = new MyPushButton(":/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    connect(startBtn,&MyPushButton::clicked,[=] ()
    {
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(500, this,[=](){
            this->hide();
            chooseScene->show();

        });
        startSound->play(); //開始音效
    });
    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=]()
    {
        chooseScene->hide();
        this->show();

    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//绘制背景图

    //载入标题
    pix.load(":/Title.png");

    //縮放圖片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);

    //绘制标题
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);


}

