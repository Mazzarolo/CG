#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <vector>
#include "Scene.h"
#include "../Lib/gl_canvas2d.h"
#include "../Objects/Player.h"
#include "../Objects/Background.h"

using namespace std;

class GameScene : public Scene
{
private:
    Player* player;
    Background* background;

public:
    GameScene();

    void render();
};


#endif // GAMESCENE_H_INCLUDED
