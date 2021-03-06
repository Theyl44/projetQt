#include "GameWindow1.h"

GameWindow1::GameWindow1(QWidget *parent)
        : QMainWindow(parent)
{
    //INIT DU NIVEAU
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl1 = new Level1();

    mainView = new QGraphicsView();
    mainView->setScene(lvl1);
    mainView->scale(0.9,0.9);

    playerView = new QGraphicsView();
    playerView->setScene(lvl1);
    playerView->resize(300, 300);
    playerView->setWindowTitle(lvl1->getPlayer()->getDescription());
    playerView->centerOn(lvl1->getPlayer());
    playerView->show();


    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow1");
    this->setFixedSize(dx, dy);

    //AFFICHAGE DE LA FENETRE : SCORE ET LE TEMPS
    timeprint = new QLabel(mainView);
    timeprint->setFixedSize(100,10);
    timeprint->move(20, 950);

    scoreprint = new QLabel(mainView);
    scoreprint->setFixedSize(100,10);
    scoreprint->move(20, 925);

    //CONNECT
    connect(this->lvl1->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl1->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

    QTimer* time = new QTimer();
    time->start(100);
    //POUR FAIRE AVANCER LE TEMPS QU'ON AFFICHE ON APPEL CETTE FONCTION TOUTES LES 100 ms
    connect(time, SIGNAL(timeout()), this, SLOT(updatetime()));
    //POUR QUE LA FENETRE SOIT CENTREE SUR LE PERSONNAGE
    connect(time, SIGNAL(timeout()), this, SLOT(scrolling()));

}
void GameWindow1::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl1->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow1::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    this->lvl1->writescore(this->time, this->lvl1->getPlayer()->getScore());
    this->playerView->close();
    this->close();
}

void GameWindow1::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->playerView->close();
    this->close();
}
void GameWindow1::scrolling() {
    playerView->centerOn(lvl1->getPlayer());
}


