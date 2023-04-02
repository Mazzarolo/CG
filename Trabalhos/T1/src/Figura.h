#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
private:
    int x, y, raio, numLados;
    int offSetX, offSetY;
    int color;
    float angulo;
    bool preenchido, clicked;

public:
    Figura(int x, int y, int raio, int numLados, float angulo);

    void colorir(int color);

    void desenhar();

    void mover(int x, int y);

    void trocarPreenchimento();

    void rotacionar(float angulo);

    void setFiguraConfig(int x, int y, int raio);

    Figura* clonarFigura();

    bool click(int mx, int my, int button, int state);

    void arrastar(int mx, int my);
};

#endif // FIGURA_H
