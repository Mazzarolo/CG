#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "GerenciadorDeBotoes.h"
#include "GerenciadorDeFiguras.h"
#include "Figura.h"
#include "Interface.h"

FILE *arq;
Figura  *fig = NULL;
Botao *botaoSalvar = NULL;
GerenciadorDeFiguras *figuras = NULL;
GerenciadorDeBotoes *botoesGerais = NULL;
GerenciadorDeBotoes *cores = NULL;
GerenciadorDeBotoes *opcoes = NULL;
bool visivel = false;

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //variaveis globais do mouse para poder exibir dentro da render().

void DrawMouseScreenCoords()
{
    char str[100];
    CV::color(1, 1, 1);
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    CV::text(10,300, str);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
    CV::text(10,320, str);
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa função com poucas linhas de codigo.
void render()
{
   colorirFundo(0.5, 0.5, 0.5);

   //DrawMouseScreenCoords();

   fig->mover(screenWidth / 2, screenHeight / 2);
   fig->desenhar();

   figuras->desenharFiguras(screenWidth, screenHeight);

   CV::color(0.1, 0.1, 0.1);
   CV::rectFill(0, 0.75 * screenHeight, screenWidth, screenHeight);
   botoesGerais->desenharBotoes(screenWidth, screenHeight);
   cores->desenharBotoes(screenWidth, screenHeight);
   botaoSalvar->setBotaoConfig(screenWidth * 5 / 100, screenHeight * 5 / 100, screenWidth * 12 / 100, screenHeight * 7 / 100);
   botaoSalvar->desenhar();
   if(visivel)
      opcoes->desenharBotoes();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d" , key);
   if( key < 200 )
   {
      opcao = key;
   }

   switch(key)
   {
      case 27:
	     exit(0);
	  break;
   }

   figuras->verificarMudancasTeclado(key);
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
   figuras->verificarSoltarTeclado(key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   int figuraAdicionada = botoesGerais->verificarClick(x, y, button, state);

   if(figuraAdicionada != -1)
   {
        figuras->adicionarFigura(botoesGerais->getFigura(figuraAdicionada), screenWidth, screenHeight);
   }

   int corSelect = cores->verificarClick(x, y, button, state);

   if (corSelect != -1)
   {
       botoesGerais->colorirFiguras(corSelect);
       figuras->colorirSelect(corSelect);
   }

   if(botaoSalvar->click(x, y, button, state))
   {
       figuras->salvarFiguras(&arq);
   }

   Figura* selecionada = figuras->getSelected();

   if(button == 2 && y < 0.75 * screenHeight && selecionada)
   {
       visivel = true;
       opcoes->posicionar(x, y);
   }

   if(visivel && selecionada)
   {
       int op = opcoes->verificarClick(x, y, button, state);
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
           }
           visivel = false;
       }
   }

   if(button == 0 && state == 1)
      visivel = false;
   if(!opcoes->onBotoes(x, y) || !visivel)
      figuras->verificarClick(x, y, button, state, 0.75 * screenHeight);
   figuras->verificarMudancasMouse(wheel, direction);
}

int main(void)
{
   fig = new Figura(screenWidth / 2, screenHeight / 2, 20, 4, 3.14 / 4);
   criarBotoesGerais(&botoesGerais, screenWidth, screenHeight);
   cores = new GerenciadorDeBotoes(14, 2, 93, 5, screenWidth, screenHeight);
   char* textos[3] = {"Trocar Preenchimento", "Enviar para frente", "Enviar para tras"};
   opcoes = new GerenciadorDeBotoes(3, 50, 50, 250, 30, textos);
   figuras = new GerenciadorDeFiguras();
   botaoSalvar = new Botao(screenWidth * 5 / 100, screenHeight * 5 / 100, screenWidth * 12 / 100, screenHeight * 7 / 100, "Salvar", 0);
   botaoSalvar->colorir(0, 3);

   int cor[14];

   for(int i = 0; i < 14; i++)
      cor[i] = i;

   cores->colorirBotoes(cor);

   figuras->carregarFiguras(&arq);

   CV::init(&screenWidth, &screenHeight, "Editor de imagens");
   CV::run();
}
