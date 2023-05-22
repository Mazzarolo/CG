#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include <vector>
#include "Scene.h"
#include "../Lib/gl_canvas2d.h"
#include "../Objects/Player.h"
#include "../Objects/Background.h"
#include "../Tools/Input.h"
#include "../Objects/Bitmap.h"

using namespace std;

class GameScene : public Scene, public Clock
{
private:
    Player* player;
    Background* background;

public:
    GameScene(int screenWidth, int screenHeight);

    ~GameScene();

    void render();

private:
    void onKeyboardUp();

};


#endif // GAMESCENE_H_INCLUDED
