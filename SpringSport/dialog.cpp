#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    ui->lineEdit_x->setText(QString::number(m_TH.m_YD.x()));
    ui->lineEdit_y->setText(QString::number(m_TH.m_YD.y()));
    ui->lineEdit_k->setText(QString::number(m_TH.m_TLK,'f',2));
    ui->lineEdit_v->setText(QString::number(m_TH.m_v,'f',2));
    ui->lineEdit_m->setText(QString::number(m_TH.m_m,'f',2));
    ui->lineEdit_l->setText(QString::number(m_TH.m_InitL,'f',2));
    ui->lineEdit_ZN->setText(QString::number(m_TH.m_ZN,'f',2));
}

