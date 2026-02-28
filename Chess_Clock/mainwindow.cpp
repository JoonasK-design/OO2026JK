#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0), player2Time(0), currentPlayer(1), gameTime(0), pQTimer(new QTimer(this))
{
    ui->setupUi(this);
    //connect QTimer signal to timeout() slot
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
    //set initial gameinfo
    setGameInfoText("Select playtime and press start game!", 16);
    //disable start game button
    ui->btnStartGame->setEnabled(false);
    ui->btnSwitchPlayer1->setEnabled(false);
    ui->btnSwitchPlayer2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    //Decrease active player time by 1 sec
    if (currentPlayer == 1) {
        player1Time--;
    } else {
        player2Time--;
    }
    //If player runs out of time
    if (player1Time <= 0 || player2Time <= 0) {
        pQTimer->stop();
        if (player1Time <=0) {
            setGameInfoText("Player 2 WON!!", 16);
        } else {
            setGameInfoText("Player 1 WON!!", 16);
        }
        return;
    }
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    int p1Progress;
    int p2Progress;

    //remaining time as a percentage
    if (gameTime > 0) {
        p1Progress = (player1Time * 100) / gameTime;
    } else {
        p1Progress = 0;
    }
    if (gameTime > 0) {
        p2Progress = (player2Time * 100) / gameTime;
    } else {
        p2Progress = 0;
    }
    //update progress bar
    ui->progressBarPlayer1->setValue(p1Progress);
    ui->progressBarPlayer2->setValue(p2Progress);
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    //set text
    ui->labelGameInfo->setText(text);

    QFont font = ui->labelGameInfo->font(); //get font object
    font.setPointSize(fontSize);            //modify
    ui->labelGameInfo->setFont(font);       //set font back
}

void MainWindow::on_btnStartGame_clicked()
{
    currentPlayer = 1;
    pQTimer->start(1000); //1 sec
    setGameInfoText("Game ongoing", 16);
    //disable start & timer buttons
    ui->btnStartGame->setEnabled(false);
    ui->btn120sec->setEnabled(false);
    ui->btn5min->setEnabled(false);
    //enable switch for player 1 only
    ui->btnSwitchPlayer1->setEnabled(true);
    ui->btnSwitchPlayer2->setEnabled(false);
}


void MainWindow::on_btnStopGame_clicked()
{
    pQTimer->stop();
    //reset variables
    currentPlayer = 1;
    gameTime = 0;
    player1Time = 0;
    player2Time = 0;
    updateProgressBar();
    setGameInfoText("Select playtime and press start game!", 16);
    //disable buttons
    ui->btnStartGame->setEnabled(false);
    ui->btnSwitchPlayer1->setEnabled(false);
    ui->btnSwitchPlayer2->setEnabled(false);
    //enable timer buttons
    ui->btn120sec->setEnabled(true);
    ui->btn5min->setEnabled(true);
}


void MainWindow::on_btnSwitchPlayer1_clicked()
{
    //switch to player 2
    currentPlayer = 2;
    ui->btnSwitchPlayer1->setEnabled(false);
    ui->btnSwitchPlayer2->setEnabled(true);
}


void MainWindow::on_btnSwitchPlayer2_clicked()
{
    //switch to player 1
    currentPlayer = 1;
    ui->btnSwitchPlayer1->setEnabled(true);
    ui->btnSwitchPlayer2->setEnabled(false);
}


void MainWindow::on_btn120sec_clicked()
{
    gameTime = 120;
    player1Time = 120;
    player2Time = 120;
    updateProgressBar();
    setGameInfoText("Ready to play", 16);
    //allow user to click start game
    ui->btnStartGame->setEnabled(true);
}


void MainWindow::on_btn5min_clicked()
{
    gameTime = 300;
    player1Time = 300;
    player2Time = 300;
    updateProgressBar();
    setGameInfoText("Ready to play", 16);
    //allow user to click start game
    ui->btnStartGame->setEnabled(true);
}
