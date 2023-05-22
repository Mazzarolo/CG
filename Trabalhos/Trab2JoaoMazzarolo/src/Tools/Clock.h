#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include "../Lib/gl_canvas2d.h"

using namespace std;

class Clock
{
private:
    chrono::steady_clock::time_point lastFrame;

    static float deltaTime;

protected:
    float getDeltaTime();

    void printFPS(int x, int y);

public:
    Clock();
    
    void tic();
};

#endif // CLOCK_H
