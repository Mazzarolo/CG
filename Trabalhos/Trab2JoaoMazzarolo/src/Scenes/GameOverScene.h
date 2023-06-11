#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "Scene.h"
#include <vector>
#include "../UI/SpriteButton.h"

class GameOverScene : public Scene
{
private:
    int score, highscore;
    Bitmap* title;
    vector<SpriteButton*> buttons;

public:
    GameOverScene(int screenWidth, int screenHeight);

    ~GameOverScene();

    void render();

    virtual void reset(int score);
private:
    void onPlayClick();

    void onExitClick();

    virtual void setNextScene(int nextScene);

    void getHighscore();

    void setHighscore();
};

#endif // GAME_OVER_SCENE_H