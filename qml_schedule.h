#ifndef QML_SCHEDULE_H
#define QML_SCHEDULE_H

#include "note.h"
#include <QObject>

class QML_Schedule : public QObject
{
    Q_OBJECT
public:
    QML_Schedule(QObject *parent = nullptr);
    QML_Schedule(const QString & file, QObject *parent = nullptr);
    virtual ~QML_Schedule();
    Q_INVOKABLE void setNote (const QString & name, const QList<int> & date, int progress);
    Q_INVOKABLE QList<QString> getNotes();

private:
    QString file_name;
    QList<Note> notes;
    void readFile();
    void writeFile();

public:
    QList<Note> * getListNotes();

};

#endif // QML_SCHEDULE_H
