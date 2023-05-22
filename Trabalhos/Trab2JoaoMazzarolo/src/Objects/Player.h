#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "Gun/Gun.h"
#include "../Tools/Input.h"
#include "../Tools/Clock.h"
#include "Animation.h"
#include <vector>

using namespace std;

class Player : public Input, public Clock
{
private:
    Gun* gun;
    Animation* sprite;
    Bitmap* hearth;
    Vector2 center;
    int life;
    int hitBoxRadius;
    int color[3];
    float invincibleTime, invincbleTimeCounter;    
    float speed, cameraSpeed;
    bool left, right, top, shooting;
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

    int getHitBoxRadius();

    bool takeDamage();

    void reset(int x);

private:
    void gunControl();

    void renderHealth();

    void renderSprite();
};

#endif // PLAYER_H
