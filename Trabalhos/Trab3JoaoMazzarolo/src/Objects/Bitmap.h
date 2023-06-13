// Classe que serve para controlar e desenhar imagens carregadas no formato BMP

#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lib/gl_canvas2d.h"

using namespace std;

// Structs que representa cada pixel da imagem
typedef struct bitmapPixel
{
    float r, g, b, a;
} BitmapPixel;

// Structs que representa o cabeçalho do arquivo BMP
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

// Struct que representa informações sobre os pixels da imagem
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
    // Construtor
    Bitmap();

    // Destrutor
    virtual ~Bitmap();
    
    // Carrega uma imagem no formato BMP
    void load(char* filename);

    // Renderiza a imagem
    virtual void render();

    // Move a imagem
    void setPosition(int x, int y);

    // Retorna a largura e altura da imagem
    int getWidth();
    int getHeight();

    // move a imagem em relação a X
    void moveX(int x);

    // move a imagem em relação a Y
    void moveY(float y);

    // Retorna a posição da imagem
    Vector2 getPosition();

    // Retorna uma copia da imagem
    virtual Bitmap* clone();

private:
    // Lê o cabeçalho do arquivo BMP
    bool read(unsigned char* memory);
};

#endif // BITMAP_H