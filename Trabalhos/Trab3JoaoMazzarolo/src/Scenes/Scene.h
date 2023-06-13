// Classe base para as cenas do jogo, que é herdada pelas outras cenas.

#ifndef SCENE_H
#define SCENE_H

#include "../Tools/Input.h"
#include "../Tools/Clock.h"

class Scene : public Input, public Clock
{
protected:
    int screenWidth, screenHeight, nextScene;

public:
    // Construtor
    Scene(int screenWidth, int screenHeight);

    // Destrutor
    virtual ~Scene() {  };
    
    // Renderiza a cena
    virtual void render() = 0;
    
    // Retorna a próxima cena
    int getNextScene();

    // Reseta a cena
    virtual void reset() { };

    // Método para setar a próxima cena
    virtual void setNextScene(int nextScene);
};

#endif // SCENE_H
