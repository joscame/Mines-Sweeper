#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "minesweeperbutton.h"
#include "whitespace.h"
#include "minespace.h"
#include "numberspace.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , buttonsWidget(new QWidget)
  , centralWidget(new QWidget)
  , time()
  , timer()
{
    ui->setupUi(this);
    timeLabel = new QLabel("", this);
    create_buttons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_buttons()
{
    QGridLayout *controlsLayout = new QGridLayout;
    for(int i=0; i < 20; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            MineSweeperButton* button = new MineSpace(0, i, j);
            connect(button, SIGNAL(clicked()), button, SLOT(react()));
            controlsLayout->addWidget(button, i, j);
        }
 }
    controlsLayout->setHorizontalSpacing(0);
    controlsLayout->setVerticalSpacing(0);
    buttonsWidget->setLayout(controlsLayout);
    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(buttonsWidget);
    centralLayout->addWidget(timeLabel);
    centralWidget->setLayout(centralLayout);
    createClock();
    setCentralWidget(centralWidget);
}

void MainWindow::createClock()
{
    time.start();
    updateDisplay();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    timer.start(500); // twice per second
}

void MainWindow::updateDisplay()
{
    int secs = time.elapsed() / 1000;
    int mins = (secs / 60) % 60;
    int hours = (secs / 3600);
    secs = secs % 60;
    timeLabel->setText(QString("%1:%2:%3").arg(hours, 2, 10, QLatin1Char('0')).arg(mins, 2, 10, QLatin1Char('0')).arg(secs, 2, 10, QLatin1Char('0')) );
    timeLabel->setAlignment(Qt::AlignBottom);
}
