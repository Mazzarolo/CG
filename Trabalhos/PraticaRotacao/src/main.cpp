// Atividade de rota��o, transla��o e escalamento de quadrados:
// Precione 1 para rotacionar o quadrado do centro, e 2 para aumentar a escala do quadrado do canto inferior direito

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"

#include "Bola.h"
#include "Relogio.h"
#include "Botao.h"

#define LADOSQUADRADO 4

using namespace std;

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
float vx[] = {-50, 50, 50, -50}, vy[] = {-50, -50, 50, 50}; // Passando os pontos de um quadrado centrado na origem para ser o quadrado original
float rx[] = {-50, 50, 50, -50}, ry[] = {-50, -50, 50, 50}; // Criando os vetores que v�o ser usados na rota��o
float ex[] = {-50, 50, 50, -50}, ey[] = {-50, -50, 50, 50}; // Criando os vetores que v�o ser usados na escala
double theta = 3.1415 / 2;
float startAng = 0;

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

// Fun��o translada o quadrado para o valor de x e y escolhido, e o desenha
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

void drawSpiral()
{
    CV::translate(screenWidth / 2, screenHeight / 2);
    startAng -= 0.1;
    if(startAng < -3.14 * 2)
        startAng = 0;
    printf("%f\n", startAng);
    float ang = startAng;
    for(float r = 0; r < screenWidth / 2; r += 0.001, ang -= 0.001)
    {
        CV::color(0, 0, 0);
        CV::point(cos(ang) * r, sin(ang) * r);
    }
}

void drawGear()
{
    CV::translate(screenWidth / 2, screenHeight / 2);
    float oldAng = 0;
    float oldR = 100;
    bool up = false;
    for(float ang = 0, r = 200, i = 0; ang < 2 * 3.14; ang += 0.01, i += 1)
    {
        if(!up && (int) i % 31 == 0)
        {
            up = true;
            r += 50;
        }
        else if(up && (int) i % 31 == 0)
        {
            up = false;
            r -= 50;
        }
        CV::color(0, 0, 0);
        CV::line(oldR * cos(oldAng), oldR * sin(oldAng), r * cos(ang), r * sin(ang));
        oldAng = ang;
        oldR = r;
    }
}

void drawBezier(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3)
{
    Vector2 p;
    CV::color(0, 0, 0);
    for(float t = 0; t < 1; t += 0.001)
    {
        p.x = pow(1 - t, 3) * p0.x + 3 * pow(1 - t, 2) * t * p1.x + 3 * (1 - t) * pow(t, 2) * p2.x + pow(t, 3) * p3.x;
        p.y = pow(1 - t, 3) * p0.y + 3 * pow(1 - t, 2) * t * p1.y + 3 * (1 - t) * pow(t, 2) * p2.y + pow(t, 3) * p3.y;
        CV::point(p.x, p.y);
    }
    CV::color(1, 0, 0);
    CV::circleFill(p0.x, p0.y, 3, 10);
    CV::circleFill(p1.x, p1.y, 3, 10);
    CV::circleFill(p2.x, p2.y, 3, 10);
    CV::circleFill(p3.x, p3.y, 3, 10);
}

void drawBSpline(vector<Vector2> points)
{
    Vector2 p;
    CV::color(0, 0, 0);
    for (int i = 0; i < points.size() - 3; i++)
    {
        for (float t = 0; t < 1; t += 0.001)
        {
            p.x = points[i].x * (1 - pow(t, 3)) * 1 / 6 + points[i + 1].x * (3 * pow(t, 3) - 6 * pow(t, 2) + 4) * 1 / 6 + points[i + 2].x * (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) * 1 / 6 + points[i + 3].x * pow(t, 3) * 1 / 6;
            p.y = points[i].y * (1 - pow(t, 3)) * 1 / 6 + points[i + 1].y * (3 * pow(t, 3) - 6 * pow(t, 2) + 4) * 1 / 6 + points[i + 2].y * (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) * 1 / 6 + points[i + 3].y * pow(t, 3) * 1 / 6;
            CV::point(p.x, p.y);
        }
    }
    CV::color(1, 0, 0);
    for (int i = 0; i < points.size(); i++)
    {
        CV::circleFill(points[i].x, points[i].y, 3, 10);
    }
}

void render()
{
    drawAxis();
    //drawSquare(100, 100, 2, vx, vy);                            //desenha o quadrado original centrado na posi��o (100, 100)
    //drawSquare(screenWidth / 2, screenHeight / 2, 3, rx, ry);   //desenha o quadrado rotacionado centrado na posi��o central da tela
    //drawSquare(700, 500, 4, ex, ey);                            //desenha o quadrado escalado centrado na posi��o (700, 500);
    //drawCenteredSquare();
    drawSpiral();
    //drawGear();
    //drawBezier(Vector2(100, 300), Vector2(300, 100), Vector2(500, 500), Vector2(700, 300));
    //vector<Vector2> points = {Vector2(100, 300), Vector2(300, 100), Vector2(500, 500), Vector2(700, 300)};
    //drawBSpline(points);
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
