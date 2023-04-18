#ifndef GERENCIADORDEFIGURAS_H
#define GERENCIADORDEFIGURAS_H

#include "Figura.h"
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class GerenciadorDeFiguras
{
private:
    list<Figura*> listaFiguras;
    int numTotal;
    Figura* selected;
    bool ctrl;

public:
    GerenciadorDeFiguras();

    void carregarFiguras(FILE** arq);

    void salvarFiguras(FILE** arq);

    void adicionarFigura(Figura* base, int largTela, int altTela);

    void desenharFiguras(int largTela, int altTela);

    void posicionarResponsivo(int largTela, int altTela);

    void verificarClick(int mx, int my, int button, int state, int canvasY);

    void verificarMudancasTeclado(int key);

    void verificarSoltarTeclado(int key);

    void verificarMudancasMouse(int wheel, int direction);

    void colorirSelect(int cor);

    void enviarFrente();

    void enviarTras();

    Figura* getSelected();
};


#endif // GERENCIADORDEFIGURAS_H
