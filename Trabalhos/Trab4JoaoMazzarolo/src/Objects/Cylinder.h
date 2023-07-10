// Classe que repesenta um objeto 3D formado por uma malha, o formato inicial é um cilindro

#ifndef CYLINDER_H
#define CYLINDER_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Point.h"

#define DIM 30

class Cylinder : public Clock
{
private:
    Point mat[DIM + 1][DIM + 1];

    Point transf[DIM + 1][DIM + 1];

    float angX = 0, angY = 0, angZ = 0, distance = -300, speed = 1;

    bool visible = true;
public:
    // Construtor de um cilindro
    Cylinder(int orientation, float radiusMultiplier, float heightMultiplier);

    // Muda o formato da malha para um cone
    void changeShapeToCone(float radiusMultiplier, float heightMultiplier);

    // Muda o formato da malha para um paraboloide
    void changeShapeToCircularCone(float radiusMultiplier, float heightMultiplier);

    // Renderiza o cilindro
    void render();

    // Rotaciona um ponto no eixo x
    Point rotateX(Point p);
    // Rotaciona um ponto no eixo x com base em um angulo
    Point rotateX(Point p, float angle);

    // Rotaciona um ponto no eixo y
    Point rotateY(Point p);
    // Rotaciona um ponto no eixo y com base em um angulo
    Point rotateY(Point p, float angle);

    // Rotaciona um ponto no eixo z
    Point rotateZ(Point p);
    // Rotaciona um ponto no eixo z com base em um angulo
    Point rotateZ(Point p, float angle);

    // Rotaciona todo o cilindro em x com base em um angulo
    void rotateCylinderX(float angle);
    // Soma o angulo em x do cilindro
    void rotateCylinderX();

    // Rotaciona todo o cilindro em y com base em um angulo
    void rotateCylinderY(float angle);
    // Soma o angulo em y do cilindro
    void rotateCylinderY();

    // Rotaciona todo o cilindro em z com base em um angulo
    void rotateCylinderZ(float angle);
    // Soma o angulo em z do cilindro
    void rotateCylinderZ();

    // Retorna o angulo em z do cilindro
    float getAngZ();

    // Seta o angulo em Y do cilindro
    void setAngY(float angY);
    // Retorna o angulo em Y do cilindro
    float getAngY();

    // Seta o angulo em X do cilindro
    void setAngX(float angX);

    // Move o cilindro com base em um offset
    void translateCylinder(Point offset);

    // Move um ponto o suficiente para projetar
    Point translate(Point p);
    // Move um ponto com base em um offset
    Point translate(Point p, Point offset);

    // Move o cilindro para a origem
    void resetPosition(int orientation, float radiusMultiplier, float heightMultiplier);

    // Retorna o centro da face superior do cilindro
    Point getUpFaceCenter();

    // Retorna o centro da face inferior do cilindro
    Point getDownFaceCenter();

    // Retorna o centro do cilindro
    Point getCenter();

    // Seta a velocidade em que o cilindro gira
    void setSpeed(float speed);

    // Projeta um ponto do cilindro
    Point project(Point p);
    // Faz a projeção de todo o cilindro
    void project();

    // Aumenta a distancia do cilindro para zoom in e out
    void increaseDistance(float inc);

    // Seta a visibilidade do cilindro
    void setVisible();
};

#endif // CYlINDER_H