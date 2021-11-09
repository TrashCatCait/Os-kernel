#include <typedefs.h>
#include <gui.h>


static uint32_t *buffer_base;
static uint64_t size; 
static uint32_t width;
static uint32_t height;
static uint32_t ppsl;
static uint8_t *font;

void setup_bfr(framebfr_t *fb) {
    buffer_base = fb->buffer_base;
    size = fb->size;
    width = fb->width;
    height = fb->height;
    ppsl = fb->ppsl;
}

void clear_gui(uint8_t color) {
    for(size_t index = 0; index < size; index++) {
        buffer_base[index] = 0x000000ff;
    }
}

void draw_vline(uint8_t color, uint32_t x) {
    for(int i = 0; i < size; i += 320) {
	buffer_base[i+x] = color;
    }
}

void draw_hline(uint8_t color, uint32_t y) {
    for(int i = 0; i < width; i++) {
	buffer_base[i+(y*width)] = color;
    }
}

void draw_rect(uint8_t color, uint32_t sx, uint32_t ex, uint32_t sy, uint32_t ey){
    draw_hline(color, sy);
    draw_hline(color, ey);
    draw_vline(color, sx);
    draw_vline(color, ex);
}

void putpixel(uint32_t x, uint32_t y, uint8_t color) {
    buffer_base[x+y*320] = color;
}

void load_font(bootinfo_t *bi) {
    font = bi->fontmap;
}


void draw_str8x16(char *string, uint8_t color, uint32_t x, uint32_t y) {
    while(*string != 0) {
	draw_char8x16(*string, color, x, y);
	x += 8;
	if(x >= 320) {
	    x = 0;
	    y += 16;
	}
	string++;
    }
}

void draw_char8x16(char c, uint8_t color, uint32_t x, uint32_t y) {
    uint32_t cx,cy;
    int bitmask[8] = {128,64,32,16,8,4,2,1}; //masks for checking if bits set 
    uint8_t *glyph = font+(int)c*16;

    for(cy = 0; cy < 16; cy++) {
	for(cx = 0; cx < 8; cx++) {
	    putpixel(x+cx, y+cy, glyph[cy]&bitmask[cx]?color:0x00);
	}
    }
}
