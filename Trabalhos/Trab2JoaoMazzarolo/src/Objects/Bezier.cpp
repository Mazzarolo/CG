#include "Bezier.h"

Bezier::Bezier(vector<Vector2> points)
{
    this->points = points;
    for (int i = 0; i < (int) points.size(); i++)
    {
        renderPoints.push_back(points[i]);
    }
    spawnPoint = Vector2(points[0].x, 600);
}

//Fun��o que vai interpolando entre 2 pontos com base em um offset t
Vector2 Bezier::lerp(Vector2 a, Vector2 b, float t)
{
    return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

//Desenha uma curva de Bezier
void Bezier::render()
{
    Vector2 oldPoint = renderPoints[0];

    CV::color(1, 1, 1);

    //desenha a curva de bezier com 4 pontos de controle
    for (float t = 0; t < 1; t += 0.01)
    {
        Vector2 p0 = lerp(renderPoints[0], renderPoints[1], t);
        Vector2 p1 = lerp(renderPoints[1], renderPoints[2], t);
        Vector2 p2 = lerp(renderPoints[2], renderPoints[3], t);

        Vector2 p01 = lerp(p0, p1, t);
        Vector2 p12 = lerp(p1, p2, t);

        Vector2 p = lerp(p01, p12, t);

        if(Collisions::circlePoint(p, 5, Vector2(p.x, spawnPoint.y)))
        {
            spawnPoint.x = p.x;
        }

        CV::line(oldPoint.x, oldPoint.y, p.x, p.y);
        oldPoint = p;
    }
}

//Faça um metodo que verifique a colisão da curva com um ponto passado por parametro
bool Bezier::checkCollision(Vector2 player, int hitBoxRadius)
{
    for (float t = 0; t < 1; t += 0.01) {
        Vector2 p0 = lerp(renderPoints[0], renderPoints[1], t);
        Vector2 p1 = lerp(renderPoints[1], renderPoints[2], t);
        Vector2 p2 = lerp(renderPoints[2], renderPoints[3], t);

        Vector2 p01 = lerp(p0, p1, t);
        Vector2 p12 = lerp(p1, p2, t);

        Vector2 p = lerp(p01, p12, t);

        if (Collisions::circlePoint(player, hitBoxRadius, p))
        {
            return true;
        }
    }

    return false;
}

void Bezier::moveY(int offsetY)
{
    for (int i = 0; i < (int) points.size(); i++) {
        renderPoints[i].y = points[i].y + offsetY;
    }
}

void Bezier::renderSpawnPoint()
{
    CV::color(1, 0, 0);
    CV::circle(spawnPoint.x, spawnPoint.y, 5, 30);
}

Vector2 Bezier::getSpawnPoint()
{
    return spawnPoint;
}