// Classe que representa uma estrela (compõem o fundo do jogo)

#ifndef STAR_H
#define STAR_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "player.h"

class Star : public Clock
{
private:
    Vector2 position;
    int radius, speed;

public:
    // Construtor
    Star(int x, int y, int radius);

    // Renderiza a estrela
    void render();

    // Move a estrela
    void setPosition(int x, int y);

    // Move a estrela ao longo do tempo
    void naturalMove(int screenHeight);
};


#endif // STAR_H
