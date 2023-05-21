#include "Bitmap.h"

Bitmap::Bitmap()
{

}

Bitmap::~Bitmap()
{
    delete[] pixels;
}

bool Bitmap::read(unsigned char* memory)
{
    // Lendo o Header do Bitmap
    memcpy(&header.test, &memory[0], 2);
    memcpy(&header.size, &memory[2], 4);
    memcpy(&header.reserved, &memory[6], 4);
    memcpy(&header.offset, &memory[10], 4);
    
    // Lendo o DIB Header do Bitmap
    memcpy(&dibHeader.size, &memory[14], 4);
    memcpy(&dibHeader.pixelWidth, &memory[18], 4);
    memcpy(&dibHeader.pixelHeight, &memory[22], 4);
    memcpy(&dibHeader.numColorPlanes, &memory[26], 2);
    memcpy(&dibHeader.colorDepth, &memory[28], 2);

    // Calculando os valores para ler os pixels do bitmap
    pixelInfo.rowSize = (((dibHeader.pixelWidth * dibHeader.colorDepth) + 31) / 32) * 4;
    pixelInfo.arraySize = dibHeader.pixelWidth * dibHeader.pixelHeight;

    pixels = new BitmapPixel[pixelInfo.arraySize];

    int index = 0;

    // Lendo os pixels do bitmap
    for (int i = 0; i < dibHeader.pixelHeight; i++)
    {
        unsigned char* rowData = new unsigned char[pixelInfo.rowSize];

        memcpy(rowData, &memory[header.offset + (i * pixelInfo.rowSize)], pixelInfo.rowSize);

        for (int j = 0; j < dibHeader.pixelWidth * 4; j += 4)
        {
            pixels[index].b = ((float) rowData[j]) / 255.0f;
            pixels[index].g = ((float) rowData[j + 1]) / 255.0f;
            pixels[index].r = ((float) rowData[j + 2]) / 255.0f;
            pixels[index].a = ((float) rowData[j + 3]) / 255.0f;
            index++;
        }
        
        delete[] rowData;
    }
    
    return true;
}

void Bitmap::load(char* filename)
{
    FILE* file = fopen(filename, "rb");
    if(file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char* buffer = new unsigned char[size];
    fread(buffer, 1, size, file);
    fclose(file);

    if(!read(buffer))
    {
        printf("Error: Could not read file %s\n", filename);
        delete[] buffer;
        return;
    }

    printf("File %s loaded\n", filename);
    delete[] buffer;   
}

void Bitmap::render()
{
    for (int i = 0; i < dibHeader.pixelHeight; i++)
    {
        for (int j = 0; j < dibHeader.pixelWidth; j++)
        {
            if(pixels[i * dibHeader.pixelWidth + j].a == 0.0f)
                continue;
            CV::color(pixels[i * dibHeader.pixelWidth + j].r, pixels[i * dibHeader.pixelWidth + j].g, pixels[i * dibHeader.pixelWidth + j].b);
            CV::point(position.x + j, position.y + i);
        }
        
    }
}

void Bitmap::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

int Bitmap::getWidth()
{
    return dibHeader.pixelWidth;
}

int Bitmap::getHeight()
{
    return dibHeader.pixelHeight;
}