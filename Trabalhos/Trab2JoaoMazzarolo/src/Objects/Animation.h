#ifndef ANIMATION_H
#define ANIMATION_H

#include "Bitmap.h"
#include "../Tools/Clock.h"

class Animation : public Bitmap, public Clock
{
private:
    int numColumns, numRows;
    int currentFrame;
    int numFrames;
    float frameTime, timer;

public:
    Animation(int numColumns, int numRows, int numFrames, float frameTime);

    void render();

    Animation* clone();
};

#endif // ANIMATION_H
