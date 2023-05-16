// Atividade de rotação, translação e escalamento de quadrados:
// Precione 1 para rotacionar o quadrado do centro, e 2 para aumentar a escala do quadrado do canto inferior direito

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "Bola.h"
#include "Relogio.h"
#include "Botao.h"

#define LADOSQUADRADO 4

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
float vx[] = {-50, 50, 50, -50}, vy[] = {-50, -50, 50, 50}; // Passando os pontos de um quadrado centrado na origem para ser o quadrado original
float rx[] = {-50, 50, 50, -50}, ry[] = {-50, -50, 50, 50}; // Criando os vetores que vão ser usados na rotação
float ex[] = {-50, 50, 50, -50}, ey[] = {-50, -50, 50, 50}; // Criando os vetores que vão ser usados na escala
double theta = 3.1415 / 2;

void rotateFigure(double theta)
{
    for(int i = 0; i < LADOSQUADRADO; i++)
    {
        rx[i] = vx[i] * cos(theta) - vy[i] * sin(theta);
        ry[i] = vx[i] * sin(theta) + vy[i] * cos(theta);
    }
}

void scaleFigure(float scale)
{
    for(int i = 0; i < LADOSQUADRADO; i++)
    {
        ex[i] = ex[i] * scale;
        ey[i] = ey[i] * scale;
    }
}

// Função translada o quadrado para o valor de x e y escolhido, e o desenha
void drawSquare(int x, int y, int color, float *vX, float *vY)
{
    CV::translate(x, y);
    CV::color(color);
    CV::polygonFill(vX, vY, LADOSQUADRADO);
    CV::translate(0, 0);
}

void drawAxis()
{
    CV::color(0, 0, 0);
    CV::line(0, screenHeight / 2, screenWidth, screenHeight / 2);
    CV::line(screenWidth / 2, 0, screenWidth /2, screenHeight);
}

void render()
{
    drawAxis();
    drawSquare(100, 100, 2, vx, vy);                            //desenha o quadrado original centrado na posição (100, 100)
    drawSquare(screenWidth / 2, screenHeight / 2, 3, rx, ry);   //desenha o quadrado rotacionado centrado na posição central da tela
    drawSquare(700, 500, 4, ex, ey);                            //desenha o quadrado escalado centrado na posição (700, 500);
    //drawCenteredSquare();
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
   //precione 1 para rotacionar o quadrado
   if(key == 49)
   {
        theta += 3.1415 / 8;
        rotateFigure(theta);
   }
   //precione 2 para aumentar o quadrado
   else if(key == 50)
   {
        scaleFigure(1.2);
   }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

   //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "Rotacionar Poligono");
   CV::run();
}
