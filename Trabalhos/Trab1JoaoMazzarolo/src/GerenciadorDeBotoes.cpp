// Implementação da classe do Gerenciador de Botoes

#include "GerenciadorDeBotoes.h"
#include "gl_canvas2d.h"

GerenciadorDeBotoes::GerenciadorDeBotoes(int numTotal, float percentAlt, float percentY, float percentEspaco, int largTela, int altTela)
{
    this->numTotal = numTotal;
    this->percentEspaco = percentEspaco;
    this->percentY = percentY;
    this->percentAlt = percentAlt;

    botoes = new Botao*[numTotal];

    int espaco = (percentEspaco / 100) * largTela;
    int largura = (largTela - (numTotal + 1) * espaco) / numTotal;
    int altura = (percentAlt / 100) * altTela;

    for(int i = 0; i < numTotal; i++)
    {
        botoes[i] = new Botao(espaco + i * espaco + i * largura, (percentY / 100) * altTela, largura, altura, i);
        botoes[i]->colorir(0, 14);
    }
}

GerenciadorDeBotoes::GerenciadorDeBotoes(int numTotal, int x, int y, int larg, int alt, char** textos)
{
    this->numTotal = numTotal;

    botoes = new Botao*[numTotal];

    for(int i = 0; i < numTotal; i++)
    {
        botoes[i] = new Botao(x, y + alt * i, larg, alt, textos[i], i);
        botoes[i]->colorir(0, 14);
    }
}

void GerenciadorDeBotoes::posicionarResponsivo(int largTela, int altTela)
{
    int espaco = (percentEspaco / 100) * largTela;
    int largura = (largTela - (numTotal + 1) * espaco) / numTotal;
    int altura = (percentAlt / 100) * altTela;

    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->setBotaoConfig(espaco + i * espaco + i * largura, (percentY / 100) * altTela, largura, altura);
    }
}

void GerenciadorDeBotoes::desenharBotoes(int largTela, int altTela)
{
    posicionarResponsivo(largTela, altTela);

    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->desenhar();
    }
}

void GerenciadorDeBotoes::desenharBotoes()
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->desenhar();
    }
}

int GerenciadorDeBotoes::verificarClick(int mx, int my, int button, int state)
{
    int clicked = -1;
    for(int i = 0; i < numTotal; i++)
    {
        if(botoes[i]->click(mx, my, button, state))
        {
            clicked = i;
        }
    }
    return clicked;
}

void GerenciadorDeBotoes::atribuirFiguras(int* nLados, int* cor)
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->atribuirFigura(nLados[i], 3.14 / 4, cor[i]);
    }
}

void GerenciadorDeBotoes::colorirBotoes(int* cor)
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->colorir(0, cor[i]);
    }
}

void GerenciadorDeBotoes::colorirBotoes(int cor)
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->colorir(0, cor);
    }
}

void GerenciadorDeBotoes::colorirFiguras(int cor)
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->colorirFigura(cor);
    }
}

Figura* GerenciadorDeBotoes::getFigura(int id)
{
    return botoes[id]->getFigura();
}

void GerenciadorDeBotoes::posicionar(int x, int y)
{
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i]->posicionar(x, y + botoes[i]->getAltura() * i);
    }
}

bool GerenciadorDeBotoes::onBotoes(int mx, int my)
{
    if(mx > botoes[0]->getX() && mx < botoes[0]->getX() + botoes[0]->getLargura() && my > botoes[0]->getY()
       && my < botoes[numTotal - 1]->getY() + botoes[numTotal - 1]->getAltura())
        return true;
    else
        return false;
}
