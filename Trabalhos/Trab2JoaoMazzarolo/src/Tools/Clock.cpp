#include "Clock.h"

float Clock::deltaTime = 0;

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
}

float Clock::getDeltaTime()
{
    return deltaTime;
}

void Clock::printFPS(int x, int y)
{
    char fps[10];
    sprintf(fps, "FPS: %.1f", 1 / getDeltaTime());
    CV::color(1, 1, 1);
    CV::text(x, y, fps);
}