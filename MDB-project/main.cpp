#include "mainwindow.h"
#include "matching.h"

#include <QApplication>

int main(int argc, char** argv)
{
    //Affichage de la fenetre graphique

    QApplication a(argc, argv);
    MainWindow* win = new MainWindow();
    win->show();

    return a.exec();
}
