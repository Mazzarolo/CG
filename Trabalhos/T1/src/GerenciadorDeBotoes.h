#ifndef GERENCIADORDEBOTOES_H
#define GERENCIADORDEBOTOES_H

#include "Botao.h"

class GerenciadorDeBotoes
{
private:
    int numTotal, numLinha;
    int esqX, topY, altura, largura;
    Botao** botoes;

public:
    GerenciadorDeBotoes(int numTotal, int numLinha, int esqX, int topY, int altura, int largura, int largTela, int altTela);
    void desenharBotoes();
    int verificarClick(int mx, int my, int button, int state);
    Botao getBotao(int id);
};

#endif // GERENCIADORDEBOTOES_H
