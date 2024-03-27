#include "playscene.h"

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    //翻金幣音效
      QSound *flipSound = new QSound(":/ConFlipSound.wav",this);
      //勝利按鈕音效
      QSound *winSound = new QSound(":/LevelWinSound.wav",this);
    QString str = QString("进入第 %1 关").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;

    this->setFixedSize(320,588);

    this->setWindowIcon(QPixmap(":/Coin0001.png"));

    this->setWindowTitle("翻金币场景");

    //菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,[=](){this->close();});
    //返回按鈕
    MyPushButton * closeBtn = new MyPushButton(":/BackButton.png",":/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //返回按鈕功能實現
    connect(closeBtn,&MyPushButton::clicked,[=](){
//        qDebug("11");
        QTimer::singleShot(500, this,[=]()
        {
            this->hide();
            emit this->chooseSceneBack();
        }
        );
    });

    //显示关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str1 = QString("Level:%1").arg(this->levelIndex);
    label->setText(str1);
    label->setGeometry(QRect(30, this->height() - 50,120, 50)); //設置大小和位置

    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());


    //創建金幣的背景圖片
      for(int i = 0 ; i < 4;i++)
      {
          for(int j = 0 ; j < 4; j++)
          {
             //繪製背景圖片
              QLabel* label = new QLabel;
              label->setGeometry(0,0,50,50);
              label->setPixmap(QPixmap(":/BoardNode.png"));
              label->setParent(this);
              label->move(57 + i*50,200+j*50);

          }
      }


      //金币类的封装
      dataConfig config;
      for(int i = 0;i < 4;i++)
      {
          for(int j = 0;j < 4;j++)
          {
              gameArray[i][j] = config.mData[this->levelIndex][i][j];
              //金幣對象
              QString img;
              if(gameArray[i][j] == 1)
              {
                img = ":/Coin0001.png";
              }
              else
              {
                img = ":/Coin0008.png";
              }
              MyCoin * coin = new MyCoin(img);
              coin->setParent(this);
              coin->move(59 + i*50,204+j*50);

              coin->posX = i; //記錄x座標
              coin->posY = j; //記錄y座標
              coin->flag = gameArray[i][j]; //記錄正反標誌
              coinBtn[i][j] = coin;//存储金币状态
              connect(coin,&MyCoin::clicked,[=](){
//                              qDebug() << "點擊的位置： x = " <<  coin->posX << " y = " << coin->posY ;
                              flipSound->play();
                              coin->changeFlag();
                              gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0; //陣列內部記錄的標誌同步修改
                              //翻转周围硬币
                             if(coin->posX+1 <=3)
                             {
                               coinBtn[coin->posX+1][coin->posY]->changeFlag();
                               gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                             }
                             if(coin->posX-1>=0)
                             {
                               coinBtn[coin->posX-1][coin->posY]->changeFlag();
                               gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
                             }
                             if(coin->posY+1<=3)
                             {
                              coinBtn[coin->posX][coin->posY+1]->changeFlag();
                              gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                             }
                             if(coin->posY-1>=0)
                             {
                              coinBtn[coin->posX][coin->posY-1]->changeFlag();
                              gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                             }
                             this->isWin = true;
                            for(int i = 0 ; i < 4;i++)
                            {
                                for(int j = 0 ; j < 4; j++)
                                {
                                    //qDebug() << coinBtn[i][j]->flag ;
                                    if( coinBtn[i][j]->flag == false)
                                    {
                                        this->isWin = false;
                                        break;
                                    }
                                }
                            }
                            if(this->isWin == true)
                            {
                                QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                                animation1->setDuration(1000);
                                animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                                animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+170,winLabel->width(),winLabel->height()));
                                animation1->setEasingCurve(QEasingCurve::OutBounce);
                                animation1->start();
                                winSound->play();
                                qDebug("胜利了");
                                for(int i = 0;i < 4; i++)
                                {
                                    for(int j = 0;j < 4;j++)
                                        coinBtn[i][j]->isWin = true;
                                }


                            }

                          });


          }
      }


}


void PlayScene::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //載入標題
    pix.load(":/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);


}



