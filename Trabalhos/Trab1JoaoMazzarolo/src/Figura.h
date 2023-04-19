// Declaração da classe Figura

#ifndef FIGURA_H
#define FIGURA_H

#include <stdlib.h>
#include <stdio.h>

class Figura
{
private:
    int x, y, raio, numLados;
    int offSetX, offSetY;
    int color;
    float angulo;
    bool preenchido, clicked, selected;
    float r, g, b;
    bool corPersonalizada;

public:
    // Construtor da clase figura
    Figura(int x, int y, int raio, int numLados, float angulo);

    // Colore a figura
    void colorir(int color);
    void colorir(float r, float g, float b);

    // desenha a figura
    void desenhar();

    // move a figura para uma nova posição
    void mover(int x, int y);

    // preenche/despeenche a figura
    void trocarPreenchimento();

    // rotaciona uma figura com base em um angulo em radianos
    void rotacionar(float angulo);

    // seta os valores de uma figura para novos passados por parametro
    void setFiguraConfig(int x, int y, int raio);

    // copia uma figura e retorna a nova criada
    Figura* clonarFigura();

    // trata o click em uma figura
    bool click(int mx, int my, int button, int state);

    //trata o arrastar de uma figura
    void arrastar(int mx, int my);

    //seta se a figura está selecionada no momento ou não
    void setSelected();

    // gira a figura com base em um valor que será somado a o angulo atual
    void girar(float angulo);

    // redimenciona a figura somando um valor
    void redimencionar(int diferenca);

    // salva a figura em um arquivo
    void salvar(FILE** arq, int chave);

    // modifica o numero de lados somando o parametro
    void modificarLados(int dif);
};

#endif // FIGURA_H
