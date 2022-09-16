#ifndef NOTE_H
#define NOTE_H

#include <QDate>
#include <QJsonObject>
#include <QString>



class Note
{
public:
    Note(const QJsonObject & js);
    Note(const QString & nm, const QDate & dl, int pr);
    QJsonObject getJsonObject();
    QString toString();
private:
    QString name;
    QDate deadline;
    int progress;
};

#endif // NOTE_H
