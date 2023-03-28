#include "GerenciadorDeBotoes.h"
#include "Botao.h"
#include "gl_canvas2d.h"

GerenciadorDeBotoes::GerenciadorDeBotoes(int numTotal, int numLinha, int esqX, int topY, int altura, int largura, int largTela, int altTela)
{
    this->numTotal = numTotal;
    botoes = new Botao*[numTotal];
    for(int i = 0; i < numTotal; i++)
    {
        botoes[i] = new Botao(esqX + i * 50 + i * largura, topY, largura, altura, i);
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
