#include "Collisions.h"

bool Collisions::circlePoint(Vector2 center, float radius, Vector2 point)
{
    float distanceSquared = pow(point.x - center.x, 2) + pow(point.y - center.y, 2);
    float radiusSquared = pow(radius, 2);

    return distanceSquared <= radiusSquared;
}

bool Collisions::circleCircle(Vector2 center1, float radius1, Vector2 center2, float radius2)
{
    float distanceSquared = pow(center2.x - center1.x, 2) + pow(center2.y - center1.y, 2);
    float radiusSquared = pow(radius1 + radius2, 2);

    return distanceSquared <= radiusSquared;
}