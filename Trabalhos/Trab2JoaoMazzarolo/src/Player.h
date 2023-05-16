#ifndef PLAYER_H
#define PLAYER_H

#include "gl_canvas2d.h"
#include <vector>

using namespace std;

class Player
{
private:
    Vector2 center, speed;
    vector<Vector2> shape;
    int color[3], maxSpeed;
    bool moving;
    int yScreenCenter;

public:
    Player(int screenWidth, int screenHeight);

    void render();

    void getKeys(int key);

    void move();

    void brake(int key);

    int getY();
};

#endif // PLAYER_H
