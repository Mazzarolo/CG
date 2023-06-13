// Classe que representa a cena de informações

#ifndef INFO_SCENE_H
#define INFO_SCENE_H

#include "Scene.h"
#include "../Lib/gl_canvas2d.h"
#include "../UI/SpriteButton.h"

class InfoScene : public Scene
{
private:
    Bitmap* title;
    SpriteButton* exitButton;

public:
    // Construtor
    InfoScene(int screenWidth, int screenHeight);

    // Destrutor
    ~InfoScene();

    // Renderiza a cena
    void render();

    // Reseta a cena
    virtual void reset();

private:
    // Evento de clique no botão de sair
    void onExitClick();

    // Método para setar a próxima cena
    virtual void setNextScene(int nextScene);

    // Método para printar o texto de informações
    void printInfoText();
};

#endif // INFO_SCENE_H