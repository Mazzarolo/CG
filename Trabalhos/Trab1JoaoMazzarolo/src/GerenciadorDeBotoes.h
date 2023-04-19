// Declaração da classe do Gerenciador de Botoes

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
    // Contrutores de um gerenciador de botões, um responsivo e um absoluto
    GerenciadorDeBotoes(int numTotal, float percentAlt, float percentY, float percentEspaco, int largTela, int altTela); // Horizontal e responsivo
    GerenciadorDeBotoes(int numTotal, int x, int y, int larg, int alt, char** textos); // Vertical

    // Funções para colorir os botoes, uma com um array de cores e uma com uma unica cor
    void colorirBotoes(int* cor);
    void colorirBotoes(int cor);

    // Função para colorir as figuras dos botoes
    void colorirFiguras(int cor);

    // Desenhas os botoes, de forma responsiva ou absoluta
    void desenharBotoes(int largTela, int altTela);
    void desenharBotoes(); //não responsivo

    // atribui um array de figuras aos botoes
    void atribuirFiguras(int* nLados, int* cor);

    // Trata os clicks nos botoes
    int verificarClick(int mx, int my, int button, int state);

    // Posiciona os botões de forma responsiva
    void posicionarResponsivo(int largTela, int altTela);

    // posiciona os botoes com base nos parametros passados
    void posicionar(int x, int y);

    // Retorna um botão pelo id
    Botao getBotao(int id);

    // Função que verifica se o mouse estã em cima de algum botão
    bool onBotoes(int mx, int my);

    // Retorna a figura de um botão pelo id
    Figura* getFigura(int id);
};

#endif // GERENCIADORDEBOTOES_H
