#include "includes/utils.h"
//Use details taken from GOP is to write to pixels.
void plotPixelGop(int pixelPerSL, int x, int y, uint32_t pixel, void *buffer) {
   *((uint32_t*)(buffer + 4 * pixelPerSL * y + 4 * x)) = pixel;
}

//gop clear screen function 
void clrScrGop(uint32_t pixelPerSL, uint32_t width, uint32_t height, uint32_t pixel, void *buffer) {
   for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            plotPixelGop(pixelPerSL, i, j, pixel, buffer);
        }
    }
}
