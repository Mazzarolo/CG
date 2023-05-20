#include "Collisions.h"

bool Collisions::circlePoint(Vector2 center, float radius, Vector2 point)
{
    float distanceSquared = pow(point.x - center.x, 2) + pow(point.y - center.y, 2);
    float radiusSquared = pow(radius, 2);

    return distanceSquared <= radiusSquared;
}