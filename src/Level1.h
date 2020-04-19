//
// Created by Théo on 17/04/2020.
//

#ifndef PROJETQT_LEVEL1_H
#define PROJETQT_LEVEL1_H

#include <iostream>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>

#include "Player.h"
#include "Wall.h"
#include "Ground.h"
#include "Flammes.h"
#include "FinalFlag.h"

class Level1 : public QGraphicsScene {
Q_OBJECT

private :
    QPixmap background;
    Player* player;
    QTimer* time;

public:
    Level1();
    void drawBackground(QPainter* painter, const QRectF& rect);

    Player* getPlayer(){return this->player ;};

public slots :
    void keyPressEvent(QKeyEvent* event);
};


#endif //PROJETQT_LEVEL1_H