#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tanhuang.h"
#include <QTimer>
#include <QDebug>
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
    TanHuang m_TH;
    Dialog m_dlg;
    QTimer *m_timer;
public slots:
    void OnTimer();
    void StartClock();
    void StopClock();
    void CanShuSheZhi();
    void InitCanShu();

public slots:
    void on_pushButton_XiuGai_clicked();

public:
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
