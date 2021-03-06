//
// Created by Théo on 20/04/2020.
//

#ifndef PROJETQT_TIMERWINDOW_H
#define PROJETQT_TIMERWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTextStream>
#include <QDesktopWidget>
#include "MenuWindow.h"
//PANNEAU DES SCORES
class TimerWindow : public QMainWindow {
Q_OBJECT

private:
    QWidget* window;
public:
    TimerWindow(QWidget *parent = nullptr);
    QDesktopWidget dw;

public slots:
    void pressMainMenu();
    void pressReset();
};



#endif //PROJETQT_TIMERWINDOW_H
