#include "GameOverScene.h"

GameOverScene::GameOverScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    nextScene = -1;
    int buttonX = 3 * screenWidth / 8;
    int buttonY = 6 * screenHeight / 12;

    title = new Bitmap();
    title->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Title.bmp");
    title->setPosition(screenWidth / 2 - title->getWidth() / 2, screenHeight / 2 + 150);

    vector<char*> pathToSprites;

    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Play\\Button.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Play\\ButtonSelected.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Play\\ButtonClicked.bmp");
    buttons.push_back(new SpriteButton(buttonX, buttonY - 125, [this] {onPlayClick();}, pathToSprites));

    pathToSprites.clear();
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\Button.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\ButtonSelected.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\ButtonClicked.bmp");
    buttons.push_back(new SpriteButton(buttonX, buttonY - 250, [this] {onExitClick();}, pathToSprites));

    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->setActive(true);
    }
}

GameOverScene::~GameOverScene()
{
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        delete buttons[i];
    }
}

void GameOverScene::render()
{
    CV::clear(0.1, 0.1, 0.2);
    title->render();
    printFPS(10, 10);
    CV::color(rand() % 14);
    char scoreText[50];
    sprintf(scoreText, "Score: %d", score);
    CV::biggerText(3 * screenWidth / 8, 7 * screenHeight / 12, scoreText);
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->render();
    }
}

void GameOverScene::onPlayClick()
{
    printf("Play clicked\n");
    nextScene = 1;
}

void GameOverScene::onExitClick()
{
    nextScene = 0;
}

void GameOverScene::reset(int score)
{
    nextScene = -1;
    this->score = score;
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->setActive(true);
    }
}

void GameOverScene::setNextScene(int nextScene)
{
    Scene::setNextScene(nextScene);
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->setActive(false);
    }
}