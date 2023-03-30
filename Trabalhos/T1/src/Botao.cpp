#include "Botao.h"
#include "gl_canvas2d.h"

Botao::Botao(float x, float y, float largura, float altura, char *label, int id)
{
    this->altura  = altura;
    this->largura = largura;
    this->x = x;
    this->y = y;
    this->id = id;
    fig = NULL;
    strcpy(this->label, label);
    escrito = true;
}

Botao::Botao(float x, float y, float largura, float altura, int id)
{
    this->altura  = altura;
    this->largura = largura;
    this->x = x;
    this->y = y;
    this->id = id;
    fig = NULL;
    escrito = false;
}

void Botao::desenhar()
{
    if(fig && clickDown)
        CV::color(0.8, 0.8, 0.8);
    else
        CV::color(corBotao);
    CV::rectFill(x, y, x + largura, y + altura);
    CV::color(corTexto);
    if(escrito)
        CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro
    else if(fig)
        fig->desenhar();
}

bool Botao::click(int mx, int my, int button,  int state)
{
    if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) && !button)
    {
        if(state == 0)
            clickDown = true;
        else if(state == 1 && clickDown)
        {
            clickDown = false;
            return true;
        }
    }

    if (state == 1)
        clickDown = false;

    return false;
}

void Botao::colorir(int corTexto, int corBotao)
{
    this->corTexto = corTexto;
    this->corBotao = corBotao;
}

void Botao::setBotaoConfig(int x, int y, int largura, int altura)
{
    this->altura  = altura;
    this->largura = largura;
    this->x = x;
    this->y = y;
    if(fig)
    {
        int raio = altura / 4;
        if(altura > largura)
            raio = largura / 4;
        fig->setFiguraConfig(x + (largura / 2), y + (altura / 2), raio);
    }
}

void Botao::atribuirFigura(int nLados, float angulo, int cor)
{
    fig = new Figura(x + (largura / 2), y + (altura / 2), altura / 4, nLados, angulo);
    fig->trocarPreenchimento();
    fig->colorir(cor);
}

void Botao::colorirFigura(int cor)
{
    fig->colorir(cor);
}
