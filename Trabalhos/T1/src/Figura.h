#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
    int x, y, raio, numLados;
    int r, g, b;

public:
    Figura(int x, int y, int raio, int numLados);
    void pintarFigura(int r, int g, int b);
    void desenhaFigura();
    void moveFigura(int x, int y);
};

#endif // FIGURA_H
