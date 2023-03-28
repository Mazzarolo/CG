#include "Figura.h"
#include "gl_canvas2d.h"

Figura::Figura(int x, int y, int raio, int numLados, float angulo)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
    this->numLados = numLados;
    this->color = 1;
    preenchido = false;
    this->angulo = angulo;
}

void Figura::colorir(int color)
{
    this->color = color;
}

void Figura::desenhar()
{
    CV::color(color);
    if(preenchido)
    {
        CV::circleFill(x, y, angulo, raio, numLados);
    }
    else
    {
        CV::circle(x, y, angulo, raio, numLados);
    }
}

void Figura::mover(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Figura::trocarPreenchimento()
{
    preenchido = !preenchido;
}

void Figura::rotacionar(float angulo)
{
    this->angulo = angulo;
}
