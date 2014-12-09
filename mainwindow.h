#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <minesweeperbutton.h>
#include <QtGui>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void create_buttons();
    void createClock();

public slots:
    void updateDisplay();

private:
    Ui::MainWindow *ui;

protected:
    QWidget *buttonsWidget;
    QWidget *centralWidget;
    QLabel *timeLabel;
    QTime time;
    QTimer timer;
};

#endif // MAINWINDOW_H
