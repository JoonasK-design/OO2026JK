#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushCount_clicked();

    void on_pushReset_clicked();

    void on_pushCalculator_clicked();

private:
    Ui::MainWindow *ui;
    //Added a separate window for the calculator
    Calculator *calculatorWindow;
};
#endif // MAINWINDOW_H
