//
// Created by Théo on 17/04/2020.
//

#ifndef PROJETQT_FINALFLAG_H
#define PROJETQT_FINALFLAG_H

//un objet qui va servir d'arrvier et qui va fermer la fenetre quand il est en contact avec le joueur et va afficher la fenetre de victoire
#include <QtWidgets/QGraphicsItem>

class FinalFlag : public QObject , public QGraphicsPixmapItem{
Q_OBJECT
private:
    QString description;
public:
    FinalFlag(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }

};


#endif //PROJETQT_FINALFLAG_H
