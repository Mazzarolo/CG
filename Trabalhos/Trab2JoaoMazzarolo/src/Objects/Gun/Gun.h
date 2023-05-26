#ifndef GUN_H
#define GUN_H

#include "Projectile.h"
#include "../../Tools/Clock.h"
#include "../../Tools/Collisions.h"
#include <vector>

using namespace std;

class Gun : public Clock
{
private:
    float shootRate, shootRateCounter;
    int limitY, speed;
    Vector2 position;
    vector<Projectile*> projectiles;

public:
    Gun(int x, int y, int screenHeight);

    Gun(int x, int y, int screenHeight, float shootRate, int speed);

    void shoot();

    void render();
    void render(bool down);

    void moveX(int x);

    void move(int x, int y);

    void reset();

    bool verifyCollision(Vector2 position, int radius);

    bool isEmpty();
};

#endif // GUN_H