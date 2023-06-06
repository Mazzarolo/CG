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
    Bezier(vector<Vector2> points);

    bool checkCollision(Vector2 player, int hitBoxRadius);

    //move the curves
    void moveY(int offsetY);

    //Desenha uma curva de Bezier
    void render();

    void renderSpawnPoint();
private:
    //Função que vai interpolando entre 2 pontos com base em um offset t
    Vector2 lerp(Vector2 a, Vector2 b, float t);

};

#endif // BEZIER_H
