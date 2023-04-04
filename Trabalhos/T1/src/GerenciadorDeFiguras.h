#ifndef GERENCIADORDEFIGURAS_H
#define GERENCIADORDEFIGURAS_H

#include "Figura.h"
#include <list>
#include <stdlib.h>

using namespace std;

class GerenciadorDeFiguras
{
private:
    list<Figura*> listaFiguras;
    int numTotal;
    Figura* selected;

public:
    GerenciadorDeFiguras();

    void adicionarFigura(Figura* base, int largTela, int altTela);

    void desenharFiguras(int largTela, int altTela);

    void posicionarResponsivo(int largTela, int altTela);

    void verificarClick(int mx, int my, int button, int state, int canvasY);

    void verificarMudancas(int key);

    void colorirSelect(int cor);
};


#endif // GERENCIADORDEFIGURAS_H
