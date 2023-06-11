// Classe que desenha e controla o plano de fundo da cena principal do jogo

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <time.h>
#include <stdlib.h>
#include "../Lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Star.h"
#include "Animation.h"
#include "Bezier.h"


using namespace std;

class Background : public Clock
{
private:
    Bezier* leftCurve;
    Bezier* rightCurve;
    int backColor[3], lineColor[3];
    int renderY, height, offsetY;
    int screenWidth, screenHeight;
    vector<Star*> stars;
    vector<Animation*> planets;

public:
    // Cria o plano de fundo
    Background(int screenWidth, int screenHeight, int offsetY, int curveHeight);

    // Destrói o plano de fundo
    ~Background();

    // Verifica a colisão com as curvas de Bezier
    bool checkCollision(Vector2 point, int hitBoxRadius);
    // Verifica a colisão com a curva da direita ou da esquerda
    bool checkCollision(Vector2 point, int hitBoxRadius, bool right);

    // Desenha o plano de fundo
    void render();

    // Move o plano de fundo
    void moveY(int renderY);

    // Retorna o ponto de spawn entre as curvas onde alguns tipos de inimigos podem nascer
    vector<Vector2> getSpawnPoints();

private:
    // Cria as estrelas que serão desenhadas no plano de fundo
    void createStars(int numStars);

    // Desenha as estrelas
    void renderStars();
};

#endif // BACKGROUND_H
