#ifndef SCANNER_R
#define SCANNER_R

#include <QMap>
#include <QString>

class Scanner
{
public:
    Scanner();
    void separateTextToLines(QString wholeText);
private:
    QMap <QString,QString> table;
};

#endif // SCANNER_R

