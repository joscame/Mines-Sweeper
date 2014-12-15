#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <minesweeperbutton.h>
#include <QtGui>
#include <QLabel>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGridLayout>

class MineSweeper;

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, MineSweeper *game = 0);
    ~MainWindow();
    void create_buttons(MineSweeper *game);
    void createClock();
    void change_Labels();
    bool turn_switch();
    bool begin_new_one();
    void create_central_widget();

public slots:
    void show_current_info();
    void updateDisplay();
    void refresh();

private:
    Ui::MainWindow *ui;

protected:
    QWidget *buttonsWidget;
    QWidget *centralWidget;
    QLabel *timeLabel;
    QLabel *playerLabel;
    QLabel *winnerLabel;
    QLabel *loserLabel;
    QTime time;
    QTimer timer;
    QPushButton* start_button;
    QPushButton* acept_button;
    QString current_player;
    MineSweeper* mine_sweeper;
    QVector<MineSweeperButton*> buttons;
    QGridLayout *controlsLayout;
    bool show_info = false;
};

#endif // MAINWINDOW_H
