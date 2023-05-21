#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    int curvesHeight = screenHeight * 2;
    int startY = screenHeight / 7;
    player = new Player(screenWidth, screenHeight, startY, curvesHeight);
    background = new Background(screenWidth, screenHeight, player->getPosition().y, curvesHeight);
    bmp = new Bitmap();
    bmp->load("Trab2JoaoMazzarolo\\src\\Images\\Test.bmp");
}

void GameScene::render()
{
    background->render();
    player->render();
    background->moveY(player->getY());
    if(background->checkCollision(player->getPosition(), player->getHitBoxRadius()))
    {
        player->setX(screenWidth / 2);
    }
}
