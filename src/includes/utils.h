#ifndef UTILS_H
#define UTILS_H

#include "inttypes.h"
//same structs as what is found in the EFI program we just use different typedefs.
//As I personally prefer UNIX and LINUX like typedefs over UEFI typedefs
typedef struct memLay {
    void *memMap;
    uint64_t mapSize;
    uint64_t descSize;
} efimemory_t;

typedef struct frameBuffer {
    void* baseAdd;
    size_t bufferSize;
    uint32_t width;
    uint32_t height;
    uint32_t scanLine; // pixels per scan line
} framebuffer_t;


typedef struct bootInfo {
    framebuffer_t frameBuf;
    efimemory_t memLayout;
} efiinfo_t;

//Use details taken from GOP is to write to pixels.
void plot_pixel_gop(int pixelPerSL, int x, int y, uint32_t pixel, void *buffer);


//gop clear screen function 
void clr_scr_gop(uint32_t pixelPerSL, uint32_t width, uint32_t height, uint32_t pixel, void *buffer);

#endif
