// Classe que representa a cena do menu

#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <vector>
#include "../Lib/gl_canvas2d.h"
#include "Scene.h"
#include "../UI/SpriteButton.h"

using namespace std;

class MenuScene : public Scene
{
private:
    Bitmap* title;
    vector<SpriteButton*> buttons;

public:
    // Construtor
    MenuScene(int screenWidth, int screenHeight);

    // Destrutor
    ~MenuScene();

    // Renderiza a cena
    void render();

private:
    // Evento de clique no botão de jogar
    void onPlayClick();

    // Evento de clique no botão de informações
    void onInfoClick();

    // Evento de clique no botão de sair
    void onExitClick();

    // Método que reseta a cena
    virtual void reset();

    // Método para setar a próxima cena
    virtual void setNextScene(int nextScene);
};

#endif // MENU_SCENE_H