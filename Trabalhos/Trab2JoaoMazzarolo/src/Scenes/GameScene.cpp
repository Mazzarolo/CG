#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    int startY = screenHeight / 7;
    player = new Player(screenWidth, screenHeight, startY);
    background = new Background(screenWidth, screenHeight, player->getPosition().y);
}

void GameScene::render()
{
    background->render();
    player->render();
    background->moveY(player->getY());
    if(background->checkCollision(player->getPosition()))
    {
        player->setX(screenWidth / 2);
    }
}
