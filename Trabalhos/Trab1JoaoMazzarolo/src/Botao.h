//Declaração da classe botão e seus metodos

#ifndef BOTAO_H
#define BOTAO_H

#include "Figura.h"

class Botao
{
private:
    float altura, largura, x, y;
    int corTexto, corBotao;
    int id;
    char label[100];
    bool escrito, clickDown;
    Figura* fig;

public:
    //Contrutores da classe, um para botoes com texto e um para botoões sem texto
    Botao(float x, float y, float largura, float altura, char *label, int id);
    Botao(float x, float y, float largura, float altura, int id);

    //Atribui uma figura ao desenho do botão
    void atribuirFigura(int nLados, float angulo, int cor);

    //Colore o botão e o seu texto(se ouver)
    void colorir(int corTexto, int corBotao);

    //Desenha o botão
    void desenhar();

    //Função que trata o click no botão
    bool click(int mx, int my, int button, int state);

    //Seta as configurações do botão
    void setBotaoConfig(int x, int y, int largura, int altura);

    //Posiciona o botão em uma nova posição
    void posicionar(int x, int y);

    //Metodos que retornam atributos de um determinado botão
    int getAltura();

    int getLargura();

    int getX();

    int getY();

    Figura* getFigura();

    //Colore a figura correspondente a um botão
    void colorirFigura(int cor);
};

#endif
