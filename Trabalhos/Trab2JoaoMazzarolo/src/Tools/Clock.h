#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

using namespace std;

class Clock
{
private:
    chrono::steady_clock::time_point lastFrame;

    static float deltaTime;

protected:
    float getDeltaTime();

public:
    Clock();
    
    void tic();
};

#endif // CLOCK_H
