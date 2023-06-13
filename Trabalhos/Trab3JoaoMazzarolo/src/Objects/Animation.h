// Classe dericade de Bitmap que serve para controlar animações, carregadas de spritesheets em formato BMP

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Bitmap.h"
#include "../Tools/Clock.h"

class Animation : public Bitmap, public Clock
{
private:
    int numColumns, numRows;
    int currentFrame;
    int numFrames;
    float frameTime, timer;

public:
    // Construtor que leva em consideração o número de colunas, linhas, frames da spritesheet, além do tempo de cada frame
    Animation(int numColumns, int numRows, int numFrames, float frameTime);

    // Renderiza o frame atual da animação
    void render();

    // Retorna uma cópia da animação
    Animation* clone();
};

#endif // ANIMATION_H
