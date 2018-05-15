#include "interfaz.h"
#include "ui_interfaz.h"
#include "escena.h"

Interfaz::Interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    timer = new QTimer();
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::on_btn_enviar_clicked()
{
    timer->start(200);
    this->close();
    Escena escena;
    escena.exec();
}

void Interfaz::cerrar()
{
    ui->l_texto->setText("Cerrando");
}


