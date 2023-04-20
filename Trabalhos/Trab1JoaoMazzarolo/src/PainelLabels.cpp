//Implementação do painel de label que aparecerá na tela

#include "PainelLabels.h"

PainelLabels::PainelLabels(int screenWidth, int screenHeight, float decY, float decAltura)
{
    this->decY = decY;
    this->decAltura = decAltura;
    slider = new Slider(screenWidth / 2 - 50, (decY + decAltura * 0.75) * screenHeight, 100, 15, 10, 13, 0);
    slider->setZero();
    deslocamento = 0;
}


void PainelLabels::desenhar(int screenWidth, int screenHeight, GerenciadorDeFiguras* figuras)
{
    CV::color(0.3, 0.3, 0.3);
    CV::rectFill(0, decY * screenHeight, screenWidth, screenHeight * (decY + decAltura));
    figuras->printLabels(slider->porcentagem() * -100 * figuras->getNumTotal(), decY * screenHeight, 100, decAltura * screenHeight);
    slider->mover(screenWidth / 2 - 50, (decY + decAltura * 0.75) * screenHeight);
    slider->desenhar();
}

void PainelLabels::verificarMouse(int mx, int my, int button, int state)
{
    slider->arrastar(mx, my, button, state);
}
