// Classe que representa uma curva de Bezier

#ifndef BEZIER_H
#define BEZIER_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Collisions.h"
#include <vector>

using namespace std;

class Bezier
{
private:
    vector<Vector2> points;
    vector<Vector2> renderPoints;
    Vector2 spawnPoint;

public:
    // Construtor
    Bezier(vector<Vector2> points);

    // Verifica colisão com a curva
    bool checkCollision(Vector2 player, int hitBoxRadius);

    // Move a curva em relação a Y
    void moveY(int offsetY);

    // Desenha uma curva de Bezier
    void render();

    // Desenha o ponto de spawn
    void renderSpawnPoint();

    // Retorna o ponto de spawn
    Vector2 getSpawnPoint();

private:
    //Função que vai interpolando entre 2 pontos com base em um offset t
    Vector2 lerp(Vector2 a, Vector2 b, float t);

};

#endif // BEZIER_H
