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
    EditorDeCor(int x, int y, int largura, int altura);

    //Desenha todos os elementos
    void desenhar();

    //Trata todas as verificações do mouse
    void verificarMouse(int mx, int my, int button, int state);

    //Colore uma figura com a cor personalizada
    void colorirFigura(Figura* fig);
};

#endif // EDITORDECOR_H
