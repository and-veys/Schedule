#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "nodesdialog.h"

#include <QQuickWidget>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QQuickWidget * widget;
    NodesDialog * dlg;

private slots:
    void printSchedule();
    void saveNode (QString name, QVariant date, int progress);


};
#endif // MAINWINDOW_H
