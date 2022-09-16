#include "mainwindow.h"
#include "qml_schedule.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
     qmlRegisterType<QML_Schedule>("MY.Schedule", 1, 0, "Schedule");
     widget = new QQuickWidget{QUrl{"qrc:/src/main.qml"}};
     setCentralWidget(widget);
     setFixedSize(sizeHint());
     setWindowTitle("Расписание");
}

MainWindow::~MainWindow()
{
}


