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
    token["if"]     ="IF token";
    token["then"]   ="THEN token";
    token["end"]    ="END token";
    token["until"]  ="UNTIL token";
    token["write"]  ="WRITE token";
    token["else"]   ="ELSE token";
    token["repeat"] ="REPEAT token";
    token["read"]   ="READ token";
    //token["+"]      ="plus";
    //token["-"]      ="minus";
    //token["*"]      ="multiple";
    //token["/"]      ="divide";
    //token[";"]      ="SEMI";
    //token[":="]     ="ASSIGN";

    enum state{start,inComment,inID,inNum,inAssign,done};
    state s=start;

    QString myCharContainer="";
    //QVector <QString>container;
    //QMap <QString,QString>outputToken;

    QVector <pair <QString,QString> > answer;
    QString type;
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
                     answer.push_back({"+","Plus"});
                     //outputToken["+"]="PLUS";
                 }
                 else if (text[i]=='-') {
                     answer.push_back({"-","Minus"});
                     //outputToken["-"]="MINUS";
                 }
                 else if (text[i]=='/') {
                    answer.push_back({"/","Divide"});
                    // outputToken["/"]="DIVIDE";
                 }
                 else if (text[i]=='*') {
                    answer.push_back({"*","Multiple Operator"});
                     //outputToken["*"]="MULTIPLE";
                 }
                 else if (text[i]==';') {
                    answer.push_back({";","SemiColon"});
                     //outputToken[";"]="SEMI";
                 }
                 else if ( text[i]== '.'){
                    answer.push_back({".","DOT"});
                 }
                 else if ( text[i]== '<'){
                    answer.push_back({"<","SmallerThan"});
                 }
                 else if ( text[i]=='>')
                 {
                     answer.push_back({">","GreaterThan"});
                 }
                 break;


           case inAssign:
                   if (text[i]=='=')
                   {    myCharContainer= myCharContainer+(text[i]);}
                    type="Assignment operator";
                    s=done;
                    goto label;      // or u can use (i--) instead of (goto)
                   break;
           case inComment:
                    while (text[i] !='}')
                        { i++;}
                    s=start;
                    break;
           case inNum:
                    while (text[i].isDigit())
                    {
                        myCharContainer=myCharContainer+text[i];
                        i++;
                    }
                    i--;
                    //outputToken[myCharContainer]="Number";
                    type="Number";
                    s=done;
                    //s=start;
                    //goto label;
                     break;
           case inID:
                     while (text[i].isLetter()||text[i].isDigit())
                     {
                         myCharContainer=myCharContainer+text[i];
                         i++;
                     }
                     i--;
                     if (token.find(myCharContainer)!=token.end())
                     {
                         type=token[myCharContainer];
                     }
                     else type="identefier";
                     s=done;
                    goto label;
            break;

          case done:
                 //container.push_back(myCharContainer);
                 answer.push_back({myCharContainer,type});
                 s=start;
           break;
          }
      }

     /*   // to get the Reserved word and the Identefier
      for(QVector<QString>::iterator vec = container.begin(); vec != container.end(); vec++) {
          for (QMap<QString,QString>::iterator mp=token.begin();mp!=token.end(); mp++) {
              if (vec ==mp.key() )
              {
                  outputToken[mp.key()]=mp.value();
                  break;
              }
              else outputToken[*vec]="IDENTEFIER";
           }
      }*/
    for (QVector< pair <QString,QString> >::iterator it=answer.begin(); it != answer.end(); it++) {
        ui->textBrowser->append(it->first + "   ||  " + it->second);
    }
}

void MainWindow::on_textEdit_destroyed()
{
 //   trial = "hi";
}

void MainWindow::on_pushButton_3_clicked()
{
   close();
}



void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
    ui->textBrowser->clear();
}
