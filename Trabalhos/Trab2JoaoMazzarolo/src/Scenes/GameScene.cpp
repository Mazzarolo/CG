#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    int curvesHeight = screenHeight * 5;
    int startY = screenHeight / 7;
    player = new Player(screenWidth, screenHeight, startY, curvesHeight);
    background = new Background(screenWidth, screenHeight, player->getPosition().y, curvesHeight);
    enemiesManager = new EnemiesManager(screenWidth, screenHeight, background, player);
    powerUpManager = new PowerUpManager(screenWidth, screenHeight, background, player);
    ending = false;
    endTime = 3;
    endTimeCounter = 0;
}

void GameScene::render()
{
    powerUpManager->render(player->isUp());
    if(powerUpManager->getSelecting())
    {
        printFPS(10, 10);
        printStopWatch(10, 25);
        return;
    }
    background->render();
    enemiesManager->render(player->getLevel(), player->isUp());
    player->render();
    background->moveY(player->getY());

    if(enemiesManager->verifyCollision())
    {
        if(player->takeDamage())
        {
            ending = true;
        }
    }

    if(background->checkCollision(player->getPosition(), player->getHitBoxRadius()))
    {
        if(player->takeDamage(screenWidth / 2))
        {
            ending = true;
        }
    }

    if (ending)
    {
        endGame();
    }

    printFPS(10, 10);
    printStopWatch(10, 25);
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
    powerUpManager->reset();
    enemiesManager->reset();
    resetStopWatch();
    ending = false;
    endTime = 3;
    endTimeCounter = 0;
}

void GameScene::endGame()
{
    endTimeCounter += getDeltaTime();
    if(endTimeCounter >= endTime)
    {
        nextScene = 0;
    }
}
