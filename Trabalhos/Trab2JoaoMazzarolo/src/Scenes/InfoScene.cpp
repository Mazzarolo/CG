#include "InfoScene.h"

InfoScene::InfoScene(int screenWidth, int screenHeight) : Scene(screenWidth, screenHeight)
{
    nextScene = -1;
    int buttonX = 3 * screenWidth / 8;
    int buttonY = 6 * screenHeight / 12;

    title = new Bitmap();
    title->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Title.bmp");
    title->setPosition(screenWidth / 2 - title->getWidth() / 2, screenHeight / 2 + 150);

    vector<char*> pathToSprites;

    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\Button.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\ButtonSelected.bmp");
    pathToSprites.push_back((char*)"Trab2JoaoMazzarolo\\src\\Images\\Buttons\\Quit\\ButtonClicked.bmp");
    exitButton = new SpriteButton(buttonX, buttonY - 250, [this] {onExitClick();}, pathToSprites);

    exitButton->setActive(true);
}

InfoScene::~InfoScene()
{
    delete exitButton;
}

void InfoScene::render()
{
    CV::clear(0.1, 0.1, 0.2);
    title->render();
    printFPS(10, 10);
    exitButton->render();
}

void InfoScene::onExitClick()
{
    nextScene = 0;
}

void InfoScene::reset()
{
    nextScene = -1;
    exitButton->setActive(true);
}

void InfoScene::setNextScene(int nextScene)
{
    this->nextScene = nextScene;
    exitButton->setActive(false);
}