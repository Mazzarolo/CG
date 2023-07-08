#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Lib/gl_canvas2d.h"
#include "Objects/EngineV2D.h"
#include "Objects/Engine3D.h"
#include "Objects/Cube.h"
#include "Objects/Cylinder.h"
#include "Tools/Clock.h"

int screenWidth = 500, screenHeight = 500;
EngineV2D *engine;
Engine3D *engine3D;
Clock *timer;
bool is3D = false;

void render()
{
   timer->tic();
   if(is3D)
      engine3D->render();
   else
      engine->render();
}

void keyboard(int key)
{
   if(key == 32)
      is3D = !is3D;
}

void keyboardUp(int key)
{
   printf("\nLiberou: %d", key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   engine->onMouse(button, state, wheel, direction, x, y);
   engine3D->onMouse(button, state, wheel, direction, x, y);
}

int main(void)
{
   timer = new Clock();
   engine = new EngineV2D(screenWidth, screenHeight);
   engine3D = new Engine3D(screenWidth, screenHeight);

   CV::init(&screenWidth, &screenHeight, "Trabalho 4");
   CV::run();
}
