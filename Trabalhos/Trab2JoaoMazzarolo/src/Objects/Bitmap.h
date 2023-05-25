#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lib/gl_canvas2d.h"

using namespace std;

typedef struct bitmapPixel
{
    float r, g, b, a;
} BitmapPixel;

typedef struct bitmapHeader
{
    unsigned char test[2];
    unsigned int size;
    unsigned int reserved;
    unsigned int offset;
} BitmapHeader;

typedef struct dibHeader
{
    unsigned int size;
    unsigned int pixelWidth;
    unsigned int pixelHeight;
    unsigned short numColorPlanes;
    unsigned short colorDepth;
} DibHeader;

typedef struct pixelInfo
{
    unsigned int rowSize;
    unsigned int arraySize;
} PixelInfo;

class Bitmap
{
protected:
    Vector2 position;
    BitmapHeader header;
    DibHeader dibHeader;
    PixelInfo pixelInfo;
    BitmapPixel* pixels;

public:
    Bitmap();

    virtual ~Bitmap();
    
    void load(char* filename);

    virtual void render();

    void setPosition(int x, int y);

    int getWidth();

    int getHeight();

    void moveX(int x);

    virtual Bitmap* clone();

private:
    bool read(unsigned char* memory);
};

#endif // BITMAP_H