//Declara��o da classe slider

#ifndef SLIDER_H
#define SLIDER_H

#include "gl_canvas2d.h"

class Slider
{
private:
    int x, y, largura, altura, raio, xBotao;
    int corBarra, corCirculo;
    bool clicked;

public:
    //Construtor de um slider
    Slider(int x, int y, int largura, int altura, int raio, int corBarra, int corCirculo);

    //Desenha o slider
    void desenhar();

    //Move o slider
    void mover(int x, int y);

    //Fun��o que trata o arrastar do slider
    bool arrastar(int mx, int my, int button, int state);

    //Fun��o que retorna a porcentagem do slider entre 0 e 1
    float porcentagem();

    void setZero();
};

#endif // SLIDER_H
