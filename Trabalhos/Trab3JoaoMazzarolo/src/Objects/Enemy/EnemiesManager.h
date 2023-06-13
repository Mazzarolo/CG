// Classe que gerencia a criação e movimentação dos inimigos.

#ifndef ENEMIESMANAGER_H
#define ENEMIESMANAGER_H

#include <vector>
#include "BlockerEnemy.h"
#include "SmallEnemy.h"
#include "SeekerEnemy.h"
#include "../../Tools/Clock.h"
#include "../../Lib/gl_canvas2d.h"
#include "../Background.h"

class EnemiesManager : public Clock
{
private:
    vector<Enemy*> enemies;
    vector<Animation*> sprites;
    Animation* explosion;
    Background* background;
    Player* player;
    int screenWidth, screenHeight;
    float spawnTime, spawnTimeCounter;

public:
    // Construtor padrão.
    EnemiesManager(int screenWidth, int screenHeight, Background* background, Player* player);

    void reset(); // Reseta o gerenciador de inimigos.

    void render(int level, bool up); // Renderiza os inimigos.

    void spawn(int level); // Cria um novo inimigo.

    bool verifyCollision(); // Verifica a colisão de todos os inimigos e balas com o jogador.
};

#endif // ENEMIESMANAGER_H