#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

public slots:
    void timeout();

private slots:
    void on_btnStartGame_clicked();
    void on_btnStopGame_clicked();
    void on_btnSwitchPlayer1_clicked();
    void on_btnSwitchPlayer2_clicked();
    void on_btn120sec_clicked();
    void on_btn5min_clicked();

private:
    Ui::MainWindow *ui;

    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;

    void updateProgressBar();
    void setGameInfoText(QString text, short fontSize);
};
#endif // MAINWINDOW_H
