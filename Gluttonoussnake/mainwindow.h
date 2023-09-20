#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <QLabel>
typedef struct
{
    int x,y; //定义蛇的位置坐标
}SSnakeJD; //定义蛇对象
typedef struct
{
    int x,y; //定义食物的位置坐标
}SFood; //定义食物对象
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitialSnake();
    void paintEvent(QPaintEvent *event);
    void DrawBackground();
    void DrawSnake();
    void keyPressEvent(QKeyEvent *ev);
    void timerEvent(QTimerEvent *ev);
    void JudgeSnakeHeadDirection();
    void JudgeCollide();
    void MoveSnake();
    void DrawFood();

    SSnakeJD m_snake[100];
    SFood m_food;
    int m_direct;
    int m_len;
    int m_ZSJx,m_ZSJy;
    int m_id1;
    QTimer *m_timer;
    QPainter painter;
    QString str;

private slots:
    void on_pushButton_Start_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_clicked();
    void OnTimer();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
