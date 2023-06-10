#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <time.h>
#include <stdlib.h>
#include "../Lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Star.h"
#include "Animation.h"
#include "Bezier.h"


using namespace std;

class Background : public Clock
{
private:
    Bezier* leftCurve;
    Bezier* rightCurve;
    int backColor[3], lineColor[3];
    int renderY, height, offsetY;
    int screenWidth, screenHeight;
    vector<Star*> stars;
    vector<Animation*> planets;

public:
    Background(int screenWidth, int screenHeight, int offsetY, int curveHeight);

    ~Background();

    bool checkCollision(Vector2 point, int hitBoxRadius);
    bool checkCollision(Vector2 point, int hitBoxRadius, bool right);

    void render();

    void moveY(int renderY);

    vector<Vector2> getSpawnPoints();

private:
    void createStars(int numStars);

    void renderStars();
};

#endif // BACKGROUND_H
