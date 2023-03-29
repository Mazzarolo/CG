#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
private:
    int x, y, raio, numLados;
    int color;
    float angulo;
    bool preenchido;

public:
    Figura(int x, int y, int raio, int numLados, float angulo);

    void colorir(int color);

    void desenhar();

    void mover(int x, int y);

    void trocarPreenchimento();

    void rotacionar(float angulo);

    void setFiguraConfig(int x, int y, int raio);
};

#endif // FIGURA_H
