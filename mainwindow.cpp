#include "mainwindow.h"
//#include "qml_schedule.h"
#include <QQuickItem>
#include <QDebug>
#include <QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
     //qmlRegisterType<QML_Schedule>("MY.Schedule", 1, 0, "Schedule");
     widget = new QQuickWidget{QUrl{"qrc:/src/main.qml"}};
     setCentralWidget(widget);
     setFixedSize(sizeHint());
     setWindowTitle("Расписание");

     auto root = widget->rootObject();
     if (root) {
         auto button_print = root->findChild<QObject*>("button_print");
         if (button_print) {
             connect(button_print, SIGNAL(printSchedule()), this, SLOT(printSchedule()));
         }
         auto button_save = root->findChild<QObject*>("button_save");
         if (button_save) {
             connect(button_save, SIGNAL(saveNode(QString, QVariant, int)), this, SLOT(saveNode(QString, QVariant, int)));
         }
     }

     dlg = new NodesDialog();
}

MainWindow::~MainWindow()
{
    delete dlg;
}

void MainWindow::printSchedule()
{
    dlg->showDlg();
}

void MainWindow::saveNode(QString name, QVariant date, int progress)
{
    QList <QVariant> q = date.toList();
    QDate dt(q[2].toInt(),  q[1].toInt(),  q[0].toInt());
    dlg->saveNode(name, dt.toString("yyyy-MM-dd"), progress);
}


