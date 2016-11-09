#include "scanner.h"


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



void Scanner::separateTextToLines (QString wholeText)
    {
        for (int i  = 0; i < wholeText.size(); i++) {

        }
    }

