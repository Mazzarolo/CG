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