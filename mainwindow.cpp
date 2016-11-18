#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanner.h"
#include <QString>
#include <QMap>
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


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText(); // read the input
    QMap<QString,QString> token;
    token["if"]="reserve word";
    token["then"]="reserved word";
    token["end"]="reserved word";
    token["until"]="reserved word";
    token["write"]="reserved word";
    token["else"]="reserved word";
    token["repeat"]="reserved word";
    token["read"]="reserved word";
    token["+"]="plus";
    token["-"]="minus";
    token["*"]="multiple";
    token["/"]="divide";
    token[";"]="SEMI";
    token[":="]="ASSIGN";

    enum state{start,inComment,inID,inNum,inAssign,done,identifier};
    state s=start;

    QString myCharContainer="";
    QVector <QString>container;

    for (int i = 0 ;i < (text.size()+1);i++){
        QChar ch = text[i];
        switch (s) {
          case start:
                 myCharContainer="";
                 if (text[i]=='{')
                 {
                    myCharContainer=myCharContainer+text[i];
                    s=inComment;
                 }
                     //if (text[i]==':')
                     //{ myCharContainer = myCharContainer+(text[i]); s=inAssign; }
                     //else if (text[i]=='{')
                       //  s=inComment;
                     //else if (isalpha(text[i],loc))
                       //  s=inID;
                     //else if (isdigit(text[i],loc))
                       //  s=inNum;
                     //else if (text[i]== "\n" || text[i]=="\t" || text[i]==' ')
                       //  s=start;
                     //else s= done;
                 break;


           case inComment:
                while (text[i] !='}')
                { i++;}
                s=start;
                break;
           /*case inID:
             while (isalnum(text[i],loc))
             {
                 myCharContainer=myCharContainer+text[i];
                 i++;
             }
             break;
                 case inNum:break;
          case inAssign:
                 if (text[i]=='=') { myCharContainer= myCharContainer+(text[i]);}
                  s=done;
                 break;
          case done:
                 container.push_back(myCharContainer);
                 s=start;
           break;*/
          }
      }

    /* Scanner scanner;
    scanner.separateTextToLines(text);
    QMap<QString,QString>toPrint = scanner.returnPrintedTable();

    QMap<QString, QString>::iterator i;
    for (i = toPrint.begin(); i != toPrint.end(); i++)
    {
        ui->textBrowser->setText(i.value()+i.key()) ;
    }
    //ui->textBrowser->setText(text);
    */

}

void MainWindow::on_textEdit_destroyed()
{
 //   trial = "hi";
}
