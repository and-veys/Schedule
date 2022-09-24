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

QString Note::toString(){

    QList<QString> params = getParamsString();
    return params[1] + " '" + params[0] + "', процесс: " + params[2];
}

QList<QString> Note::getParamsString()
{
    QList<QString> res;
    res.push_back(name);
    res.push_back(deadline.toString("dd.MM.yyyy"));
    res.push_back(QString::number(progress));
    return res;
}

