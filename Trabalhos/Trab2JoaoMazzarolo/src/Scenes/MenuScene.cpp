#include "MenuScene.h"

MenuScene::MenuScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
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
    buttons.push_back(new SpriteButton(buttonX, buttonY, [this] {onPlayClick();}, pathToSprites));

    pathToSprites.clear();
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Info\\Button.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Info\\ButtonSelected.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Info\\ButtonClicked.bmp");
    buttons.push_back(new SpriteButton(buttonX, buttonY - 125, [this] {onInfoClick();}, pathToSprites));

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

MenuScene::~MenuScene()
{
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        delete buttons[i];
    }
}

void MenuScene::render()
{
    CV::clear(0, 0, 0.05);
    title->render();
    printFPS(10, 10);
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->render();
    }
}

void MenuScene::onPlayClick()
{
    nextScene = 1;
}

void MenuScene::onInfoClick()
{
    nextScene = 3;
}

void MenuScene::onExitClick()
{
    exit(0);
}

void MenuScene::reset()
{
    nextScene = -1;
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->setActive(true);
    }
}

void MenuScene::setNextScene(int nextScene)
{
    Scene::setNextScene(nextScene);
    for(int i = 0; i < (int) buttons.size(); i++)
    {
        buttons[i]->setActive(false);
    }
}