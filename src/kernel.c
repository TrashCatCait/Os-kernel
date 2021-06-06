typedef struct {
    int memMapSize;
    int descriptSize;
    int mapKey;
    void* map;
    int descriptVer;
} boot_info;

int _start(boot_info BI)
{
    char *vidmem = (char*)0xb8000;
    vidmem[1] = 'h';
    return 1922;
}
