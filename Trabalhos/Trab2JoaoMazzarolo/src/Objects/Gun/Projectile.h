// Classe do Projétil, que é utilizado tanto pelo jogador quanto pelos inimigos.

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../Lib/gl_canvas2d.h"
#include "../../Tools/Clock.h"
#include "../Animation.h"

class Projectile : public Clock
{
private:
    static Animation* explosionSprite;
    Vector2 position;
    int radius, fixedX;
    float colorCircle[3];
    float colorBorder[3];
    int speed, enemyId;
    float explosionTime, explosionTimeCounter;
    bool ended;
    bool curved, topDown, continuous, decelerator, decending;

public:
    // Construtor padrão.
    Projectile(int x, int y, int radius, int speed, float* colorCircle, float* colorBorder);

    virtual ~Projectile() { };

    // Carrega o sprite da explosão.
    static void loadExplosionSprite();

    // Renderiza o projétil.
    void render();

    void move(); // Move o projétil.
    void move(bool down); // Move o projétil dos inimigos mais rapidamente se o jogador estiver se movendo.

    int getY(); // Retorna a posição Y do projétil.

    int getRadius(); // Retorna o raio do projétil.

    Vector2 getPosition(); // Retorna a posição do projétil.

    virtual void renderSprite(); // Renderiza o sprite do projétil.

    void explode(); // começa o processo de explosão do projétil.

    bool hasEnded(); // Verifica se o projétil já explodiu.

    bool getEnded(); // Retorna se o projétil está em processo de explosão

    Projectile* clone(); // Retorna uma cópia do projétil.

    void setPosition(int x, int y); // Define a posição do projétil.

    void setRadius(int radius); // Define o raio do projétil.

    void setSpeed(int speed); // Define a velocidade do projétil.

    void setTopDown(bool topDown); // Define que o projetil ira retornar para baixo a partir de uma certa altura

    bool getTopDown();  // Retorna se o projétil irá retornar para baixo a partir de uma certa altura

    void setCurved(bool curved); // Define que o projétil irá seguir uma trajetória curva.

    bool getCurved(); // Retorna se o projétil irá seguir uma trajetória curva.

    void setContinuous(bool continuous); // Define que o projétil irá atravessar inimigos.

    bool getContinuous(); // Retorna se o projétil irá atravessar inimigos.

    void setEnemyId(int id); // Define o id do inimigo que está imune ao projetil (para projeteis que atravessam)

    int getEnemyId(); // Retorna o id do inimigo que está imune ao projetil (para projeteis que atravessam)

    void setDecelerator(bool decelerator); // define que o projetil ira desacelerar os alvos

    bool getDecelerator(); // retorna se o projetil ira desacelerar os alvos
};

#endif // PROJECTILE_H
