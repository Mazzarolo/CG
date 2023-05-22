#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    int curvesHeight = screenHeight * 3;
    int startY = screenHeight / 7;
    player = new Player(screenWidth, screenHeight, startY, curvesHeight);
    background = new Background(screenWidth, screenHeight, player->getPosition().y, curvesHeight);
}

void GameScene::render()
{
    background->render();
    player->render();
    background->moveY(player->getY());
    if(background->checkCollision(player->getPosition(), player->getHitBoxRadius()))
    {
        player->setX(screenWidth / 2);
        if(player->takeDamage())
        {
            nextScene = 0;
        }
    }
    printFPS(10, screenHeight - 20);
}

GameScene::~GameScene()
{
    delete player;
    delete background;
}

void GameScene::onKeyboardUp()
{
    switch(getKeyUp())
    {
        case 27:
            nextScene = 0;
            break;
    }
}

void GameScene::reset()
{
    player->reset(screenWidth / 2);
}
