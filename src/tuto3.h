//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_TUTO3_H
#define PROJETQT_TUTO3_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>
//MEME CHOSE QUE POUR LE TUTO DE LA PAGE 1 ET 2
class tuto3 : public QMainWindow {
Q_OBJECT

public:
    tuto3(QWidget *parent = nullptr);
    QDesktopWidget dw;

public slots:
    void pressMainMenu();
    void pressPrec();
};


#endif //PROJETQT_TUTO3_H
