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
void Dialog::CanShuSlot(float x,float y,float z,float vx,float vy,float vz)
{
    ui->lineEdit_x->setText(QString::number(x,'f',1));
    ui->lineEdit_y->setText(QString::number(y,'f',1));
    ui->lineEdit_z->setText(QString::number(z,'f',1));
    ui->lineEdit_vx->setText(QString::number(vx,'f',1));
    ui->lineEdit_vy->setText(QString::number(vy,'f',1));
    ui->lineEdit_vz->setText(QString::number(vz,'f',1));

    update();
}


void Dialog::on_pushButton_clicked()
{
    float x,y,z,vx,vy,vz;
    x = ui->lineEdit_x->text().toFloat();
    y = ui->lineEdit_y->text().toFloat();
    z = ui->lineEdit_z->text().toFloat();
    vx = ui->lineEdit_vx->text().toFloat();
    vy = ui->lineEdit_vy->text().toFloat();
    vz = ui->lineEdit_vz->text().toFloat();

    emit(CanShuSignal(x,y,z,vx,vy,vz));
}
