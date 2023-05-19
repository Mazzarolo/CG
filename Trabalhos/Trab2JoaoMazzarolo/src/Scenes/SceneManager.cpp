#include "SceneManager.h"

SceneManager::SceneManager(int screenWidth, int screenHeight)
{
    currentScene = new GameScene(screenWidth, screenHeight);
    clock = new Clock();
}

void SceneManager::render()
{
    clock->tic();
    currentScene->render();
}
