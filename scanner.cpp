#include "scanner.h"
using namespace std;
Scanner::Scanner()
{

    table["if"]="reserve word";
    table["then"]="reserved word";
    table["end"]="reserved word";
    table["until"]="reserved word";
    table["write"]="reserved word";
    table["else"]="reserved word";
    table["repeat"]="reserved word";
    table["read"]="reserved word";
    table["+"]="plus";
    table["-"]="minus";
    table["*"]="multiple";
    table["/"]="divide";
    table[";"]="SEMI";
}

QString Scanner::separateTextToLines (QString wholeText)
    {
    state s=start;
    locale loc;
    QString myCharContainer="";
    QString container[100];
    int count = 0; // counter for containr index


       for (int i = 0 ;i < wholeText.size();i++){
          switch (s) {
             case start:
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
                    case inID:break;
                    case inNum:break;
             case inAssign:
                    if (wholeText[i]=='=') { myCharContainer= myCharContainer+(wholeText[i]); s=done;}
                    break;
             case done:
                    container[count]=myCharContainer;
                    count ++;
              break;
             }
         }
    }

