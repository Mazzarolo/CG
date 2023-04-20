//Implementação da classe figura

#include "Figura.h"
#include "gl_canvas2d.h"
#include "stdio.h"

Figura::Figura(int x, int y, int raio, int numLados, float angulo)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
    this->numLados = numLados;
    this->color = 1;
    preenchido = false;
    this->angulo = angulo;
    clicked = false;
    selected = false;
    corPersonalizada = false;
}

void Figura::colorir(int color)
{
    corPersonalizada = false;
    this->color = color;
}

void Figura::colorir(float r, float g, float b)
{
    corPersonalizada = true;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Figura::desenhar()
{
    if(selected)
    {
        CV::color(rand() % 14);
        if(preenchido)
        {
            CV::circleFill(x, y, angulo, raio + 3, numLados);
        }
        else
        {
            CV::circle(x, y, angulo, raio + 2, numLados);
        }
    }
    if(corPersonalizada)
        CV::color(r, g, b);
    else
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

void Figura::setFiguraConfig(int x, int y, int raio)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
}

Figura* Figura::clonarFigura()
{
    Figura* novaFigura = NULL;
    novaFigura = new Figura(x, y, raio, numLados, angulo);
    novaFigura->corPersonalizada = corPersonalizada;
    if(corPersonalizada)
        novaFigura->colorir(r, g, b);
    else
        novaFigura->colorir(color);
    novaFigura->preenchido = preenchido;
    return novaFigura;
}

bool Figura::click(int mx, int my, int button, int state)
{
    if(state == 1)
        clicked = false;

    if((sqrt(pow(mx - x, 2) + pow(my - y, 2))) < raio)
    {
        if(state == 0)
        {
            clicked = true;
            offSetX = x - mx;
            offSetY = y - my;
            return true;
        }
    }

    if(clicked)
        arrastar(mx, my);

    return false;
}

void Figura::arrastar(int mx, int my)
{
    x = mx + offSetX;
    y = my + offSetY;
}

void Figura::setSelected()
{
    selected = !selected;
}

void Figura::girar(float angulo)
{
    this->angulo += angulo;
}

void Figura::redimencionar(int diferenca)
{
    if(raio + diferenca > 2)
    raio += diferenca;
}

void Figura::salvar(FILE** arq, int chave)
{
    fprintf(*arq, "\n%d %d %d %d %d %f %d ", x + chave, y + chave, raio + chave, numLados + chave, color + chave, angulo + chave, preenchido + chave);
    fprintf(*arq, "%f %f %f %d", r + chave, g + chave, b + chave, corPersonalizada + chave);
}

void Figura::modificarLados(int dif)
{
    if(dif >= 0 || numLados > 3)
        numLados += dif;
}
