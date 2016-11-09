#ifndef SCANNER_R
#define SCANNER_R

#include <QMap>
#include <QString>
//#include <algorithm>
#include <string>
#include <locale>
class Scanner
{
public:
    Scanner();
    QString separateTextToLines(QString wholeText);
private:
    QMap <QString,QString> table;
    enum state{start,inComment,inID,inNum,inAssign,done};
};

#endif // SCANNER_R

