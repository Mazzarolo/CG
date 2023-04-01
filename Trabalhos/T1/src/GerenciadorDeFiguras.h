#ifndef GERENCIADORDEFIGURAS_H
#define GERENCIADORDEFIGURAS_H

#include "Figura.h"
#include <list>

using namespace std;

class GerenciadorDeFiguras
{
private:
    list<Figura> listaFiguras;
    int numTotal;

public:
    GerenciadorDeFiguras();
    desenharFiguras(int largTela, int altTela);
};


#endif // GERENCIADORDEFIGURAS_H
