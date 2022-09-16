#include "note.h"
#include <QDebug>
Note::Note(const QJsonObject &js)
{
    name = js["name"].toString();
    deadline.setDate(js["year"].toInt(), js["month"].toInt(), js["day"].toInt());
    progress = static_cast<int>(js["progress"].toInt());
}

Note::Note(const QString &nm, const QDate &dl, int pr):
    name(nm), deadline(dl), progress(pr)
{

}
QJsonObject Note::getJsonObject()
{
    QJsonObject res;
    int y, m, d;
    deadline.getDate(&y, &m, &d);
    res.insert("name", name);
    res.insert("year", y);
    res.insert("month", m);
    res.insert("day", d);
    res.insert("progress", progress);
    return res;
}

QString Note::toString()
{

   return deadline.toString("dd.MM.yyyy") + " '" + name + "', процесс: " + QString::number(progress);
}
