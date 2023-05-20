#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Input.h"
#include "../Tools/Clock.h"
#include <vector>

using namespace std;

class Player : public Input, public Clock
{
private:
    Vector2 center;
    vector<Vector2> shape;
    int color[3];
    float speed, cameraSpeed;
    bool left, right, top;
    int fixedY, maxY;

public:
    Player(int screenWidth, int screenHeight, int startY);

    void render();

    void onKeyboardDown();

    void onKeyboardUp();

    void move();

    int getY();

    void setX(int x);

    Vector2 getPosition();
};

#endif // PLAYER_H
