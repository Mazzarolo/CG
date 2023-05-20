#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include "../Structures/Vector2.h"

using namespace std;

namespace Collisions
{
    bool circlePoint(Vector2 center, float radius, Vector2 point);
};


#endif // COLLISIONS_H
