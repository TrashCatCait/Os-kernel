#ifndef GUI_H
#define GUI_H
#include <typedefs.h>

void setup_bfr(framebfr_t *fb);
void clear_gui(uint8_t color);
void draw_vline(uint8_t color, uint32_t x);
void draw_hline(uint8_t color, uint32_t y);
void draw_rect(uint8_t color, uint32_t sx, uint32_t ex, uint32_t sy, uint32_t ey);
void putpixel(uint32_t x, uint32_t y, uint8_t color);
void load_font(bootinfo_t *bi);
void draw_str8x16(char *string, uint8_t color, uint32_t x, uint32_t y);
void draw_char8x16(char c, uint8_t color, uint32_t x, uint32_t y); 


#endif
