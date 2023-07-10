// Classe que desenha a modelagem do motor em 3D

#ifndef ENGINE_3D_H
#define ENGINE_3D_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Slider.h"
#include "Cylinder.h"

class Engine3D : public Clock
{
private:
    Slider *cameraSliderX, *cameraSliderY, *speedSlider;
    int screenWidth, screenHeight;
    Cylinder *eixo, *manivela1, *manivela2, *pistao1, *pistao2, *conection1, *conection2, *camisa1, *camisa2;
    float ang = PI / 2, angHorizontal = PI / 4, speed = 1;
    bool bielaVisible = true;

    void drawParallelLines(float x1, float y1, float x2, float y2, float radius, int numLines);

public:
    // Contrutor da classe
    Engine3D(int screenWidth, int screenHeight);

    // Renderiza o cilindro
    void render();

    // faz o movimento do primeiro pistao
    void movePistao1();

    // faz o movimento do segundo pistao
    void movePistao2();

    // trata inputs do mouse
    void onMouse(int button, int state, int wheel, int direction, int x, int y);

    // trata inputs do teclado
    void onKeyboard(int key);
};

#endif // ENGINE_3D_H