// Implementação da classe slider

#include "Slider.h"

Slider::Slider(int x, int y, int largura, int altura, int raio, int corBarra, int corCirculo)
{
    this->x = x;
    this->y = y;
    this->largura = largura;
    this->altura = altura;
    this->raio = raio;
    this->corBarra = corBarra;
    this->corCirculo = corCirculo;
    xBotao = x + largura / 2;
    clicked = false;
}

void Slider::desenhar()
{
    CV::color(corBarra);
    CV::rectFill(x, y, x + largura, y + altura);
    CV::color(corCirculo);
    CV::circleFill(xBotao, y + altura / 2, raio, 30);
}

bool Slider::arrastar(int mx, int my, int button, int state)
{
    if(state == 1)
        clicked = false;

    if((sqrt(pow(mx - xBotao, 2) + pow(my - (y + altura / 2), 2))) < raio)
    {
        if(state == 0)
        {
            clicked = true;
            return true;
        }
    }

    if(clicked && mx >= x && mx <= x + largura)
        xBotao = mx;

    return false;
}

float Slider::porcentagem()
{
    return (float)(xBotao - x) / (float) largura;
}
