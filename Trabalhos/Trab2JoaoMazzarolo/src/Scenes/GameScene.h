// Classe que representa a cena do jogo

#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <vector>
#include "Scene.h"
#include "../Lib/gl_canvas2d.h"
#include "../Objects/Player.h"
#include "../Objects/Background.h"
#include "../Tools/Input.h"
#include "../Objects/Bitmap.h"
#include "../Objects/Enemy/EnemiesManager.h"
#include "../Objects/PowerUp/PowerUpManager.h"

using namespace std;

class GameScene : public Scene
{
private:
    Player* player;
    Background* background;
    EnemiesManager* enemiesManager;
    PowerUpManager* powerUpManager;
    bool ending, paused;
    float endTime, endTimeCounter;

public:
    // Construtor
    GameScene(int screenWidth, int screenHeight);

    // Destrutor
    ~GameScene();

    // Método que reseta a cena
    void reset();

    // Método que renderiza a cena
    void render();

    // Método que retorna o score do jogador
    int getScore();
private:
    // Função de callback para o evento de soltar uma tecla
    void onKeyboardUp();

    // Função para setar o fim da cena
    void endGame();
};


#endif // GAMESCENE_H_INCLUDED
