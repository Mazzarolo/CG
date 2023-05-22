#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Input.h"
#include "../Tools/Clock.h"
#include "Animation.h"
#include <vector>

using namespace std;

class Player : public Input, public Clock
{
private:
    Animation* sprite;
    Vector2 center;
    int hitBoxRadius;
    int color[3];
    float speed, cameraSpeed;
    bool left, right, top;
    int fixedY, maxY;

public:
    Player(int screenWidth, int screenHeight, int startY, int curveHeight);

    ~Player();

    void render();

    void onKeyboardDown();

    void onKeyboardUp();

    void move();

    int getY();

    void setX(int x);

    Vector2 getPosition();

    vector<Vector2> getShapeAbs();

    int getHitBoxRadius();
};

#endif // PLAYER_H
