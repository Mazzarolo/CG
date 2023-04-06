#ifndef GERENCIADORDEBOTOES_H
#define GERENCIADORDEBOTOES_H

#include "Botao.h"

class GerenciadorDeBotoes
{
private:
    int numTotal, numLinhas;
    float percentEspaco, percentY, percentAlt;
    Botao** botoes;

public:
    GerenciadorDeBotoes(int numTotal, float percentAlt, float percentY, float percentEspaco, int largTela, int altTela); // Horizontal e responsivo
    GerenciadorDeBotoes(int numTotal, int x, int y, int larg, int alt, char** textos); // Vertical

    void colorirBotoes(int* cor);
    void colorirBotoes(int cor);

    void colorirFiguras(int cor);

    void desenharBotoes(int largTela, int altTela);
    void desenharBotoes(); //não responsivo

    void atribuirFiguras(int* nLados, int* cor);

    int verificarClick(int mx, int my, int button, int state);

    void posicionarResponsivo(int largTela, int altTela);

    Botao getBotao(int id);

    Figura* getFigura(int id);
};

#endif // GERENCIADORDEBOTOES_H
