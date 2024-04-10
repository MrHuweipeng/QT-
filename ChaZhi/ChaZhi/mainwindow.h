#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <cszjs.h>
#include <QtCharts>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void saveLineEditData();
    void initCharts(); // 初始化表


    ~MainWindow();


public:
    CSZJS * m_cszjs;


private slots:

    void on_pushButton_oneOK_clicked();

    void on_pushButton_twoOK_clicked();

    void on_pushButton_threeOK_clicked();

private:
    Ui::MainWindow *ui;

    QPainter * m_painter;

//    //表
//    QChart * m_chart;
//    QChart * m_chart651;
};
#endif // MAINWINDOW_H
