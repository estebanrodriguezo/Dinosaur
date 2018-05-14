#ifndef ESCENA_H
#define ESCENA_H

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QPainter>
namespace Ui {
class Escena;
}

class Escena : public QDialog,public QGraphicsPixmapItem,public QPixmap, public QPainter
{
    Q_OBJECT

public:
    explicit Escena(QDialog *parent = 0);
    ~Escena();
    QGraphicsScene* scene;
    QTimer* timer;
    QGraphicsRectItem* rect;
    QGraphicsEllipseItem* elipse;
    int desp;
    bool saltando;
    int count;

private:
    Ui::Escena *ui;

private slots:
    void actualizar();
    void keyPressEvent( QKeyEvent* event );
    };
#endif // ESCENA_H
