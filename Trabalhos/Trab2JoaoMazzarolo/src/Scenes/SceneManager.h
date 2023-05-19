#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "GameScene.h"
#include "../Tools/Clock.h"

using namespace std;

class SceneManager
{
private:
    Scene* currentScene;
    Clock* clock;

public:
    SceneManager(int screenWidth, int screenHeight);

    void render();
};


#endif // SCENEMANAGER_H
