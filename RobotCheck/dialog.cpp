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

void Dialog::CanShuSlot(float wz,float r,float fx,float jsd)
{
    ui->lineEdit_WZ->setText(QString::number(wz,'f',1));
    ui->lineEdit_R->setText(QString::number(r,'f',1));
    ui->lineEdit_XZFX->setText(QString::number(fx,'f',1));
    ui->lineEdit_JSD->setText(QString::number(jsd,'f',1));
    update();
}

void Dialog::on_pushButton_clicked()
{
    float wz,fx,r,jsd;
    wz = ui->lineEdit_WZ->text().toFloat();
    fx = ui->lineEdit_XZFX->text().toFloat();
    r = ui->lineEdit_R->text().toFloat();
    jsd = ui->lineEdit_JSD->text().toFloat();

    emit(CanShuSignal(wz,fx,r,jsd));

//    qDebug("222");
}
