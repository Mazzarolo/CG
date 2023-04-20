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
    //Construtor do painel de labels
    PainelLabels(int screenWidth, int screenHeight, float decY, float decAltura);

    //Desenha o painel de labels e seu scroll
    void desenhar(int screenWidth, int screenHeight, GerenciadorDeFiguras* figuras);

    //trata as verificações de mouse do painel de labels
    void verificarMouse(int mx, int my, int button, int state);
};

#endif // PAINELLABELS_H_INCLUDED
