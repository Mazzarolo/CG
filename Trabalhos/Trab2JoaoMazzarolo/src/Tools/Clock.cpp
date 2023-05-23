#include "Clock.h"

float Clock::deltaTime = 0;
float Clock::stopWatch = 0;

Clock::Clock()
{
    lastFrame = chrono::steady_clock::now();
}

void Clock::tic()
{
    chrono::steady_clock::time_point currentFrame = chrono::steady_clock::now();
    chrono::duration<float> time = currentFrame - lastFrame;
    deltaTime = time.count();
    lastFrame = currentFrame;

    stopWatch += deltaTime;
}

float Clock::getDeltaTime()
{
    return deltaTime;
}

void Clock::printFPS(int x, int y)
{
    char fps[10];
    sprintf(fps, "FPS: %.f", 1 / getDeltaTime());
    CV::color(1, 1, 1);
    CV::text(x, y, fps);
}

void Clock::resetStopWatch()
{
    stopWatch = 0;
}

float Clock::getStopWatch()
{
    return stopWatch;
}

void Clock::printStopWatch(int x, int y)
{
    char sw[10];
    sprintf(sw, "Time:%.f", getStopWatch());
    CV::color(1, 1, 1);
    CV::text(x, y, sw);
}