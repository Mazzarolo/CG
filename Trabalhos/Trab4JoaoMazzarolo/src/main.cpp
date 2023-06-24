#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Lib/gl_canvas2d.h"
#include "Objects/Component2D.h"
#include "Tools/Clock.h"

int screenWidth = 500, screenHeight = 500;
Component2D *pistao;
Component2D *manivela;
Component2D *biela;
Clock *timer;

void render()
{
   timer->tic();
   pistao->render();
   //pistao->rotate(timer->getDeltaTime());
   manivela->render();
   manivela->rotate(timer->getDeltaTime());
   biela->render();
   biela->move(manivela->getUpFaceCenter() - biela->getCenter());
   //biela->rotate(timer->getDeltaTime());
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
   timer = new Clock();

   pistao = new Component2D({Vector2(0, 0),
                             Vector2(0, 100),
                             Vector2(100, 100),
                             Vector2(100, 0)});

   manivela = new Component2D({Vector2(0, 30),
                               Vector2(30, 100),
                               Vector2(70, 100),
                               Vector2(100, 30),
                               Vector2(90, 15),
                               Vector2(70, 0),
                               Vector2(30, 0),
                               Vector2(10, 15)});

   biela = new Component2D({Vector2(0, 50),
                            Vector2(15, 50),
                            Vector2(30, 200),
                            Vector2(70, 200),
                            Vector2(85, 50),
                            Vector2(100, 50),
                            Vector2(100, 15),
                            Vector2(70, 0),
                            Vector2(30, 0),
                            Vector2(0, 15)});

   manivela->translate(Vector2(screenWidth / 2, screenHeight / 4));
   biela->translate(Vector2(screenWidth / 2, manivela->getHeight() + screenHeight / 4));
   pistao->translate(Vector2(screenWidth / 2, biela->getHeight() + manivela->getHeight() + screenHeight / 9));

   CV::init(&screenWidth, &screenHeight, "Trabalho 4");
   CV::run();
}
