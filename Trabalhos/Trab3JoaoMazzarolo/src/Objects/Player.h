// Classe que representa o jogador

#ifndef PLAYER_H
#define PLAYER_H

#include "../Lib/gl_canvas2d.h"
#include "Gun/Gun.h"
#include "../Tools/Input.h"
#include "../Tools/Clock.h"
#include "Animation.h"
#include <vector>

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
    float invincibleTime, invincibleTimeCounter, invincibleBlinkTime, invincibleBlinkTimeCounter, shieldTime, shieldTimeCounter;
    float scoreTime, scoreTimeCounter;
    float changingTime, changingTimeCounter;
    float speed, cameraSpeed;
    bool left, right, top, shooting;
    int fixedY, maxY;

public:
    // Construtor
    Player(int screenWidth, int screenHeight, int startY, int curveHeight);

    // Destrutor
    virtual ~Player();

    // Renderiza o jogador
    void render();

    // Função de callback para o teclado quando uma tecla é pressionada
    void onKeyboardDown();

    // Função de callback para o teclado quando uma tecla é solta
    void onKeyboardUp();

    // Move o jogador
    void move();

    // Retorna o Y do jogador
    int getY();

    // Atualiza o X do jogador
    void setX(int x);

    // Retorna a posição do jogador
    Vector2 getPosition();

    // Retorna o raio do hitbox do jogador
    int getHitBoxRadius();

    // Retorna o nivel do jogador
    int getLevel();

    // Retorna se o jogador está se movendo para cima mais rapidamente
    bool isUp();

    // Função que verificam se o jogador pode receber dano, o aplicam e retornam se o jogador morreu
    bool takeDamage(int x);
    bool takeDamage();

    // Reseta o jogador
    void reset(int x);

    // Retorna a arma do jogador
    Gun* getGun();

    // Retorna a pontuação do jogador
    int getScore();

    // Adiciona pontuação ao jogador
    void addScore(int score);

    // Retorna a vida do jogador
    int getLife();

    // Adicona vida ao jogador
    void addLife();

    // Adiciona escudo ao jogador
    void addShield();

    // Adciona velocidade ao jogador
    void addSpeed(float multiplier);

    // Adiciona multiplicador de pontuação ao jogador
    void addScoreMultiplier();

private:
    // Função que controla a arma do jogador
    void gunControl();

    // Função que renderiza os status do jogador
    void renderStats();

    // Função que renderiza o sprite do jogador
    void renderSprite();

    // Função que verifica se o jogador mudou de nível
    void verifyChanges();
};

#endif // PLAYER_H
