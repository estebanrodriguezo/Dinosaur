#include "interfaz.h"
#include "ui_interfaz.h"
#include "escena.h"

Interfaz::Interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    timer = new QTimer();

//    QPushButton *button = new QPushButton("&Download", this);
//    button->setGeometry(100,100,300,100);
//    button->show();

//    connect(timer,SIGNAL(timeout()),button,SLOT(hide()));

}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::on_btn_enviar_clicked()
{
    ui->l_texto->setText("Hola mundo");
    timer->start(200);
    this->close();
    Escena escena;
    escena.exec();
}

void Interfaz::on_actionAbout_triggered()
{
}

void Interfaz::cerrar()
{
    ui->l_texto->setText("Cerrando");
}


