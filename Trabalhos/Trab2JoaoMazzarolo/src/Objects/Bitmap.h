#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lib/gl_canvas2d.h"

using namespace std;

typedef struct bitmapPixel
{
    unsigned char r, g, b;
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
    unsigned int compressionMethod;
    unsigned int rawImageSize;
    unsigned int horizontalResolution;
    unsigned int verticalResolution;
    unsigned int numColors;
    unsigned int numImportantColors;
} DibHeader;

typedef struct pixelInfo
{
    unsigned int rowSize;
    unsigned int arraySize;
} PixelInfo;

class Bitmap
{
private:
    BitmapHeader header;
    DibHeader dibHeader;
    PixelInfo pixelInfo;
    BitmapPixel* pixels;

public:
    Bitmap();
    
    void load(char* filename);

    void render();

private:
    bool read(unsigned char* memory);
};

#endif // BITMAP_H