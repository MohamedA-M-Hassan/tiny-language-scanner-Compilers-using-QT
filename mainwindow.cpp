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
    token["if"]     ="reserved word";
    token["then"]   ="reserved word";
    token["end"]    ="reserved word";
    token["until"]  ="reserved word";
    token["write"]  ="reserved word";
    token["else"]   ="reserved word";
    token["repeat"] ="reserved word";
    token["read"]   ="reserved word";
    //token["+"]      ="plus";
    //token["-"]      ="minus";
    //token["*"]      ="multiple";
    //token["/"]      ="divide";
    //token[";"]      ="SEMI";
    token[":="]     ="ASSIGN";

    enum state{start,inComment,inID,inNum,inAssign,done};
    state s=start;

    QString myCharContainer="";
    QVector <QString>container;
    QMap <QString,QString>outputToken;
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
                 // alphapitic
                 else if (text[i].isLetter())
                 {
                     myCharContainer=myCharContainer+text[i];
                     s=inID;
                 }
                 //  numbers
                 else if (text[i].isDigit())
                 {
                    myCharContainer=myCharContainer+text[i];
                    s=inNum;
                 }
                 else if (text[i]=='+') {
                    outputToken["+"]="PLUS";
                 }
                 else if (text[i]=='-') {
                    outputToken["-"]="MINUS";
                 }
                 else if (text[i]=='/') {
                    outputToken["/"]="DIVIDE";
                 }
                 else if (text[i]=='*') {
                    outputToken["*"]="MULTIPLE";
                 }
                 else if (text[i]==';') {
                    outputToken[";"]="SEMI";
                 }
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
                    outputToken[myCharContainer]="Number";
                    s=start;
                    //goto label;
                     break;
           case inID:
                     while (text[i].isLetter()||text[i].isDigit())
                     {
                         myCharContainer=myCharContainer+text[i];
                         i++;
                     }
                     i--;
                     s=done;
                    goto label;
            break;

          case done:
                 container.push_back(myCharContainer);
                 s=start;
           break;
          }
      }

        // to get the Reserved word and the Identefier
      for(QVector<QString>::iterator vec = container.begin(); vec != container.end(); vec++) {
          for (QMap<QString,QString>::iterator mp=token.begin();mp!=token.end(); mp++) {
              if (vec ==mp.key() )
              {
                  outputToken[mp.key()]=mp.value();
                  break;
              }
              else outputToken[*vec]="IDENTEFIER";
           }
      }

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
