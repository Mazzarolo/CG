#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Lib/gl_canvas2d.h"
#include "Objects/Engine2D.h"
#include "Objects/Cube.h"
#include "Tools/Clock.h"

int screenWidth = 500, screenHeight = 500;
Engine2D *engine;
Cube *cube;
Clock *timer;

void render()
{
   timer->tic();
   //engine->render();
   CV::color(0, 0, 0);
   //desenhe as linhas de um plano 3d com as funções existentes
   CV::translate(screenWidth / 2, screenHeight / 2);
   cube->render();
}

void keyboard(int key)
{

}

void keyboardUp(int key)
{
   printf("\nLiberou: %d", key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{

}

int main(void)
{
   cube = new Cube(Point(0, 0, 0), 100);
   engine = new Engine2D(screenWidth, screenHeight);
   timer = new Clock();

   CV::init(&screenWidth, &screenHeight, "Trabalho 4");
   CV::run();
}
