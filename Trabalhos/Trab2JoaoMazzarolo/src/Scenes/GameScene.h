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
    GameScene(int screenWidth, int screenHeight);

    ~GameScene();

    void reset();

    void render();

private:
    void onKeyboardUp();

    void endGame();

};


#endif // GAMESCENE_H_INCLUDED
