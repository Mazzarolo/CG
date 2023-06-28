#include "Engine2D.h"

Engine2D::Engine2D(int screenWidth, int screenHeight)
{
    pistao = new Component2D({Vector2(0, 0),
                              Vector2(0, 100),
                              Vector2(100, 100),
                              Vector2(100, 0)});

    manivela = new Component2D({Vector2(0, 30),
                                Vector2(30, 100),
                                Vector2(70, 100),
                                Vector2(100, 30),
                                Vector2(90, 15),
                                Vector2(70, 0),
                                Vector2(30, 0),
                                Vector2(10, 15)});

    biela = new Component2D({Vector2(0, 85),
                             Vector2(15, 100),
                             Vector2(30, 250),
                             Vector2(70, 250),
                             Vector2(85, 100),
                             Vector2(100, 85),
                             Vector2(100, 15),
                             Vector2(70, 0),
                             Vector2(30, 0),
                             Vector2(0, 15)});

    manivela->translate(Vector2(screenWidth / 2, screenHeight / 4));
}

Engine2D::~Engine2D()
{
    delete pistao;
    delete manivela;
    delete biela;
}

void Engine2D::render()
{
    pistao->render();
    manivela->render();
    manivela->rotate(getDeltaTime() * 5);
    biela->render();
    biela->move(manivela->getUpFaceCenter() - biela->getCenter() + Vector2(0, 40));
    pistao->move(biela->getUpFaceCenter() - pistao->getCenter());
    while (biela->getUpFaceCenter().x < manivela->getCenter().x - 1 || biela->getUpFaceCenter().x > manivela->getCenter().x + 1 || biela->getUpFaceCenter().y < manivela->getCenter().y)
    {
        if (biela->getCenter().x < manivela->getCenter().x)
        {
            // printf("\nRotacionando para a direita");
            biela->rotate(-0.1);
        }
        else
        {
            // printf("\nRotacionando para a esquerda");
            biela->rotate(0.1);
        }
    }
}
