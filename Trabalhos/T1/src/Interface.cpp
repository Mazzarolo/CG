#include "Interface.h"

#include "gl_canvas2d.h"

void colorirFundo(float r, float g, float b)
{
    CV::clear(r, g, b);
}

void criarBotoesGerais(GerenciadorDeBotoes** botoesGerais, int screenWidth, int screenHeight)
{
    *botoesGerais = new GerenciadorDeBotoes(4, 10, 80, 5, screenWidth, screenHeight);

    int nLados[4] = {3, 4, 6, 30};
    int cor[4] = {3, 4, 6, 7};

    (*botoesGerais)->atribuirFiguras(nLados, cor);
}
