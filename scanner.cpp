#include "scanner.h"
using namespace std;
Scanner::Scanner()
{}
// set t
/*void Scanner::sett(QMap <QString,QString> t)
{
    t["if"]="reserve word";
    t["then"]="reserved word";
    t["end"]="reserved word";
    t["until"]="reserved word";
    t["write"]="reserved word";
    t["else"]="reserved word";
    t["repeat"]="reserved word";
    t["read"]="reserved word";
    t["+"]="plus";
    t["-"]="minus";
    t["*"]="multiple";
    t["/"]="divide";
    t[";"]="SEMI";
    t[":="]="ASSIGN";
    table =t;

}*/
// RETURN t
QMap<QString,QString> Scanner::getTable()
{
    return table;
}

void Scanner::separateTextToLines (QString wholeText)
    {
    state s=start;
    locale loc;
    QString myCharContainer="";

    QVector <QString>container;
  //  int count = 0; // counter for containr index

       for (int i = 0 ;i < wholeText.size();i++){
          switch (s) {
             case start:
                        myCharContainer="";
                        if (wholeText[i]==':')
                        { myCharContainer = myCharContainer+(wholeText[i]); s=inAssign; }
                        else if (wholeText[i]=='{')
                            s=inComment;
                        else if (isalpha(wholeText[i],loc))
                            s=inID;
                        else if (isdigit(wholeText[i],loc))
                            s=inNum;
                        //else if (wholeText[i]== "\n" || wholeText[i]=="\t" || wholeText[i]==' ')
                          //  s=start;
                        else s= done;
                    break;


              case inComment:
                   while (wholeText[i] !='}')
                   { i++;}
                   s=start;
                   break;
              case inID:
                while (isalnum(wholeText[i],loc))
                {
                    myCharContainer=myCharContainer+wholeText[i];
                    i++;
                }
                break;
                    case inNum:break;
             case inAssign:
                    if (wholeText[i]=='=') { myCharContainer= myCharContainer+(wholeText[i]);}
                     s=done;
                    break;
             case done:
                    container.push_back(myCharContainer);
                    s=start;
              break;
             }
         }
       comparing(container);
}
void Scanner::comparing(QVector<QString>container)
{
    for (QVector<QString>::iterator i = container.begin(); i !=container.end(); i++) {
       for (QMap<QString,QString>::iterator it=getTable().begin();it != getTable().end();it++)
       {
           if (i==it.key())
               printedTable[it.key()]=it.value();
           else printedTable[it.key()]="identigier";
       }
    }

}
QMap<QString,QString> Scanner::returnPrintedTable()
{
    return printedTable;
}
