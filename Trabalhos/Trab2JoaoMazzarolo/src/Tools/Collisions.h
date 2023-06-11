// Namespace responsavel por verificar algumas colisoes basicas

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include "../Structures/Vector2.h"

using namespace std;

namespace Collisions
{
    // Verifica a colisão entre um ponto e um circulo
    bool circlePoint(Vector2 center, float radius, Vector2 point);

    // Verifica a colisão entre dois circulos
    bool circleCircle(Vector2 center1, float radius1, Vector2 center2, float radius2);
};


#endif // COLLISIONS_H
