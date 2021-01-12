#include "calculator.h"


QString Calculator::calcAll(QString all){
    all = deleteUnnecessary(all);
    all = seekDevideMulti(all);
    all = seekMinusPlus(all);
    all = rounding(all);
    return all;
}

QString Calculator::deleteUnnecessary(QString all){
    if(all == "-") return "0";
    while(!isdigit(QString(all).toStdString()[all.size()-1])){
        all.remove(all.size()-1,1);
    }
    return all;
}

QString Calculator::plus(QString firstNum, QString secondNum){
    double res = firstNum.toDouble() + secondNum.toDouble();

    return QString::number(res, 'g', 31);
}

QString Calculator::minus(QString firstNum, QString secondNum){
    double res = firstNum.toDouble() - secondNum.toDouble();

    return QString::number(res, 'g', 31);
}

QString Calculator::multi(QString firstNum, QString secondNum){
    double res = firstNum.toDouble() * secondNum.toDouble();

    return QString::number(res, 'g', 31);
}

QString Calculator::devide(QString firstNum, QString secondNum){
    double res = firstNum.toDouble() / secondNum.toDouble();
    if(secondNum.toDouble() == 0)
        res = 0;

    return QString::number(res, 'g', 31);
}

QString Calculator::doOperation(QString firstNum,QString op, QString secondNum){

    if(op == "+") return plus(firstNum, secondNum);
    else if(op == "-") return minus(firstNum, secondNum);
    else if(op == "/") return devide(firstNum, secondNum);
    else if(op == "x") return multi(firstNum, secondNum);
    return 0;
}

QString Calculator::seekDevideMulti(QString all){
    QRegExp rx_d("([\\-]?\\d+\\.?\\d*)[\\/]([\\-]?\\d+\\.?\\d*)");
    QRegExp rx_multi("([\\-]?\\d+\\.?\\d*)[x]([\\-]?\\d+\\.?\\d*)");
    return countPath(all ,rx_multi, rx_d, "x", "/");

}

QString Calculator::seekMinusPlus(QString all){
    QRegExp rx_m("([\\-]?\\d+\\.?\\d*)[\\-]([\\-]?\\d+\\.?\\d*)");
    QRegExp rx_p("([\\-]?\\d+\\.?\\d*)[\\+]([\\-]?\\d+\\.?\\d*)");
    return countPath(all ,rx_m, rx_p, "-", "+");

}

QString Calculator::countPath(QString all, QRegExp rxOne, QRegExp rxTwo, QString opOne, QString opTwo){
    int id;
    QString res;
    QString firstNum,secondNum;

    while(rxOne.indexIn(all) != -1 || rxTwo.indexIn(all) != -1){
        if(rxTwo.indexIn(all) == -1 || (rxOne.indexIn(all)<rxTwo.indexIn(all) && rxOne.indexIn(all) != -1)){
            firstNum = rxOne.cap(1);
            secondNum = rxOne.cap(2);
            id = rxOne.indexIn(all);
            res = doOperation(firstNum, opOne, secondNum);
        }
        else{
            firstNum = rxTwo.cap(1);
            secondNum = rxTwo.cap(2);
            id = rxTwo.indexIn(all);
            res = doOperation(firstNum, opTwo, secondNum);
        }

        all.replace(id, firstNum.size() + secondNum.size()+1, res);
    }

    return all;
}

QString Calculator::rounding(QString all){
    QRegExp rx_point("([\\-]?\\d+\\.\\d)(\\d)(\\d)");
    if(rx_point.indexIn(all) >= 0){
        QString delta;

        if(rx_point.cap(3).toDouble() >= 5){
           delta = "1";
        }
        else {delta = "0";}

        all = rx_point.cap(1) + plus(rx_point.cap(2), delta);
    }
    if (all.toDouble() == 0) return "0";
    return all;
}
