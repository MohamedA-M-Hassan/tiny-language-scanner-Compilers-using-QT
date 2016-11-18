#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanner.h"
#include <QString>
#include <QMap>
// copy paste to check if num or n
#include <locale>         // std::locale, std::isdigit
#include <sstream>        // std::QStringstream
using namespace std;

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
    using namespace std;
    QString text = ui->textEdit->toPlainText(); // read the input
    QMap<QString,QString> token;
    token["if"]     ="reserve word";
    token["then"]   ="reserved word";
    token["end"]    ="reserved word";
    token["until"]  ="reserved word";
    token["write"]  ="reserved word";
    token["else"]   ="reserved word";
    token["repeat"] ="reserved word";
    token["read"]   ="reserved word";
    token["+"]      ="plus";
    token["-"]      ="minus";
    token["*"]      ="multiple";
    token["/"]      ="divide";
    token[";"]      ="SEMI";
    token[":="]     ="ASSIGN";

    enum state{start,inComment,inID,inNum,inAssign,done,identifier};
    state s=start;


    QString myCharContainer="";
    //double numberContainer=NULL;
    QVector <QString>container;

    for (int i = 0 ;i < (text.size()+1);i++){
        QChar ch = text[i];
        label:  switch (s) {   // the label to not waste the current char
                               // or u can use (i--) instead of (goto)
          case start:
                 myCharContainer="";
                 // comment
                 if (text[i]=='{')
                 {
                    //myCharContainer=myCharContainer+text[i];
                    s=inComment;
                 }
                 // assign
                 else if (text[i]==':') {
                    myCharContainer=myCharContainer+text[i];
                    s=inAssign;
                 }
                 //else if (isalpha(text[i],loc))
                       //  s=inID;
                 //  numbers
                 else if (text[i].isDigit())
                 {
                    myCharContainer=myCharContainer+text[i];
                    s=inNum;
                 }
                     //else if (text[i]== "\n" || text[i]=="\t" || text[i]==' ')
                       //  s=start;
                     //else s= done;
                 break;


           case inAssign:
                   if (text[i]=='=')
                   { myCharContainer= myCharContainer+(text[i]);}
                    s=done;
                    goto label;      // or u can use (i--) instead of (goto)
                   break;
           case inComment:
                    while (text[i] !='}')
                        { i++;}
                    s=start;
                    break;
           case inNum:
                    while (text[i].isDigit() || text[i]== '.')
                    {
                        myCharContainer=myCharContainer+text[i];
                        i++;
                    }
                    i--;
                    s=done;
                    goto label;
            break; // will never  be achieved
    /*       case inID:
             while (isalnum(text[i],loc))
             {
                 myCharContainer=myCharContainer+text[i];
                 i++;
             }
             break;
                 case inNum:break;
*/
          case done:
                 container.push_back(myCharContainer);
                 s=start;
           break;
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

void MainWindow::on_pushButton_2_clicked()
{

    std::locale loc;
      QString str="17k76ad2";
      for (int i = 0; i < str.size(); ++i)
      {
        /* code */
        if (str[i].isDigit())
        {
             ui->textBrowser->setText("tmam");
        }
        else ui->textBrowser->setText("msh tmam");
      }

}
