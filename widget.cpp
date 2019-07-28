#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

static int retMoney;

widget::widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbice->setEnabled(false);
}
widget::~widget()
{
    delete ui;
}

void widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));

    if (money >= 1){
        ui->pbreturn->setEnabled(true);
    }
    else{
        ui->pbreturn->setEnabled(false);
    }

    if (money >= 100){
        ui->pbCoffee->setEnabled(true);
    }
    else{
        ui->pbCoffee->setEnabled(false);
    }

    if (money >= 150){
        ui->pbTea->setEnabled(true);
    }
    else{
        ui->pbTea->setEnabled(false);
    }

    if (money >= 300){
        ui->pbice->setEnabled(true);
    }
    else{
        ui->pbice->setEnabled(false);
    }
    /*
    QMessageBox msg;
    msg.information(nullptr, "title", "text");
    make button to change money
    */
    retMoney=money;
}

void widget::retChange(int c){
    int cal, count[5];
    c= retMoney;
    cal = c;
    ui->lcd500->display(QString::number(0));
    ui->lcd100->display(QString::number(0));
    ui->lcd50->display(QString::number(0));
    ui->lcd10->display(QString::number(0));

    count[1] = retMoney / 500;
    retMoney %= 500;
    ui->lcd500->display(QString::number(count[1]));
    count[2] = retMoney / 100;
    retMoney %= 100;
    ui->lcd100->display(QString::number(count[2]));
    count[3] = retMoney / 50;
    retMoney %= 50;
    ui->lcd50->display(QString::number(count[3]));
    count[4] = retMoney / 10;
    retMoney %= 10;
    ui->lcd10->display(QString::number(count[4]));

    changeMoney(-c);
    retMoney = 0;
    ui->pbreturn->setEnabled(false);
}

void widget::on_pb10_clicked()
{
    changeMoney(10);

}


void widget::on_pb50_clicked()
{
    changeMoney(50);
}


void widget::on_pb100_clicked()
{
    changeMoney(100);
}

void widget::on_pb500_clicked()
{
    changeMoney(500);
}

void widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void widget::on_pbice_clicked()
{
    changeMoney(-300);
}



void widget::on_pbreturn_clicked()
{
    retChange(retMoney);
}
