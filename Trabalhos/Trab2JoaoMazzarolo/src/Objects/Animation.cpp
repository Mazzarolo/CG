#include "Animation.h"

Animation::Animation(int numColumns, int numRows, int numFrames, float frameTime) : Bitmap()
{
    this->numColumns = numColumns;
    this->numRows = numRows;
    this->numFrames = numFrames;
    this->frameTime = frameTime;
    timer = 0;
    currentFrame = 0;
}

void Animation::render()
{
    if(timer > frameTime)
    {   
        if(currentFrame == numFrames - 1)
            currentFrame = 0;
        else
            currentFrame++;
        timer = 0;
    }

    int frameWidth = dibHeader.pixelWidth / numColumns;
    int frameHeight = dibHeader.pixelHeight / numRows;

    int frameX = (currentFrame % numColumns) * frameWidth;
    int frameY = (currentFrame / numColumns) * frameHeight;

    for (int i = frameY; i < frameY + frameHeight; i++)
    {
        for (int j = frameX; j < frameX + frameWidth; j++)
        {
            if(pixels[i * dibHeader.pixelWidth + j].a == 0.0f)
                continue;
            CV::color(pixels[i * dibHeader.pixelWidth + j].r, pixels[i * dibHeader.pixelWidth + j].g, pixels[i * dibHeader.pixelWidth + j].b);
            CV::point(position.x + (dibHeader.pixelWidth - frameWidth) / 2 + j - frameX, position.y + (dibHeader.pixelHeight - frameHeight) / 2 + i - frameY);
        }
    }

    timer += getDeltaTime();
}

Animation* Animation::clone()
{
    Animation* clone = new Animation(numColumns, numRows, numFrames, frameTime);
    clone->position = position;
    clone->header = header;
    clone->dibHeader = dibHeader;
    clone->pixelInfo = pixelInfo;
    clone->pixels = new BitmapPixel[pixelInfo.arraySize];
    memcpy(clone->pixels, pixels, pixelInfo.arraySize * sizeof(BitmapPixel));
    return clone;
}