#include "Botao.h"
#include "gl_canvas2d.h"

Botao::Botao(float x, float y, float largura, float altura, char *label, int id)
{
    this->altura  = altura;
    this->largura = largura;
    this->x = x;
    this->y = y;
    this->id = id;
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
    escrito = false;
}

void Botao::desenhar()
{
    CV::color(corBotao);
    CV::rectFill(x, y, x + largura, y + altura);
    CV::color(corTexto);
    if(escrito)
        CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro.
}

bool Botao::click(int mx, int my, int button,  int state)
{
    if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) && !button && state == 1)
    {
        return true;
    }
    return false;
}

void Botao::colorir(int corTexto, int corBotao)
{
    this->corTexto = corTexto;
    this->corBotao = corBotao;
}
