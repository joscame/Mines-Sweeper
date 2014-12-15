#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "minesweeperbutton.h"
#include "whitespace.h"
#include "minespace.h"
#include "numberspace.h"
#include "minesweeper.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent, MineSweeper *game) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , buttonsWidget(new QWidget)
  , centralWidget(new QWidget)
  , time()
  , timer()
  , current_player("Player 1")
  , buttons(400)
{
    ui->setupUi(this);
    controlsLayout = new QGridLayout;
    mine_sweeper = game;
    timeLabel = new QLabel("00:00:00", this);
    timeLabel->setFixedSize(50, 15);
    timeLabel->setStyleSheet("QLabel { color: white }");
    playerLabel = new QLabel("Current Player:    Player 1", this);
    playerLabel->setFixedSize(130, 20);
    playerLabel->setStyleSheet("QLabel { color: white }");
    winnerLabel = new QLabel("", this);
    loserLabel = new QLabel("", this);
    start_button = new QPushButton("START          START          START          START          START          START          START          START          START");
    connect(start_button, SIGNAL(clicked()), this, SLOT(show_current_info()));
    acept_button = new QPushButton("ACEPTAR");
    connect(acept_button, SIGNAL(clicked()), this, SLOT(refresh()));
    centralWidget->setStyleSheet("background-image: url(:/background.jpg)");
    create_buttons(mine_sweeper);
    create_central_widget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_buttons(MineSweeper* game)
{
    int contador = 0;
    for(int i=0; i < 20; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            if (game->getSpace(i, j) == -1)
            {
                MineSweeperButton* button = new MineSpace(0, i, j, this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
            else if (game->getSpace(i, j) == 0)
            {
                MineSweeperButton* button = new WhiteSpace(0, i, j, this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
            else
            {
                MineSweeperButton* button = new NumberSpace(0, i, j, game->getSpace(i, j), this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
        }
    }
    controlsLayout->setHorizontalSpacing(0);
    controlsLayout->setVerticalSpacing(0);
    buttonsWidget->setLayout(controlsLayout);
    //QVBoxLayout *centralLayout = new QVBoxLayout;
}

void MainWindow::create_central_widget()
{
    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(buttonsWidget, 0, 0);
    centralLayout->addWidget(timeLabel, 1, 0);
    centralLayout->addWidget(start_button, 5, 0);
    centralLayout->addWidget(playerLabel, 3, 0);
    centralLayout->addWidget(winnerLabel, 6, 0);
    centralLayout->addWidget(loserLabel, 7, 0);
    centralLayout->addWidget(acept_button, 4, 0);
    show_current_info();
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::show_current_info()
{
    this->setVisible(false);
    if (!show_info)
    {
        timeLabel->setVisible(false);
        playerLabel->setVisible(false);
        winnerLabel->setVisible(false);
        loserLabel->setVisible(false);
        acept_button->setVisible(false);
        start_button->setVisible(true);
        buttonsWidget->setEnabled(false);
        show_info = ! show_info;
    }
    else
    {
        timeLabel->setVisible(true);
        playerLabel->setVisible(true);
        start_button->setVisible(false);
        buttonsWidget->setEnabled(true);
        createClock();
        show_info = ! show_info;
    }
    this->setVisible(true);
}

void MainWindow::createClock()
{
    time.start();
    updateDisplay();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    timer.start(500); // twice per second
}

void MainWindow::change_Labels()
{
    if (current_player.compare("Player 2") == 0)
    {
        playerLabel->setText("Current Player:    Player 1");
        current_player = "Player 1";
    }
    else
    {
        playerLabel->setText("Current Player:    Player 2");
        current_player = "Player 2";
    }
    createClock();
}

void MainWindow::updateDisplay()
{
    int secs = time.elapsed() / 1000;
    int mins = (secs / 60) % 60;
    int hours = (secs / 3600);
    secs = secs % 60;
    if (secs >= 10)
        timeLabel->setStyleSheet("QLabel { color: red }");
    if (secs == 20)
        begin_new_one();
    timeLabel->setText(QString("%1:%2:%3").arg(hours, 2, 10, QLatin1Char('0')).arg(mins, 2, 10, QLatin1Char('0')).arg(secs, 2, 10, QLatin1Char('0')) );
    timeLabel->setAlignment(Qt::AlignBottom);
}

void MainWindow::refresh()
{
    this->setVisible(false);
    int contador = 0;

    for(int i= 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            controlsLayout->removeWidget(buttons[contador]);
            ++contador;
        }
    }
    contador = 0;

    for(int i=0; i < 20; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            if (mine_sweeper->getSpace(i, j) == -1)
            {
                MineSweeperButton* button = new MineSpace(0, i, j, this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
            else if (mine_sweeper->getSpace(i, j) == 0)
            {
                MineSweeperButton* button = new WhiteSpace(0, i, j, this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
            else
            {
                MineSweeperButton* button = new NumberSpace(0, i, j, mine_sweeper->getSpace(i, j), this);
                connect(button, SIGNAL(clicked()), button, SLOT(react()));
                controlsLayout->addWidget(button, i, j);
                buttons[contador] = button;
                ++contador;
            }
        }
    }
    show_current_info();
    this->setVisible(true);
}

bool MainWindow::turn_switch()
{
    change_Labels();
    return true;
}

bool MainWindow::begin_new_one()
{
    if (current_player.compare("Player 2") == 0)
    {
        winnerLabel->setText("Felicidades Player 1 has sobrevivido!!");
        loserLabel->setText("Player 2 ....sentimos tu pérdida...");
        current_player = "Player 1";
    }
    else
    {
        winnerLabel->setText("Felicidades Player 2 has sobrevivido!!");
        loserLabel->setText("Player 1 ....sentimos tu pérdida...");
    }
    winnerLabel->setStyleSheet("QLabel { color: white }");
    loserLabel->setStyleSheet("QLabel { color: red }");
    timeLabel->setVisible(false);
    playerLabel->setVisible(false);
    winnerLabel->setVisible(true);
    loserLabel->setVisible(true);
    acept_button->setVisible(true);
    buttonsWidget->setEnabled(false);

    return true;
}


