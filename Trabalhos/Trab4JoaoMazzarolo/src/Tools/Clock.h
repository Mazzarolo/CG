// Classe que representa um relógio, contendo ferramentas de controle de tempo

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

public:
    // Método para calcular o tempo entre frames
    float getDeltaTime();

    // Método para printar o FPS
    void printFPS(int x, int y);

    // Método para printar o cronometro
    void printStopWatch(int x, int y);

    // Método para resetar o relógio
    void resetStopWatch();

    // Construtor
    Clock();
    
    // Método para atualizar o relógio
    void tic();

    // Método para pausar o cronometro
    void pause();

    // Método para resumir o cronometro
    void resume();

    // Método para retornar o tempo contado no cronometro
    float getStopWatch();
};

#endif // CLOCK_H
