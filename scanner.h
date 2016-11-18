#ifndef SCANNER_R
#define SCANNER_R

#include <QMap>
#include <QString>
#include <QVector>
//#include <algorithm>

#include <locale>
#include <iterator>
class Scanner
{
public:
    Scanner();
    void setTable (QMap <QString,QString> table);
    QMap <QString,QString>getTable();
    void separateTextToLines(QString wholeText);
    void comparing (QVector<QString>container);
    QMap <QString,QString> returnPrintedTable();
private:
    QMap <QString,QString> table;
    QMap <QString,QString> printedTable;
    enum state{start,inComment,inID,inNum,inAssign,done,identifier};

};

#endif // SCANNER_R

