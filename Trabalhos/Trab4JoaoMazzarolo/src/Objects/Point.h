// Classe para criar pontos em 3D

#ifndef POINT_H
#define POINT_H

class Point
{
public:
    float x;
    float y;
    float z;

    Point() { x = 0; y = 0; z = 0; }
    Point(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
};

#endif // POINT_H