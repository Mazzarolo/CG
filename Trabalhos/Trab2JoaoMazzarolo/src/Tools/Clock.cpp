#include "Clock.h"

float Clock::deltaTime = 0;
float Clock::stopWatch = 0;
bool Clock::isPaused = false;

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

    if(!isPaused)
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
    isPaused = false;
}

float Clock::getStopWatch()
{
    return stopWatch;
}

void Clock::printStopWatch(int x, int y)
{
    char sw[10];
    sprintf(sw, "Time:%.1f", getStopWatch());
    CV::color(1, 1, 1);
    CV::text(x, y, sw);
}

void Clock::pause()
{
    isPaused = true;
}

void Clock::resume()
{
    isPaused = false;
}