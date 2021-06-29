#include "includes/inttypes.h"
#include "includes/gdt.h"
#include "includes/io.h"
//same structs as what is found in the EFI program we just use different typedefs.
//As I personally prefer UNIX and LINUX like typedefs over UEFI typedefs
typedef struct {
    void *memMap;
    uint64_t mapSize;
    uint64_t descSize;
} memLay;

typedef struct {
    void* baseAdd;
    size_t bufferSize;
    uint32_t width;
    uint32_t height;
    uint32_t PPSL; // pixels per scan line
} frameBuffer;

typedef struct {
    frameBuffer frameBuf;
    memLay memLayout;
} bootInfo;


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
 

void _start(bootInfo kernelInfo) {
    return;
}

