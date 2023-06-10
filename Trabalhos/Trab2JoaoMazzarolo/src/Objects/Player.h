#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "Gun/Gun.h"
#include "../Tools/Input.h"
#include "../Tools/Clock.h"
#include "Animation.h"
#include <vector>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

class Player : public Input, public Clock
{
private:
    Gun* gun;
    Animation* sprite;
    Animation* coins;
    Animation* explosion;
    Bitmap* hearth;
    Vector2 center;
    Vector2 scorePosition;
    int life, score, scoreMultiplier, scoreChanger, cameraSpeedChanger;
    int hitBoxRadius;
    int color[3];
    float invincibleTime, invincibleTimeCounter, invincibleBlinkTime, invincibleBlinkTimeCounter;
    float scoreTime, scoreTimeCounter;
    float changingTime, changingTimeCounter;
    float speed, cameraSpeed;
    bool left, right, top, shooting;
    int fixedY, maxY;

public:
    Player(int screenWidth, int screenHeight, int startY, int curveHeight);

    virtual ~Player();

    void render();

    void onKeyboardDown();

    void onKeyboardUp();

    void move();

    int getY();

    void setX(int x);

    Vector2 getPosition();

    int getHitBoxRadius();

    int getLevel();

    bool isUp();

    bool takeDamage(int x);
    bool takeDamage();

    void reset(int x);

    Gun* getGun();

    void addScore(int score);

    void powerUpGun();

    int getLife();

private:
    void gunControl();

    void renderStats();

    void renderSprite();

    void verifyChanges();
};

#endif // PLAYER_H
