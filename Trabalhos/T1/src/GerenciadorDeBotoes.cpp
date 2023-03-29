#include "GerenciadorDeBotoes.h"
#include "Botao.h"
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
        botoes[i]->colorir(0, 2);
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

int GerenciadorDeBotoes::verificarClick(int mx, int my, int button, int state)
{
    for(int i = 0; i < numTotal; i++)
    {
        if(botoes[i]->click(mx, my, button, state))
        {
            printf("\nClickou no %d", i);
            return i;
        }
    }
    return -1;
}
