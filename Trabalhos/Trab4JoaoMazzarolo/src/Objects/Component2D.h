#ifndef COMPONENT_2D_H
#define COMPONENT_2D_H

#include <vector>
#include "../Vector2.h"
#include "../Lib/gl_canvas2d.h"

using namespace std;

class Component2D
{
private:
    vector<Vector2> points;
    vector<Vector2> upFace;

public:
    Component2D(vector<Vector2> points);

    void render();

    void rotate(float angle);

    void move(Vector2 translation);

    void translate(Vector2 translation);

    Vector2 getCenter();

    float getHeight();

    float getWidth();

    Vector2 getUpFaceCenter();
};

#endif // COMPONENT_2D_H