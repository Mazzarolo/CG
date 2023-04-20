//Implementação da classe de um editor de cores

#include "EditorDeCor.h"

EditorDeCor::EditorDeCor(int screenWidth, int largura, int altura)
{
    this->x = screenWidth - largura;
    this->y = 0;
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

void EditorDeCor::moverResponsivo(int screenWidth)
{
    x = screenWidth - largura;
    sliders[0]->mover(x + largura * 0.05, y + altura * 0.15);
    sliders[1]->mover(x + largura * 0.05, y + altura * 0.45);
    sliders[2]->mover(x + largura * 0.05, y + altura * 0.75);
}

bool EditorDeCor::verificarMouse(int mx, int my, int button, int state)
{
    bool clicked = false;
    for(int i = 0; i < 3; i++)
    {
        if(sliders[i]->arrastar(mx, my, button, state))
            clicked = true;
    }
    // Verifica se o quadrado de cor foi precionado
    if(mx >= x + 120 && mx <= x + largura - 10 && my >= y + 15 && my <= y + altura - 10 && state == 0)
        clicked = true;
    return clicked;
}

bool EditorDeCor::onEditor(int mx, int my)
{
    if(mx >= x && mx <= x + largura && my >= y && my <= y + altura)
        return true;
    return false;
}

void EditorDeCor::colorirFigura(Figura* fig)
{
    fig->colorir(sliders[0]->porcentagem(), sliders[1]->porcentagem(), sliders[2]->porcentagem());
}
