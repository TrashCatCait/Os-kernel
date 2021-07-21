#include "includes/utils.h"
//Use details taken from GOP is to write to pixels.
void plot_pixel_gop(uint32_t pixelPerSL, int x, int y, uint32_t pixel, void *buffer) {
   *((uint32_t*)(buffer + 4 * pixelPerSL * y + 4 * x)) = pixel;
}

//gop clear screen function 
void clr_scr_gop(uint32_t pixelPerSL, uint32_t width, uint32_t height, uint32_t pixel, void *buffer) {
   for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            plot_pixel_gop(pixelPerSL, i, j, pixel, buffer);
        }
    }
}
