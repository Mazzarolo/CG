// Classe para representar um item de power up que pode ser coletado pelo jogador

#ifndef POWER_UP_ITEM_H
#define POWER_UP_ITEM_H

#include "../../Tools/Collisions.h"
#include "../../Lib/gl_canvas2d.h"
#include "../../Tools/Clock.h"
#include "../Animation.h"
#include "../Background.h"

class PowerUpItem : public Clock
{
private:
    static Animation* sprites[2];
    Background* background;    
    Vector2 position;
    float speed;
    int radius;
    bool right;

public:
    // Construtor
    PowerUpItem(int x, int y, float speed, Background* background, bool right);

    // Renderiza o item
    void render(bool isUp, bool isGun);

    // Move o item
    void move(bool isUp);

    // Verifica colisão com o jogador
    bool verifyCollision(Vector2 playerPosition, int playerRadius);

    // Verifica se o item ja pode ser removido
    bool isDead();

    // Define a posição do item
    void setPosition(int x, int y);
};

#endif // POWER_UP_ITEM_H