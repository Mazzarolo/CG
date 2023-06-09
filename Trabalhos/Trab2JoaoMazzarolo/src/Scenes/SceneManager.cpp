#include "SceneManager.h"

SceneManager::SceneManager(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    gameScene = new GameScene(screenWidth, screenHeight);
    menuScene = new MenuScene(screenWidth, screenHeight);
    currentScene = menuScene;
    clock = new Clock();
}

void SceneManager::update()
{   
    clock->tic();
    currentScene->render();
    int nextScene = currentScene->getNextScene();
    if(nextScene == 0)
    {
        currentScene->setNextScene(-1);
        currentScene = menuScene;
        currentScene->reset();
    }
    else if (nextScene == 1)
    {
        currentScene->setNextScene(-1);
        currentScene = gameScene;
        currentScene->reset();
    }
}
