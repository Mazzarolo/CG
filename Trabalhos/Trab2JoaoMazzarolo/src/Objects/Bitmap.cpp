#include "Bitmap.h"

Bitmap::Bitmap()
{
    
}

bool Bitmap::read(unsigned char* memory)
{
    memcpy(&header.test, &memory[0], 2);
    memcpy(&header.size, &memory[2], 4);
    memcpy(&header.reserved, &memory[6], 4);
    memcpy(&header.offset, &memory[10], 4);

    memcpy(&dibHeader.size, &memory[14], 4);

    if (dibHeader.size != 40)
    {
        printf("Error: DIB header size is not 40\n");
        return false;
    }

    memcpy(&dibHeader.pixelWidth, &memory[18], 4);
    memcpy(&dibHeader.pixelHeight, &memory[22], 4);
    memcpy(&dibHeader.numColorPlanes, &memory[26], 2);
    memcpy(&dibHeader.colorDepth, &memory[28], 2);
    memcpy(&dibHeader.compressionMethod, &memory[30], 4);
    memcpy(&dibHeader.rawImageSize, &memory[34], 4);
    memcpy(&dibHeader.horizontalResolution, &memory[38], 4);
    memcpy(&dibHeader.verticalResolution, &memory[42], 4); 
    memcpy(&dibHeader.numColors, &memory[46], 4);
    memcpy(&dibHeader.numImportantColors, &memory[50], 4);

    if (dibHeader.numColors != 0)
    {
        printf("Error: DIB header numColors is not 0\n");
        return false;
    }

    if(dibHeader.colorDepth != 24)
    {
        printf("Error: DIB header colorDepth is not 24\n");
        return false;
    }

    pixelInfo.rowSize = (((dibHeader.pixelWidth * dibHeader.colorDepth) + 31) / 32) * 4;
    pixelInfo.arraySize = dibHeader.pixelWidth * dibHeader.pixelHeight;

    pixels = new BitmapPixel[pixelInfo.arraySize];

    int index = 0;

    for (int i = 0; i < dibHeader.pixelHeight; i++)
    {
        unsigned char* rowData = new unsigned char[pixelInfo.rowSize];

        memcpy(rowData, &memory[header.offset + (i * pixelInfo.rowSize)], pixelInfo.rowSize);

        for (int j = 0; j < dibHeader.pixelWidth * 3; j += 3)
        {
            pixels[index].b = rowData[j];
            pixels[index].g = rowData[j + 1];
            pixels[index].r = rowData[j + 2];
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
        for (int j = 0; i < dibHeader.pixelHeight; j++)
        {
            CV::point(j, i);
        }
        
    }
}