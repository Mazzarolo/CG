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
    MenuScene(int screenWidth, int screenHeight);

    ~MenuScene();

    void render();

private:
    void onPlayClick();

    void onInfoClick();

    void onExitClick();

    virtual void reset();

    virtual void setNextScene(int nextScene);
};

#endif // MENU_SCENE_H