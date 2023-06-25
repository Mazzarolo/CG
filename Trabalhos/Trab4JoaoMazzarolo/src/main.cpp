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
   manivela->rotate(timer->getDeltaTime() * 5);
   biela->render();
   biela->move(manivela->getUpFaceCenter() - biela->getCenter());
   pistao->move(biela->getUpFaceCenter() - pistao->getCenter());
   while(biela->getUpFaceCenter().x < manivela->getCenter().x - 1 || biela->getUpFaceCenter().x > manivela->getCenter().x + 1 || biela->getUpFaceCenter().y < manivela->getCenter().y)
   {
      if(biela->getCenter().x < manivela->getCenter().x)
      {
         //printf("\nRotacionando para a direita");
         biela->rotate(-0.1);
      }
      else
      {
         //printf("\nRotacionando para a esquerda");
         biela->rotate(0.1);
      }
   }
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
                            Vector2(30, 250),
                            Vector2(70, 250),
                            Vector2(85, 50),
                            Vector2(100, 50),
                            Vector2(100, 15),
                            Vector2(70, 0),
                            Vector2(30, 0),
                            Vector2(0, 15)});

   manivela->translate(Vector2(screenWidth / 2, screenHeight / 3));

   CV::init(&screenWidth, &screenHeight, "Trabalho 4");
   CV::run();
}
