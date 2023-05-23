#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include "../Structures/Vector2.h"

using namespace std;

namespace Collisions
{
    bool circlePoint(Vector2 center, float radius, Vector2 point);

    bool circleCircle(Vector2 center1, float radius1, Vector2 center2, float radius2);
};


#endif // COLLISIONS_H
