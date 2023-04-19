//Declara��o da classe bot�o e seus metodos

#ifndef BOTAO_H
#define BOTAO_H

#include "Figura.h"

class Botao
{
private:
    float altura, largura, x, y;
    int corTexto, corBotao;
    int id;
    char label[100];
    bool escrito, clickDown;
    Figura* fig;

public:
    //Contrutores da classe, um para botoes com texto e um para boto�es sem texto
    Botao(float x, float y, float largura, float altura, char *label, int id);
    Botao(float x, float y, float largura, float altura, int id);

    //Atribui uma figura ao desenho do bot�o
    void atribuirFigura(int nLados, float angulo, int cor);

    //Colore o bot�o e o seu texto(se ouver)
    void colorir(int corTexto, int corBotao);

    //Desenha o bot�o
    void desenhar();

    //Fun��o que trata o click no bot�o
    bool click(int mx, int my, int button, int state);

    //Seta as configura��es do bot�o
    void setBotaoConfig(int x, int y, int largura, int altura);

    //Posiciona o bot�o em uma nova posi��o
    void posicionar(int x, int y);

    //Metodos que retornam atributos de um determinado bot�o
    int getAltura();

    int getLargura();

    int getX();

    int getY();

    Figura* getFigura();

    //Colore a figura correspondente a um bot�o
    void colorirFigura(int cor);
};

#endif
