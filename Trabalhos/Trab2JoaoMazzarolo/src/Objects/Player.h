#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Input.h"
#include <vector>

using namespace std;

class Player : public Input
{
private:
    Vector2 center;
    vector<Vector2> shape;
    int color[3], speed;
    bool left, right, top, down;
    int yScreenCenter;

public:
    Player(int screenWidth, int screenHeight);

    void render();

    void onKeyboardDown();

    void onKeyboardUp();

    void move();

    int getY();
};

#endif // PLAYER_H
