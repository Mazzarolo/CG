// Classe das armas tanto do jogador quanto dos inimigos.

#ifndef GUN_H
#define GUN_H

#include "Projectile.h"
#include "../../Tools/Clock.h"
#include "../../Tools/Collisions.h"
#include <vector>
#include <functional>

using namespace std;

class Gun : public Clock
{
private:
    float shootRate, shootRateCounter;
    int limitY, speed, numProjectiles, radius, projectileRadius, damage;
    Vector2 position;
    Projectile* projectileModel;
    vector<Projectile*> projectiles;

public:
    //contrutor chamado pelo jogador
    Gun(int x, int y, int screenHeight, int radius);

    //contrutor chamado pelos inimigos
    Gun(int x, int y, int screenHeight, float shootRate, int speed);

    void shoot(); // Realiza o disparo.

    void render();  // Renderiza os disparos do jogodar.
    void render(bool down); // Renderiza os disparos dos inimigos.

    void moveX(int x); // Move a arma no eixo X.

    void move(int x, int y); // Move a arma no eixo X e Y.

    void reset(); // Reseta a arma.

    bool verifyCollision(Vector2 position, int radius); // Verifica a colisão com os disparos.
    bool verifyCollision(Vector2 position, int radius, int enemyId, function<void()> loseSpeed); // Verifica a colisão dos inimigos com os disparos.

    bool isEmpty(); // Verifica se a arma está vazia.

    void addShootRate(float shootRate); // Adiciona a taxa de disparo.

    void addSpeed(int speed); // Adiciona a velocidade dos disparos.

    void addShoot(); // Adiciona um disparo.

    void addProjectileRadius(int radius); // Adiciona o raio dos disparos.

    void addDamage(int damage); // Adiciona o dano dos disparos.

    int getDamage(); // Retorna o dano dos disparos.

    void setContinuous(); // Define o disparo que atravessa inimigos.

    void setCurved(); // Define o disparo que anda em uma trajetória curva.

    void setTopDown(); // Define o disparo que anda em uma trajetória de cima para baixo ao chegar em uma certa altura.

    void setDecelerator(); // Define o disparo que diminui a velocidade do alvo
};

#endif // GUN_H