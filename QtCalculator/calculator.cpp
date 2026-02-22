#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    //start inputs for number1
    state = 1;

    //list of all buttons
    QList<QPushButton*> digitButtons = {ui->N0, ui->N1, ui->N2, ui->N3, ui->N4, ui->N5, ui->N6, ui->N7, ui->N8, ui->N9};

    //all digits connected to the same handler
    for (QPushButton *button : digitButtons) {
        connect(button, &QPushButton::clicked, this, &Calculator::numberClickedHandler);
    }

    //same thing for operand buttons
    QList<QPushButton*> operandButtons = {ui->add, ui->sub, ui->mul, ui->div};
    for (QPushButton *button : operandButtons) {
        connect(button, &QPushButton::clicked, this, &Calculator::addSubMulDivClickHandler);
    }
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numberClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString name = button->objectName();
    qDebug() << "Button name: " << name;

    QString digit = name.last(1);

    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }
}

void Calculator::clearAndEnterClickHandler()
{

}

void Calculator::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString name = button ->objectName();
    qDebug() << "Button name: " << name;

    //determines which operand is being used
    if (name == "add")
        operand = 0;
    else if (name == "sub")
        operand = 1;
    else if (name == "mul")
        operand = 2;
    else if (name == "div")
        operand = 3;
    //start inputs for number2
    state = 2;
}

void Calculator::resetLineEdits()
{

}
