#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cditu.h"
#include "NoBodyCar.h"
#include "WRJ.h"
#include "pso.h"
#include <QPaintEvent>
#include <QTimer>
#include "dialog.h"
#include "car_pso.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CDiTu *m_DT;
    CNoBodyCar *m_NC;
    CWRJ *m_WRJ;
    PSO *m_PSO;
    Dialog m_dlg;
    Car_PSO  *m_carPSO;

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *ev);
    QTimer *m_timer1,*m_timer2;
    CDC *pDC;
    //地图
    CPoint m_LBuD;
    CPoint m_tempD;
    int m_DTBJ;
    int m_ZTBJ;//小车状态
    int m_LBup;
signals:
    void CanShuSignal(float,float,float,float);
public slots:
    void DiTuGongNeng();
    void OnTimer();
    void StartClock();
    void StopClock();
    void CarStartClock();
    void CarStopClock();
    void DianNaDaoNa();
    void GuiJiYunDong();
    void YunSuYunDong();
    void ZhaoXieLouDian();
    void AnLuXianYunDong();
    void CeShiNongDu();
    void CanShuSlot(float,float,float,float);
private slots:
    void on_actionwlkaishi_triggered();

    void on_actionwljieshu_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
