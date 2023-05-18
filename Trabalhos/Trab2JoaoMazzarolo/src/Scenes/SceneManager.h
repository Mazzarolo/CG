#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "GameScene.h"

class SceneManager
{
private:
    Scene* currentScene;

public:
    SceneManager(int screenWidth, int screenHeight);

    void render();
};


#endif // SCENEMANAGER_H
