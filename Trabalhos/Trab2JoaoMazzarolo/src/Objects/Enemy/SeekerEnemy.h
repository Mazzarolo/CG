// Classe do tipo de inimigo que persegue o jogador.

#ifndef SEEKER_ENEMY_H
#define SEEKER_ENEMY_H

#include "Enemy.h"
#include "../Player.h"

class SeekerEnemy : public Enemy
{
private:
    Player* player;

public:
    // Construtor padrão.
    SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Player* player, int life);

    virtual ~SeekerEnemy() { };

    // Move o inimigo.
    void move(bool accelerating);
};

#endif // SEEKER_ENEMY_H