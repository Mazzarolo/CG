// Classe que representa a cena de game over

#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "Scene.h"
#include <vector>
#include "../UI/SpriteButton.h"

class GameOverScene : public Scene
{
private:
    int score, highscore;
    float time;
    Bitmap* title;
    vector<SpriteButton*> buttons;

public:
    // Construtor
    GameOverScene(int screenWidth, int screenHeight);

    // Destrutor
    ~GameOverScene();

    // Renderiza a cena
    void render();

    // Reseta a cena
    virtual void reset(int score, float time);
private:
    // Evento de clique no botão de rejogar
    void onPlayClick();

    // Evento de clique no botão de sair
    void onExitClick();

    // Método para setar a próxima cena
    virtual void setNextScene(int nextScene);

    // Método para pegar o highscore da memória
    void getHighscore();

    // Método para setar o highscore na memória
    void setHighscore();
};

#endif // GAME_OVER_SCENE_H