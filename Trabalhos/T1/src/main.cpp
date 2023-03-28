#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "GerenciadorDeBotoes.h"
#include "Figura.h"
#include "Interface.h"

Figura  *fig = NULL;
GerenciadorDeBotoes *botoesGerais = NULL;

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
   colorirFundo(0.1, 0.1, 0.1);

   DrawMouseScreenCoords();

   fig->mover(screenWidth / 2, screenHeight / 2);
   fig->desenhar();

   botoesGerais->desenharBotoes();
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
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   botoesGerais->verificarClick(x, y, button, state);
}

int main(void)
{
   fig = new Figura(screenWidth / 2, screenHeight / 2, 20, 4, 3.14 / 4);
   botoesGerais = new GerenciadorDeBotoes(4, 4, 20, screenHeight * 3 / 5, screenWidth, screenHeight);

   CV::init(&screenWidth, &screenHeight, "Editor de imagens");
   CV::run();
}
