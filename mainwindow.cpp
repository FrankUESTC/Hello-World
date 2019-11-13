#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>

QString s2q(const std::string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string key=this->ui->lineEdit->text().toStdString();
    int len=this->ui->lineEdit_2->text().toInt();
    std::string addr=this->ui->lineEdit_3->text().toStdString();
    auto iter=data_test.find(key);
    if(iter!=data_test.end())
    {
        int len_temp = iter->second.length();
        if(len_temp<len)
        {
            QMessageBox::warning(this,tr("waring"),tr("data len out of range"),QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit->setFocus();
        }
        else
        {
            QString str=s2q(iter->second.substr(0,len));
            ui->lineEdit_6->setText(ui->lineEdit_6->text()=str);
            QMessageBox::about(nullptr, "Success","Data Read OK!");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit->setFocus();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("waring"),tr("No current data!"),QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit->setFocus();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    std::string key=this->ui->lineEdit_4->text().toStdString();
    std::string value=this->ui->lineEdit_5->text().toStdString();
    data_test.insert(make_pair(key,value));
    QMessageBox::about(nullptr, "Success","Data Write OK!");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit->setFocus();
}
