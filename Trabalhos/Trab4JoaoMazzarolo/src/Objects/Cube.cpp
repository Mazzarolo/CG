#include "Cube.h"

Cube::Cube(Point center, float side)
{
    this->center = center;
    this->side = side;

    points[0] = new Point(center.x - side / 2, center.y - side / 2, center.z - side / 2);
    points[1] = new Point(center.x + side / 2, center.y - side / 2, center.z - side / 2);
    points[2] = new Point(center.x + side / 2, center.y + side / 2, center.z - side / 2);
    points[3] = new Point(center.x - side / 2, center.y + side / 2, center.z - side / 2);
    points[4] = new Point(center.x - side / 2, center.y - side / 2, center.z + side / 2);
    points[5] = new Point(center.x + side / 2, center.y - side / 2, center.z + side / 2);
    points[6] = new Point(center.x + side / 2, center.y + side / 2, center.z + side / 2);
    points[7] = new Point(center.x - side / 2, center.y + side / 2, center.z + side / 2);
    angle = 0;
}

Cube::~Cube()
{
    for (int i = 0; i < 8; i++)
    {
        delete points[i];
    }
}

Point Cube::rotateX(Point p, float angle)
{
    Point r;
    r.x = p.x;
    r.y = p.y * cos(angle) - p.z * sin(angle);
    r.z = p.y * sin(angle) + p.z * cos(angle);

    return r;
}

Point Cube::rotateY(Point p, float angle)
{
    Point r;
    r.x = p.x * cos(angle) + p.z * sin(angle);
    r.y = p.y;
    r.z = -p.x * sin(angle) + p.z * cos(angle);

    return r;
}

Point Cube::rotateZ(Point p, float angle)
{
    Point r;
    r.x = p.x * cos(angle) - p.y * sin(angle);
    r.y = p.x * sin(angle) + p.y * cos(angle);
    r.z = p.z;

    return r;
}

Point Cube::translate(Point p)
{
    Point r;
    r.x = p.x;
    r.y = p.y;
    r.z = p.z + side + 12;

    return r;
}

Point Cube::project(Point p)
{
    float d = 50;
    Point r;
    r.x = p.x * d / p.z;
    r.y = p.y * d / p.z;
    r.z = p.z;

    return r;
}

void Cube::transform()
{
    Point p;

    angle += 0.0001;

    for (int i = 0; i < 8; i++)
    {
        p = rotateX(*points[i], angle);
        p = rotateY(*points[i], angle);
        p = translate(p);
        p = project(p);
        transf[i] = new Point(p.x, p.y, p.z);
    }
}

void Cube::render()
{

    transform();

    CV::color(0, 0, 0);

    CV::line(transf[0]->x, transf[0]->y, transf[1]->x, transf[1]->y);
    CV::line(transf[1]->x, transf[1]->y, transf[2]->x, transf[2]->y);
    CV::line(transf[2]->x, transf[2]->y, transf[3]->x, transf[3]->y);
    CV::line(transf[3]->x, transf[3]->y, transf[0]->x, transf[0]->y);

    CV::line(transf[4]->x, transf[4]->y, transf[5]->x, transf[5]->y);
    CV::line(transf[5]->x, transf[5]->y, transf[6]->x, transf[6]->y);
    CV::line(transf[6]->x, transf[6]->y, transf[7]->x, transf[7]->y);
    CV::line(transf[7]->x, transf[7]->y, transf[4]->x, transf[4]->y);

    CV::line(transf[0]->x, transf[0]->y, transf[4]->x, transf[4]->y);
    CV::line(transf[1]->x, transf[1]->y, transf[5]->x, transf[5]->y);
    CV::line(transf[2]->x, transf[2]->y, transf[6]->x, transf[6]->y);
    CV::line(transf[3]->x, transf[3]->y, transf[7]->x, transf[7]->y);

    for (int i = 0; i < 8; i++)
    {
        delete transf[i];
    }
}
