#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <mmsystem.h>

#include "Lib/gl_canvas2d.h"
#include "Scenes/SceneManager.h"
#include "Tools/Input.h"

using namespace std;

int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.

SceneManager* sceneManager = NULL;
Input* input = NULL;

void render()
{
    sceneManager->update();
}

void keyboard(int key)
{
    input->setKeyDown(key);
}

void keyboardUp(int key)
{
    input->setKeyUp(key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    input->setMouse(button, state, wheel, direction, x, y);
}

int main(void)
{
    CV::init(&screenWidth, &screenHeight, "Nave Gamer");

    //PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\Test.wav"), NULL, SND_ASYNC);
    sceneManager = new SceneManager(screenWidth, screenHeight);
    input = new Input();

    CV::run();
}
