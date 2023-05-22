#include "MenuScene.h"

MenuScene::MenuScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    nextScene = -1;
    int buttonX = 3 * screenWidth / 8;
    int buttonY = 6 * screenHeight / 12;

    title = new Bitmap();
    title->load("Trab2JoaoMazzarolo\\src\\Images\\Title.bmp");
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
}

MenuScene::~MenuScene()
{
    for(int i = 0; i < buttons.size(); i++)
    {
        delete buttons[i];
    }
}

void MenuScene::render()
{
    CV::clear(0.1, 0.1, 0.2);
    title->render();
    printFPS(10, screenHeight - 20);
    for(int i = 0; i < buttons.size(); i++)
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
    nextScene = 2;
}

void MenuScene::onExitClick()
{
    exit(0);
}