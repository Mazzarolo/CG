#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <windows.h>
#include <mmsystem.h>
#include "GameScene.h"
#include "MenuScene.h"
#include "../Tools/Clock.h"

using namespace std;

class SceneManager
{
private:
    int screenWidth, screenHeight;
    Scene* currentScene;
    GameScene* gameScene;
    MenuScene* menuScene;
    Clock* clock;

public:
    SceneManager(int screenWidth, int screenHeight);

    void update();
};


#endif // SCENEMANAGER_H
