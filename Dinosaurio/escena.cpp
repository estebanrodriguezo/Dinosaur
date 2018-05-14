#include "escena.h"
#include "ui_escena.h"
#include <QPen>
#include <iostream>
#include<QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
using namespace std;


Escena::Escena(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Escena)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/imagenes/fondoDino.png")));

    scene->setSceneRect(0,-120,400,200);



    QLine linebottom(scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());
    QLine linetop(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y());
    QLine lineder(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y());
    QLine lineizq(scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());

    scene->addLine(linetop);
    scene->addLine(linebottom);
    scene->addLine(lineder);
    scene->addLine(lineizq);

    elipse = scene->addEllipse(10,-98,20,20);
//    QPixmap pixmap;
//    pixmap.load(":/pokebola.png");
//    pixmap->drawPixmap(boundingRect(),pixmap,pixmap.rect());

    //setPixmap(QPixmap(":/imagenes/dino.png"));
    timer = new QTimer();


    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    timer->start(50);

    count =0;

    rect = scene->addRect(200,-98,10,20);
    desp =  6;
    rect->setPos(70,10);
    saltando = false;
}

Escena::~Escena()
{
    delete ui;
}
int i =0;
void Escena::actualizar()
{
    QPointF POS = QPointF(rect->pos());

    if (rect->pos().x()  < -180){
        rect->setPos(70,10);
    }
    else {
        rect->setPos(rect->pos().x()-desp,10);
    }


    if (saltando) {
        elipse->setPos(10,float(count)*8);
        count++;
    }

    if (count == 10){
        saltando = false;
        elipse->setPos(10,10);
        count = 0;
    }

    if (rect->collidesWithItem(elipse)) {
        i++;
        if(i>=10){
            cout << "Perdiste" << endl;
            timer->stop();   }

    }

}



void Escena::keyPressEvent( QKeyEvent* event )
{
    if( event->key() == Qt::Key_Space )
    {
        saltando = true;
    }
}

