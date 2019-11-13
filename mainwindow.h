#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <map>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::map<std::string, std::string> data_test;
    std::map<std::string, std::string> data_result;
};

class Dialog:public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent=nullptr);
    ~Dialog();
    void dialogUse();
private:
    QDialog *dialog;
};

#endif // MAINWINDOW_H
