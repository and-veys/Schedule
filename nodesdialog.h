#ifndef NODESDIALOG_H
#define NODESDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class NodesDialog;
}

class NodesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NodesDialog(QWidget *parent = nullptr);
    ~NodesDialog();
    void saveNode(QString name, QString date, int progress);
    void showDlg();
private slots:
    void clickButton();

private:
    Ui::NodesDialog *ui;
    QSqlTableModel model;
};

#endif // NODESDIALOG_H
