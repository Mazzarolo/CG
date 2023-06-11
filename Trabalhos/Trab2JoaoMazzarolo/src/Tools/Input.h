// Classe que controla os callbacks de input do usuário, é herdado por todas as classes que utilizam esses recursos

#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <functional>

using namespace std;

class Input
{
private:
    static int button, state, wheel, direction, mX, mY, keyUp, keyDown;
    static vector<function<void()>> keyUpListeners, keyDownListeners, mouseListeners;

public:
    // Construtor
    Input();

    // Destrutor
    virtual ~Input();

    // Método que verifica se uma tecla foi solta
    void setKeyUp(int key);

    // Método que verifica se uma tecla foi pressionada
    void setKeyDown(int key);

    // Método que verifica se o mouse foi pressionado
    void setMouse(int button, int state, int wheel, int direction, int mX, int mY);

    // Método que reseta as teclas salvas
    void resetKeys();

protected:
    // Método de callback para o evento de tecla pressionada
    virtual void onKeyboardDown() { };

    // Método de callback para o evento de tecla solta
    virtual void onKeyboardUp() { };

    // Método de callback para o evento de clique do mouse
    virtual void onMouse() { };

    // Método que retorna o botão do mouse pressionado
    int getButton();

    // Método que retorna o estado do botão do mouse
    int getState();

    // Método que retorna o estado da roda do mouse
    int getWheel();

    // Método que retorna a direção da roda do mouse
    int getDirection();

    // Método que retorna a posição X do mouse
    int getMX();

    // Método que retorna a posição Y do mouse
    int getMY();

    // Método que retorna a tecla solta
    int getKeyUp();

    // Método que retorna a tecla pressionada
    int getKeyDown();

private:
    // Método que adiciona os listeners de input
    void addKeyboardListeners(function<void()> keyUpListener, function<void()> keyDownListener, function<void()> mouseListener);

};

#endif  // INPUT_H
