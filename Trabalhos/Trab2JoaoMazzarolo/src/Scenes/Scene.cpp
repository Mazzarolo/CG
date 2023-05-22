#include "Scene.h"
#include <stdio.h>

Scene::Scene(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    nextScene = -1;
}

int Scene::getNextScene()
{
    return nextScene;
}

void Scene::setNexScene(int nextScene)
{
    this->nextScene = nextScene;
}