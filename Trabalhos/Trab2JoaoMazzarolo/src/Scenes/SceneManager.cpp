#include "SceneManager.h"

SceneManager::SceneManager(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    gameScene = new GameScene(screenWidth, screenHeight);
    menuScene = new MenuScene(screenWidth, screenHeight);
    gameOverScene = new GameOverScene(screenWidth, screenHeight);
    infoScene = new InfoScene(screenWidth, screenHeight);
    currentScene = menuScene;
    clock = new Clock();
    PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\MenuMusic.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    menuMusicPlaying = true;
}

void SceneManager::update()
{
    clock->tic();
    currentScene->render();
    int nextScene = currentScene->getNextScene();
    if(nextScene == 0)
    {
        if(!menuMusicPlaying)
            PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\MenuMusic.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        menuMusicPlaying = true;
        currentScene->setNextScene(-1);
        currentScene = menuScene;
        currentScene->reset();
    }
    else if (nextScene == 1)
    {
        if(!menuMusicPlaying)
            PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\MenuMusic.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        menuMusicPlaying = false;
        currentScene->setNextScene(-1);
        currentScene = gameScene;
        currentScene->reset();
    }
    else if (nextScene == 2)
    {
        PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\GameOverMusic.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        currentScene->setNextScene(-1);
        currentScene = gameOverScene;
        gameOverScene->reset(gameScene->getScore(), clock->getStopWatch());
    }
    else if (nextScene == 3)
    {
        if(!menuMusicPlaying)
            PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\MenuMusic.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        currentScene->setNextScene(-1);
        currentScene = infoScene;
        infoScene->reset();
    }
}
