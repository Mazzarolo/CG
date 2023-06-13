// Classe que representa o gerenciador de cenas

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <windows.h>
#include <mmsystem.h>
#include "GameScene.h"
#include "MenuScene.h"
#include "InfoScene.h"
#include "GameOverScene.h"
#include "../Tools/Clock.h"

using namespace std;

class SceneManager
{
private:
    int screenWidth, screenHeight;
    Scene* currentScene;
    GameScene* gameScene;
    MenuScene* menuScene;
    GameOverScene* gameOverScene;
    InfoScene* infoScene;
    Clock* clock;
    bool menuMusicPlaying;

public:
    // Construtor
    SceneManager(int screenWidth, int screenHeight);

    // Loop principal do jogo, que gerencia e renderiza as cenas
    void update();
};


#endif // SCENEMANAGER_H
