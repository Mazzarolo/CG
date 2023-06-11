// Classe base para os botões do jogo, que é herdada pelos outros botões.

#ifndef BUTTON_H
#define BUTTON_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Input.h"
#include <functional>

using namespace std;

class Button : public Input
{
protected:
    int x, y, width, height;
    function<void()> onClick;
    bool selected, clicked, active;

protected:
    // Construtores
    Button(int x, int y, int width, int height, function<void()> onClick);
    Button(int x, int y, function<void()> onClick);

    // Destrutor
    virtual ~Button() { };

    // Renderiza o botão
    virtual void render() = 0;

    // Verifica se o mouse está sobre o botão
    bool checkCollision();

    // Evento de clique no botão
    void onMouse();

public:
    // Atualiza se o botão esta ativo
    void setActive(bool active);

    // Retorna se o botão esta ativo
    bool getActive();
};

#endif // BUTTON_H