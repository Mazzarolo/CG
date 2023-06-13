// Classe base de inimigo, utilizada como classe mãe para criar os inimigos do jogo.

#ifndef ENEMY_H
#define ENEMY_H

#include "../Animation.h"
#include "../Gun/Gun.h"
#include "../../Tools/Clock.h"
#include "../../Lib/gl_canvas2d.h"

class Enemy : public Clock
{
protected:
    static int count;
    Animation* sprite;
    static Animation* explosion;
    Gun* gun;
    Vector2 position;
    int life, id;
    int hitBoxRadius;
    float speed;
    float explosionTime, explosionTimeCounter;
    bool dead;

protected:
    Enemy(int screenWidth, int screenHeight, int x, int y, float speed, int life); // Construtor padrão.

public:
    virtual ~Enemy(); // Destrutor padrão.

    void render(bool accelerating); // Renderiza o inimigo.

    virtual void move(bool accelerating); // Move o inimigo.

    bool isDead(); // Retorna se o inimigo está morto.

    // Verifica a colisão com o inimigo e todas as suas balas.
    bool verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun, function<void(int)> addScore);

    int getId(); // Retorna o id do inimigo.

    void loseSpeed(); // Diminui a velocidade do inimigo.

private:
    void renderSprite(); // Renderiza o sprite do inimigo.

};

#endif // ENEMY_H
