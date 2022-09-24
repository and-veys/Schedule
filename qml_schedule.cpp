#include "note.h"
#include "qml_schedule.h"
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

QML_Schedule::QML_Schedule(QObject *parent) : QObject(parent)
{
    file_name = "data.json";
    readFile();
}

QML_Schedule::QML_Schedule(const QString & file, QObject *parent) : QObject(parent)
{
    file_name = file;
    readFile();
}
QML_Schedule::~QML_Schedule()
{
    writeFile();
}

void QML_Schedule::readFile()
{
    QFile file(file_name);
    QJsonArray array;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
        array = doc.array();
        for(int i=0; i<array.size(); ++i)
            notes.push_back(Note(array[i].toObject()));
    }
}
void QML_Schedule::writeFile()
{
    QFile file(file_name);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QJsonDocument doc;
        QJsonArray array;
        for(int i=0; i<notes.size(); ++i)
            array.append(notes[i].getJsonObject());
        doc.setArray(array);
        file.write(doc.toJson());
        file.close();
    }
}

QList<Note> * QML_Schedule::getListNotes()
{
    return &notes;
}
QList<QString> QML_Schedule::getNotes()
{
    QList<QString> res;
    for(int i=0; i<notes.size(); ++i)
        res.push_back(notes[i].toString());
    return res;
}

void QML_Schedule::setNote(const QString & name, const QList<int> & date, int progress)
{
    notes.push_back(Note(name, QDate(date[2], date[1], date[0]), progress));
}



