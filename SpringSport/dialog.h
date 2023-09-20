#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "tanhuang.h"
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    float m_m,m_InitL,m_x,m_y,m_TLK,m_ZN,m_v;
    TanHuang m_TH;
public slots:
    void on_pushButton_clicked();


public:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
