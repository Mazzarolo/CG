#include "SceneManager.h"

SceneManager::SceneManager(int screenWidth, int screenHeight)
{
    currentScene = new GameScene(screenWidth, screenHeight);
}

void SceneManager::render()
{
    currentScene->render();
}
