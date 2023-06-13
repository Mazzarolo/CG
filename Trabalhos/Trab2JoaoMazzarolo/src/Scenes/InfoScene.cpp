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
    CV::clear(0, 0, 0.05);
    title->render();
    printInfoText();
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

void InfoScene::printInfoText()
{
    CV::color(1, 1, 1);
    char buffer[100];
    int startY = 100;
    sprintf(buffer, "-> Move your ship with WASD");
    CV::textTitle(50, startY + 300, buffer);
    sprintf(buffer, "-> Shoot with SPACE");
    CV::textTitle(50, startY + 250, buffer);
    sprintf(buffer, "-> Press ESC during gameplay to reset and return to main menu");
    CV::textTitle(50, startY + 200, buffer);
    sprintf(buffer, "-> Get the upgrade boxes, and select the improvement of your ship");
    CV::textTitle(50, startY + 150, buffer);
    sprintf(buffer, "-> Stay alive and destroy foes to get points");
    CV::textTitle(50, startY + 100, buffer);
    sprintf(buffer, "Enjoy!");
}