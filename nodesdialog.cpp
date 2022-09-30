#include "nodesdialog.h"
#include "ui_nodesdialog.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
NodesDialog::NodesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodesDialog),
    model(this, QSqlDatabase::addDatabase("QSQLITE"))
{
    auto db = model.database();
    db.setDatabaseName("./nodes.db");
    if(!db.open()) {
        qDebug() << "Error open DB";
        return;
    }
    QSqlQuery qu(db);
    QString str = "create table if not exists nodes (";
    str += "id integer primary key autoincrement, ";
    str += "date varchar(10), ";
    str += "name varchar(256), ";
    str += "progress integer)";
    if(!qu.exec(str)) {
        qDebug() << "Error create table" << qu.lastError();
    }
    model.setTable("nodes");
    model.setSort(1, Qt::AscendingOrder);

    ui->setupUi(this);
    ui->tableView->setModel(&model);
    ui->tableView->setColumnHidden(0, true);
    connect(ui->pushButton, &QPushButton::clicked, this, &NodesDialog::clickButton);
}

NodesDialog::~NodesDialog()
{
    delete ui;
}

void NodesDialog::saveNode(QString name, QString date, int progress)
{
    auto db = model.database();
    QSqlQuery qu(db);
    QString str = "insert into nodes(date, name, progress) values (";
    str += ("'" + date + "', ");
    str += ("'" + name + "', ");
    str += (QString::number(progress) + ")");
    if(!qu.exec(str)) {
        qDebug() << "Error insert" << qu.lastError();
    }
}

void NodesDialog::showDlg() {
    model.select();
    exec();
}

void NodesDialog::clickButton()
{
     accept();
}
