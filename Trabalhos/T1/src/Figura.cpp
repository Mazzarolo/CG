#include "Figura.h"
#include "gl_canvas2d.h"

Figura::Figura(int x, int y, int raio, int numLados)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
    this->numLados = numLados;
    this->r = 255;
    this->g = 255;
    this->b = 255;
}

void Figura::pintarFigura(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Figura::desenhaFigura()
{
    CV::color(r, g, b);
    CV::circleFill(x, y, raio, numLados);
}

void Figura::moveFigura(int x, int y)
{
    this->x = x;
    this->y = y;
}
