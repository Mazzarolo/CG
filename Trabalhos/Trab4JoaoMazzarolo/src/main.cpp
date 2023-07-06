#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Lib/gl_canvas2d.h"
#include "Objects/EngineV2D.h"
#include "Objects/Cube.h"
#include "Objects/Cylinder.h"
#include "Tools/Clock.h"

int screenWidth = 500, screenHeight = 500;
Vector2 manivelaPos = Vector2(screenWidth / 2, screenHeight / 2);
Vector2 pistao1Pos = Vector2(screenWidth / 2, screenHeight / 2);
Vector2 pistao2Pos = Vector2(screenWidth / 2, screenHeight / 2);
float ang = 0;
EngineV2D *engine;
Cube *cube;
Cylinder *cylinder;
Clock *timer;

void render()
{
   timer->tic();
   engine->render();
   /*
   //engine->render();
   CV::color(0, 0, 0);
   //desenhe as linhas de um plano 3d com as funções existentes
   CV::translate(screenWidth / 2, screenHeight / 2);
   //cube->render();
   cylinder->render();
   */
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
   cylinder = new Cylinder(1, 1, 2);
   cylinder->translateCylinder(Point(1, -1, 0));
   engine = new EngineV2D(screenWidth, screenHeight);
   timer = new Clock();

   CV::init(&screenWidth, &screenHeight, "Trabalho 4");
   CV::run();
}
