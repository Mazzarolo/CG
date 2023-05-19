#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <chrono>
#include "GameScene.h"

using namespace std;

class SceneManager
{
private:
    Scene* currentScene;

public:
    SceneManager(int screenWidth, int screenHeight);

    void render();
};


#endif // SCENEMANAGER_H
