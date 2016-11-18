#ifndef TRIAL_H
#define TRIAL_H

#include <QMap>
#include <QString>
class trial
{
public:
    trial();
    void setToken (QMap <QString,QString> t);
    QMap<QString,QString> getToken();
    void scanner (QString text);
private:
    QMap <QString,QString> token;
};

#endif // TRIAL_H
