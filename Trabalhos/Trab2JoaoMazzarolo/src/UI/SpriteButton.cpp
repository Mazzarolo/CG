#include "SpriteButton.h"

SpriteButton::SpriteButton(int x, int y, function<void()> onClick, vector<char*> pathToSprites) : Button(x, y, onClick)
{
    for(int i = 0; i < (int) pathToSprites.size(); i++)
    {
        sprites.push_back(new Bitmap());
        sprites[i]->load(pathToSprites[i]);
        sprites[i]->setPosition(x, y);
    }

    width = sprites[0]->getWidth();
    height = sprites[0]->getHeight();
}

SpriteButton::~SpriteButton()
{
    for(int i = 0; i < (int) sprites.size(); i++)
    {
        delete sprites[i];
    }
}

void SpriteButton::render()
{
    if(clicked)
    {
        sprites[2]->render();
    }
    else if(selected)
    {
        sprites[1]->render();
    }
    else
    {
        sprites[0]->render();
    }
}
