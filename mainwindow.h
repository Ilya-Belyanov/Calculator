#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include <QtGui>
#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    Calculator calc;
private slots:
    void digits();
    void set_digits(QString text);
    void on_pushButton_point_clicked();
    void set_operations_plusminus();
    void set_operations_proc();
    void on_pushButton_AC_clicked();
    void on_pushButton_eq_clicked();
    void math_op();
    void set_math_op(QString text);
    bool checkMax();
};

#endif // MAINWINDOW_H
