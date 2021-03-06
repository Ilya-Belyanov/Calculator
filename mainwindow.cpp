#include "mainwindow.h"
#include "ui_mainwindow.h"

QString lastNumber = "0";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(set_operations_plusminus()));
    connect(ui->pushButton_proc, SIGNAL(clicked()), this, SLOT(set_operations_proc()));
    connect(ui->pushButton_devide, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_op()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(math_op()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::math_op()
{
    QPushButton *button = (QPushButton *)sender();
    set_math_op(button->text());

}

void MainWindow::set_math_op(QString text){
    if (checkMax() || lastNumber.size() >= 15){
        QString all = ui->result->text();
        if(isdigit(QString(all).toStdString()[all.size()-1])){
            all.append(text);
            lastNumber ="";
        }
        ui->result->setText(all);
    }
}


void MainWindow::set_operations_plusminus(){
    QString all = ui->result->text();
    double newLast;
    if(lastNumber.size() != 0 && lastNumber != "0"){
        if(lastNumber == '-'){
            all.remove(all.size()-1,1);
            lastNumber = "";
            if(all.size()==0){
                all = "0";
                lastNumber = "0";
            }
        }
        else{
            newLast = (lastNumber).toDouble() *-1;
            all.replace(all.size()-lastNumber.size(), lastNumber.size(), QString::number(newLast, 'g', 15));
            lastNumber = QString::number(newLast, 'g', 15);
        }
    }

    else{
        if(lastNumber == "0"){
            all.remove(all.size()-1,1);
            lastNumber = "";}
        all.push_back('-');
        lastNumber.push_back('-');


    }

    ui->result->setText(all);
}

void MainWindow::set_operations_proc(){
    QString all = ui->result->text();
    double newLast;
    if(lastNumber.size() != 0 && lastNumber != '-'){
        newLast = (lastNumber).toDouble() *0.01;
        all.replace(all.size()-lastNumber.size(), lastNumber.size(), QString::number(newLast, 'g', 15));
        lastNumber = QString::number(newLast, 'g', 15);
    }
    ui->result->setText(all);
}

void MainWindow::digits()
{
    QPushButton *button = (QPushButton *)sender();
    set_digits(button->text());
}

void MainWindow::set_digits(QString text){
    if (checkMax()){
        QString all;
        all = ui->result->text();
        if(lastNumber == "0"){
            all.replace(all.size()-1, 1, text);
            lastNumber = "";
        }
        else
            all.push_back(text);
        ui->result->setText(all);
        lastNumber.push_back(all[all.size()-1]);
    }
}


void MainWindow::on_pushButton_point_clicked()
{   if(checkMax()){
        if(!(lastNumber.contains('.')) && lastNumber.size() != 0 && lastNumber[lastNumber.size()-1] != "-"){
                ui->result->setText(ui->result->text()+".");
                lastNumber.push_back('.');
            }
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->result->setText("0");
    lastNumber = "0";

}

void MainWindow::on_pushButton_eq_clicked()
{
    QString all = ui->result->text();
    all = calc.calcAll(all);
    ui->result->setText(all);
    lastNumber = all;
}

bool MainWindow::checkMax(){
    if((ui->result->text()).size() > 30 || lastNumber.size() >= 15)
        return false;
    return true;

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete)
        on_pushButton_AC_clicked();

    if(event->key() == Qt::Key_Control){
        set_operations_plusminus();}

    if(event->key() == Qt::Key_Alt){
        set_operations_proc();}

    if(event->key() == Qt::Key_Slash){
        QString text = "/";
        set_math_op(text);}

    if(event->key() == Qt::Key_7 ){
        QString text = "7";
        set_digits(text);}

    if(event->key() == Qt::Key_8 ){
        QString text = "8";
        set_digits(text);}

    if(event->key() == Qt::Key_9 ){
        QString text = "9";
        set_digits(text);}

    if(event->key() == Qt::Key_4){
        QString text = "4";
        set_digits(text);}

    if(event->key() == Qt::Key_5 ){
        QString text = "5";
        set_digits(text);}

    if(event->key() == Qt::Key_6 ){
        QString text = "6";
        set_digits(text);}

    if(event->key() == Qt::Key_1 ){
        QString text = "1";
        set_digits(text);}

    if(event->key() == Qt::Key_2  ){
        QString text = "2";
        set_digits(text);}

    if(event->key() == Qt::Key_3 ){
        QString text = "3";
        set_digits(text);}

    if(event->key() == Qt::Key_0){
        QString text = "0";
        set_digits(text);}

    if(event->key() == Qt::Key_Period )
        on_pushButton_point_clicked();

    if(event->key() == Qt::Key_Asterisk){
        QString text = "x";
        set_math_op(text);}

    if(event->key() == Qt::Key_Minus){
        QString text = "-";
        set_math_op(text);}

    if(event->key() == Qt::Key_Plus){
        QString text = "+";
        set_math_op(text);}

    if(event->key() == Qt::Key_Enter)
        on_pushButton_eq_clicked();

}

