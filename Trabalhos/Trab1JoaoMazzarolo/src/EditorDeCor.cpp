//Implementação da classe de um editor de cores

#include "EditorDeCor.h"

EditorDeCor::EditorDeCor(int x, int y, int largura, int altura)
{
    this->x = x;
    this->y = y;
    this->largura = largura;
    this->altura = altura;
    visivel = true;
    sliders[0] = new Slider(x + largura * 0.05, y + altura * 0.15, 100, 15, 10, 2, 1);
    sliders[1] = new Slider(x + largura * 0.05, y + altura * 0.45, 100, 15, 10, 3, 1);
    sliders[2] = new Slider(x + largura * 0.05, y + altura * 0.75, 100, 15, 10, 4, 1);
}

void EditorDeCor::desenhar()
{
    CV::color(0.3, 0.3, 0.3);
    CV::rectFill(x, y, x + largura, y + altura);
    for(int i = 0; i < 3; i++)
    {
        sliders[i]->desenhar();
    }
    CV::color(sliders[0]->porcentagem(), sliders[1]->porcentagem(), sliders[2]->porcentagem());
    CV::rectFill(x + 120, y + 15, x + largura - 10, y + altura - 10);
}

void EditorDeCor::verificarMouse(int mx, int my, int button, int state)
{
    for(int i = 0; i < 3; i++)
    {
        sliders[i]->arrastar(mx, my, button, state);
    }
}

void EditorDeCor::colorirFigura(Figura* fig)
{
    fig->colorir(sliders[0]->porcentagem(), sliders[1]->porcentagem(), sliders[2]->porcentagem());
}
