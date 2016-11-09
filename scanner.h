#ifndef SCANNER_R
#define SCANNER_R

#include <QMap>
#include <QString>
//#include <algorithm>
#include <string>
#include <locale>
#include <iterator>
class Scanner
{
public:
    Scanner();
    void separateTextToLines(QString wholeText);
    void comparing (QString containerOfChar[]);
private:
    QMap <QString,QString> table;
    QMap <QString,QString> printedTable;
    enum state{start,inComment,inID,inNum,inAssign,done};

};

#endif // SCANNER_R

