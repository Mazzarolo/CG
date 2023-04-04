#include "GerenciadorDeFiguras.h"

GerenciadorDeFiguras::GerenciadorDeFiguras()
{
    numTotal = 0;
    selected = NULL;
}

void GerenciadorDeFiguras::adicionarFigura(Figura* base, int largTela, int altTela)
{
    int raio;
    Figura* novaFigura = base->clonarFigura();
    if(largTela > altTela)
        raio = 0.1 * altTela;
    else
        raio = 0.1 * largTela;
    novaFigura->setFiguraConfig(largTela / 2, altTela / 2, raio);
    listaFiguras.push_back(novaFigura);
}

void GerenciadorDeFiguras::desenharFiguras(int largTela, int altTela)
{
    list<Figura*>::iterator fig;
    for (fig = listaFiguras.begin(); fig != listaFiguras.end(); ++fig)
    {
        (*fig)->desenhar();
    }
}

void GerenciadorDeFiguras::posicionarResponsivo(int largTela, int altTela)
{
    // fazer depois
}

void GerenciadorDeFiguras::verificarClick(int mx, int my, int button, int state, int canvasY)
{
    list<Figura*>::reverse_iterator fig;
    for (fig = listaFiguras.rbegin(); fig != listaFiguras.rend(); ++fig)
    {
        if((*fig)->click(mx, my, button, state))
        {
            if(selected)
                selected->setSelected();
            selected = (*fig);
            selected->setSelected();
            return;
        }
    }
    if(button == 0 && state == 0 && my < canvasY)
    {
        if(selected)
            selected->setSelected();
        selected = NULL;
    }
}

void GerenciadorDeFiguras::verificarMudancas(int key)
{
    if(selected)
    {
        switch(key)
        {
            case 200:
                selected->redimencionar(-2);
                break;
            case 201:
                selected->girar(0.1);
                break;
            case 202:
                selected->redimencionar(2);
                break;
            case 203:
                selected->girar(-0.1);
                break;
        }
    }
}
