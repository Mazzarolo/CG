#include "Bezier.h"

Bezier::Bezier(vector<Vector2> points)
{
    this->points = points;
    for (int i = 0; i < points.size(); i++)
    {
        renderPoints.push_back(points[i]);
    }
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

    //desenha a curva de bezier com 4 pontos de controle
    for (float t = 0; t < 1; t += 0.01)
    {
        Vector2 p0 = lerp(renderPoints[0], renderPoints[1], t);
        Vector2 p1 = lerp(renderPoints[1], renderPoints[2], t);
        Vector2 p2 = lerp(renderPoints[2], renderPoints[3], t);

        Vector2 p01 = lerp(p0, p1, t);
        Vector2 p12 = lerp(p1, p2, t);

        Vector2 p = lerp(p01, p12, t);

        CV::line(oldPoint.x, oldPoint.y, p.x, p.y);
        oldPoint = p;
    }
}

//Faça um metodo que verifique a colisão da curva com um ponto passado por parametro
bool Bezier::checkCollision(Vector2 player, int hitBoxRadius)
{
    // Implemente a fun��o de colis�o
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
    for (int i = 0; i < points.size(); i++) {
        renderPoints[i].y = points[i].y + offsetY;
    }
}

/*
// Implemente a fun��o binomial
int binomial(int n, int k)
{
    // Implemente a fun��o binomial
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

//fa�a uma fun��o que desenhe uma curva de bezier com base nos pontos de controle sem usar binomial
void draw()
{
    // Desenha a curva de Bezier
    for (float t = 0; t < 1; t += 0.01) {
        // Calcula a posi��o do ponto da curva de Bezier
        float x = 0;
        float y = 0;
        for (int i = 0; i < points.size(); i++) {
            x += points[i].x * pow(1 - t, points.size() - i - 1) * pow(t, i) * binomial(points.size() - 1, i);
            y += points[i].y * pow(1 - t, points.size() - i - 1) * pow(t, i) * binomial(points.size() - 1, i);
        }

        // Desenha o ponto da curva de Bezier
        CV::color(1, 0, 0);
        CV::point(x, y);
    }

    // Desenha os pontos de controle
    CV::color(0, 0, 1);
    for (int i = 0; i < points.size(); i++) {
        CV::point(points[i].x, points[i].y);
    }
}*/
