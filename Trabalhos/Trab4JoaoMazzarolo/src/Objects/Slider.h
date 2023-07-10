//Declaraçã da classe slider

#ifndef SLIDER_H
#define SLIDER_H

#include "../lib/gl_canvas2d.h"

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
    void render();

    //Move o slider
    void move(int x, int y);

    //Funçao que trata o arrastar do slider
    bool onMouse(int mx, int my, int button, int state);

    //Funçao que retorna a porcentagem do slider entre 0 e 1
    float percent();

    //Seta o xBotao para 0, deixando o slider "zerado"
    void setZero();
};

#endif // SLIDER_H