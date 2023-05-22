#ifndef GUN_H
#define GUN_H

#include "Projectile.h"
#include "../../Tools/Clock.h"
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

    void shoot();

    void render();

    void moveX(int x);

    void reset();
};

#endif // GUN_H