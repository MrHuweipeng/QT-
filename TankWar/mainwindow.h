#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tank.h"
#include <QTimer>
#include <QMessageBox>


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
    void keyPressEvent(QKeyEvent *ev);
    QTimer *m_timer1,*m_timer2;
    CTank m_TK;

public slots:
    void OnTimer();
    void StartClock();
    void StopClock();
    void Initial();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
