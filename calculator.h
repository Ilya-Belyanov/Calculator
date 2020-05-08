#include "mainwindow.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H
class Calculator {
    QString deleteUnnecessary(QString all);

    QString plus(QString firstNum, QString secondNum);
    QString minus(QString firstNum, QString secondNum);
    QString devide(QString firstNum, QString secondNum);
    QString multi(QString firstNum, QString secondNum);
    QString doOperation(QString firstNum,QString op, QString secondNum);

    QString seekDevideMulti(QString all);
    QString seekMinusPlus(QString all);
    QString countPath(QString all,QRegExp rx1, QRegExp rx2, QString opOne, QString opTwo);

    QString rounding(QString all);
    public:
        QString calcAll(QString all);


};
#endif // CALCULATOR_H
