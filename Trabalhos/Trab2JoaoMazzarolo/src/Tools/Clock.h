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

    static float stopWatch;

protected:
    float getDeltaTime();

    void printFPS(int x, int y);

    void printStopWatch(int x, int y);

    void resetStopWatch();

    float getStopWatch();

public:
    Clock();
    
    void tic();
};

#endif // CLOCK_H
