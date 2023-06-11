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
    InfoScene(int screenWidth, int screenHeight);

    ~InfoScene();

    void render();

    virtual void reset();

private:
    void onExitClick();

    virtual void setNextScene(int nextScene);
};

#endif // INFO_SCENE_H