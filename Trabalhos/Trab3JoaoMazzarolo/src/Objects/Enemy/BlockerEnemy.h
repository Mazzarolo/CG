// Classe do do tipo de inimigo que fica limitado pelas curvas de bezier.

#ifndef BLOCKER_ENEMY_H
#define BLOCKER_ENEMY_H

#include "Enemy.h"
#include "../Background.h"

class BlockerEnemy : public Enemy
{
private:
    Background* background;
    bool right;

public:
    // Construtor padrão.
    BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Background* background, bool right, int life);

    virtual ~BlockerEnemy() { };

    // Move o inimigo.
    void move(bool accelerating);
};

#endif // BLOCKER_ENEMY_H