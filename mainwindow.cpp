#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString trial="hi";
int x =10;
void MainWindow::on_pushButton_clicked()
{

    QString text = ui->textEdit->toPlainText();
    ui->textBrowser->setText(text);

}

void MainWindow::on_textEdit_destroyed()
{
 //   trial = "hi";
}
