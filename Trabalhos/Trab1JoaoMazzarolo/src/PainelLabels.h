//Declaração do painel de label que aparecerá na tela

#ifndef PAINELLABELS_H_INCLUDED
#define PAINELLABELS_H_INCLUDED

#include "gl_canvas2d.h"
#include "Slider.h"
#include "GerenciadorDeFiguras.h"

class PainelLabels
{
private:
    float decY, decAltura;
    int deslocamento;
    Slider* slider;
public:
    PainelLabels(int screenWidth, int screenHeight, float decY, float decAltura);

    void desenhar(int screenWidth, int screenHeight, GerenciadorDeFiguras* figuras);

    void verificarMouse(int mx, int my, int button, int state);
};

#endif // PAINELLABELS_H_INCLUDED
