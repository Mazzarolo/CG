//Declaração da classe de um editor de cores

#ifndef EDITORDECOR_H
#define EDITORDECOR_H

#include "gl_canvas2d.h"
#include "Slider.h"
#include "Figura.h"

class EditorDeCor
{
private:
    int x, y, altura, largura;
    bool visivel;
    Slider* sliders[3];

public:
    //Contrutor do editor de cor
    EditorDeCor(int screenWidth, int largura, int altura);

    //Desenha todos os elementos
    void desenhar();

    //Move o desenho com base na largura da tela
    void moverResponsivo(int screenWidth);

    //Trata todas as verificações do mouse
    bool verificarMouse(int mx, int my, int button, int state);

    //Verifica se o mouse esta sobre o painel de seleção de cor
    bool onEditor(int mx, int my);

    //Colore uma figura com a cor personalizada
    void colorirFigura(Figura* fig);
};

#endif // EDITORDECOR_H
