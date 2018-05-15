#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class Interfaz;
}

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = 0);
    ~Interfaz();
    QTimer* timer;

private slots:
    void on_btn_enviar_clicked();

   // void on_actionAbout_triggered();



    void cerrar();
private:
    Ui::Interfaz *ui;
};

#endif // INTERFAZ_H
