#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //initialize calculator
    , calculatorWindow(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushCount_clicked()
{
    //Get value (text) from lineEdit object
    QString currentValue = ui->lineEdit->text();

    //Convert it to int and increase the value by 1
    int intValue = currentValue.toInt();
    intValue++;

    //Convert back
    QString newValue = QString::number(intValue);

    //Add it back to lineEdit
    ui->lineEdit->setText(newValue);
}


void MainWindow::on_pushReset_clicked()
{
    //reset value (text) to zero
    ui->lineEdit->setText("0");
}


void MainWindow::on_pushCalculator_clicked()
{
    if (!calculatorWindow) {    //if it's not open yet
        calculatorWindow = new Calculator();
        calculatorWindow->show();
    } else {                    //if it is open, creates a new one
        calculatorWindow->raise();
        calculatorWindow->activateWindow();
    }
}

