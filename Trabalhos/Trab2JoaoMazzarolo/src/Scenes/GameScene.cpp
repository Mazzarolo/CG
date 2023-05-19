#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    player = new Player(screenWidth, screenHeight);
    background = new Background(screenWidth, screenHeight);
}

void GameScene::render()
{
    background->render();
    player->render();
    background->moveY(player->getY(), screenHeight);
    if(background->checkCollision(player->getPosition()))
    {
        printf("oi\n");
    }
}