#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "Botao.h"

int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
float polX[4] = {100, 200, 200, 100}, polY[4] = {100, 100, 200, 200};
float rotX[4] = {100, 200, 200, 100}, rotY[4] = {100, 100, 200, 200};

// Função para rotacionar um ponto em torno de um ângulo
void rotatePoint(float* x, float* y, float angle) {
    float rX = *x * cos(angle) - *y * sin(angle);
    float rY = *x * sin(angle) + *y * cos(angle);
    *x = rX;
    *y = rY;
}

// Função para rotacionar um polígono em torno de seu centro
void rotatePolygon(float* polX, float* polY, float angle) {
    // Encontra o centro do polígono
    float centerX = 0.0;
    float centerY = 0.0;
    for (int i = 0; i < 4; i++) {
        centerX += polX[i];
        centerY += polY[i];
    }
    centerX /= 4;
    centerY /= 4;

    // Rotaciona cada ponto em torno do centro
    for (int i = 0; i < 4; i++) {
        // Translada o ponto para a origem
        polX[i] -= centerX;
        polY[i] -= centerY;

        // Rotaciona o ponto em torno do centro
        rotatePoint(&polX[i], &polY[i], angle);

        // Translada o ponto de volta para a posição original
        polX[i] += centerX;
        polY[i] += centerY;
    }
}

void render()
{
    CV::clear(0, 0, 0);
    CV::color(0, 0, 1);
    CV::polygonFill(polX, polY, 4);
    CV::color(1, 0, 0);
    CV::polygonFill(rotX, rotY, 4);
}

void keyboard(int key)
{
    switch(key)
    {
      case 27:
         exit(0);
      break;
    }
}

void keyboardUp(int key)
{
    printf("\nLiberou: %d" , key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void)
{
    CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    rotatePolygon(rotX, rotY, 3.14 / 4);
    CV::run();
}
