#include "Component2D.h"

Component2D::Component2D(vector<Vector2> points)
{
    for (int i = 0; i < (int) points.size(); i++)
    {
        this->points.push_back(points[i]);
    }

    int max = points[0].y;

    for (int i = 0; i < (int) points.size(); i++)
    {
        if (points[i].y > max)
        {
            max = points[i].y;
        }
    }

    for (int i = 0; i < (int) points.size(); i++)
    {
        if (points[i].y == max)
        {
            upFace.push_back(points[i]);
        }
    }
}

void Component2D::render()
{
    float *vx = new float[(int) points.size()];
    float *vy = new float[(int) points.size()];

    for (int i = 0; i < (int) points.size(); i++)
    {
        vx[i] = points[i].x;
        vy[i] = points[i].y;
    }

    CV::color(0, 0, 0);
    CV::polygon(vx, vy, (int) points.size());

    /*
    CV::color(1, 0, 0);
    CV::circleFill(getCenter().x, getCenter().y, 2, 10);

    CV::color(0, 1, 0);
    CV::circleFill(getUpFaceCenter().x, getUpFaceCenter().y, 2, 10);
    */

    delete[] vx;
    delete[] vy;
}

Vector2 Component2D::getCenter()
{
    float x = 0;
    float y = 0;

    for (int i = 0; i < (int) points.size(); i++)
    {
        x += points[i].x;
        y += points[i].y;
    }

    return Vector2(x / points.size(), y / points.size());
}

void Component2D::rotate(float angle)
{
    Vector2 center = getCenter();

    for (int i = 0; i < (int) points.size(); i++)
    {
        float x = points[i].x - center.x;
        float y = points[i].y - center.y;

        points[i].x = x * cos(angle) - y * sin(angle) + center.x;
        points[i].y = x * sin(angle) + y * cos(angle) + center.y;
    }

    for (int i = 0; i < (int) upFace.size(); i++)
    {
        float x = upFace[i].x - center.x;
        float y = upFace[i].y - center.y;

        upFace[i].x = x * cos(angle) - y * sin(angle) + center.x;
        upFace[i].y = x * sin(angle) + y * cos(angle) + center.y;
    }
}

void Component2D::move(Vector2 translation)
{
    for (int i = 0; i < (int) points.size(); i++)
    {
        points[i].x += translation.x;
        points[i].y += translation.y;
    }

    for (int i = 0; i < (int) upFace.size(); i++)
    {
        upFace[i].x += translation.x;
        upFace[i].y += translation.y;
    }
}

void Component2D::translate(Vector2 translation)
{
    Vector2 center = getCenter();
    Vector2 delta = translation - center;

    for (int i = 0; i < (int) points.size(); i++)
    {
        points[i].x += delta.x;
        points[i].y += delta.y;
    }

    for (int i = 0; i < (int) upFace.size(); i++)
    {
        upFace[i].x += delta.x;
        upFace[i].y += delta.y;
    }
}

float Component2D::getHeight()
{
    int max = points[0].y;
    int min = points[0].y;

    for (int i = 0; i < (int) points.size(); i++)
    {
        if (points[i].y > max)
        {
            max = points[i].y;
        }
        else if (points[i].y < min)
        {
            min = points[i].y;
        }
    }

    return max - min;
}

float Component2D::getWidth()
{
    int max = points[0].x;
    int min = points[0].x;

    for (int i = 0; i < (int) points.size(); i++)
    {
        if (points[i].x > max)
        {
            max = points[i].x;
        }
        else if (points[i].x < min)
        {
            min = points[i].x;
        }
    }

    return max - min;
}

Vector2 Component2D::getUpFaceCenter()
{
    float x = 0;

    for (int i = 0; i < (int) upFace.size(); i++)
    {
        x += upFace[i].x;
    }

    return Vector2(x / upFace.size(), upFace[0].y);
}