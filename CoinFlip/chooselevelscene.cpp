#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(320,588);

    this->setWindowIcon(QPixmap(":/Coin0001.png"));
    this->setWindowTitle("选择关卡");
    //菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,[=](){this->close();});
    //back返回按钮
    MyPushButton * backBtn = new MyPushButton(":/BackButton.png",":/BackButtonSelected.png");
    backBtn->setParent(this);//继承父类按钮的性质
    backBtn->move(this->width() - backBtn->width(),this->height() - backBtn->height());
    QSound *backSound = new QSound(":/BackButtonSound.wav",this);
    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
       // qDebug()<<"返回";
        //告诉主场景我返回了
        backSound->play();
        QTimer::singleShot(50,this,[=](){
                emit this->chooseSceneBack();  //发送信号
        });

    }); 
    QSound *chooseSound = new QSound(":/TapButtonSound.wav",this);

    //创建选择关卡的按钮
    for(int i = 0;i<20;i++)
    {
        MyPushButton *MenuBtn = new MyPushButton(":/LevelIcon.png");
        MenuBtn->setParent(this);
        MenuBtn->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
        //监听每个按钮的点击事件
        connect(MenuBtn,&MyPushButton::clicked,[=]{
            QString str = QString("选择第 %1 关").arg(i + 1);
            qDebug()<<str;
            chooseSound->play();
            if(pScene == NULL)  //遊戲場景最好不用複用，直接移除掉創建新的場景
              {
                  this->hide();
                  pScene = new PlayScene(i+1); //將選擇的關卡號 傳入給PlayerScene
                  pScene->show();
              }

            connect(pScene,&PlayScene::chooseSceneBack,[=]()
            {
                this->show();
                delete pScene;
                pScene = NULL;
            });
        });

        QLabel * label = new QLabel;
        label->setParent(this);//或加一个show也行
        label->setFixedSize(MenuBtn->width(),MenuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + (i%4)*70 , 130+ (i/4)*70);
        label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

        //设置鼠标穿透事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);

    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   QPixmap pix;
   pix.load(":/OtherSceneBg.png");
   painter.drawPixmap(0,0,this->width(),this->height(),pix);

   //标题
   pix.load(":/Title.png");
   painter.drawPixmap(20,30,pix.width(),pix.height(),pix);

}
