#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

};
#endif // MAINWINDOW_H
