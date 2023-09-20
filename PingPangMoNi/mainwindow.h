#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include "PingPong.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    int m_nPic;
    CPingPong m_PP;
    QTimer *m_timer;
    Dialog m_dlg;
signals:
    void CanShuSignal(float,float,float,float,float,float);
public slots:
    void OnTimer();
    void on_actionkaishi_triggered();

    void on_actionzanting_triggered();

    void on_actionweiyi_triggered();

    void on_actionsudu_triggered();

    void CanShuSlot(float,float,float,float,float,float);
private slots:
    void on_actioncanshushezhi_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
