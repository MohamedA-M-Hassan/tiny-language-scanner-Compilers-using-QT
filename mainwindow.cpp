#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanner.h"

// to insert from file
    #include <QFileDialog>
    #include <QFile>
    #include <QTextStream>
    #include <QMessageBox>

#include <QString>
#include <QMap>
// copy paste to check if num or n

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // hide
    ui->tableWidget->hide();
    ui->label_2->hide();
    ui->pushButton_2->hide();
    ui->textBrowser->hide();
    ui->tableWidget->hide();
   // ui->pushButton_6->hide();
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
                   {
                       myCharContainer= myCharContainer+(text[i]);
                        type="Assignment operator";

                   }
                   else{
                        i--;
                        type="Colon";
                   }
                   s=done;
                   goto label;
                          // or u can use (i--) instead of (goto)
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
                    goto label;
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
    /* //to print in textBrowser not so good
    ui->textBrowser->setText("Symbol       ||    TokenType");// added so when you repeat the use of the button just restart w mtkmlsh 3la el2dyym

    for (QVector< pair <QString,QString> >::iterator it=answer.begin(); it != answer.end(); it++) {
        ui->textBrowser->append(it->first + "       ||    " + it->second);
    }*/
    // to print in a table
    ui->tableWidget->show();
    // ------------
    // to not repeat the data
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    //--------------------------
    ui->label_2->show();

    for (QVector< pair <QString,QString> >::iterator it=answer.begin(); it != answer.end(); it++){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        QTableWidgetItem *newItem1 = new QTableWidgetItem(it->first);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, newItem1);
        QTableWidgetItem *newItem2 = new QTableWidgetItem(it->second);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, newItem2);
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


// trial Button
void MainWindow::on_pushButton_2_clicked()
{
    //ui->tableWidget->setRowCount(0);
    //ui->tableWidget->setColumnCount(0);
    //token type
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    QTableWidgetItem *newItem1 = new QTableWidgetItem("hello");
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, newItem1);
    QTableWidgetItem *newItem2 = new QTableWidgetItem("Boogy");
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, newItem2);
}
// clear button
void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
    ui->textBrowser->clear();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->hide();
    ui->label_2->hide();
}

// insert button
void MainWindow::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/home", tr("code file (*.txt)"));// string has the file link



    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);

    ui->textEdit->setText(in.readAll());

}

