// Implementação de algumas funções que estão diretamente conectadas com interface, mas não estão em nem uma classe

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
    int cor[4] = {0, 0, 0, 0};

    (*botoesGerais)->atribuirFiguras(nLados, cor);
}

void verificarOpcoes(int op, Figura* selecionada, GerenciadorDeFiguras* figuras, EditorDeCor* sliders, bool* visivel)
{
    if(op != -1)
       {
           switch(op)
           {
              case 0:
                selecionada->trocarPreenchimento();
                break;
              case 1:
                figuras->enviarFrente();
                break;
              case 2:
                figuras->enviarTras();
                break;
              case 3:
                selecionada->modificarLados(1);
                break;
              case 4:
                selecionada->modificarLados(-1);
                break;
              case 5:
                sliders->colorirFigura(selecionada);
                break;
              case 6:
                figuras->adicionarClone();
                break;
              case 7:
                figuras->excluir();
                break;
           }
           *visivel = false;
       }
}
