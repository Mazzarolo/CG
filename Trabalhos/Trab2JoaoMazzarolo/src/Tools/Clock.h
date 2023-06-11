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

    static bool isPaused;

protected:
    float getDeltaTime();

    void printFPS(int x, int y);

    void printStopWatch(int x, int y);

    void resetStopWatch();

public:
    Clock();
    
    void tic();

    void pause();

    void resume();

    float getStopWatch();
};

#endif // CLOCK_H
