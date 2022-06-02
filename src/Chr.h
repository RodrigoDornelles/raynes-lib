#ifndef _LIB_CHR_H
#define _LIB_CHR_H
#include <fcntl.h>
#include <raylib.h>
#include <unistd.h>

struct ChrSprite {
    unsigned char color1[8];
    unsigned char color2[8];
};

union ChrLoad {
    unsigned char raw[0x2000];
    struct ChrSprite sprite[512];
};

struct ChrPPU {
    union ChrLoad chrAdddress;
    Texture2D spriteTexture[4][512];
};

void ChrLoadFile(const char *fileName);
void ChrLoadPalette(const char *paletteBuffer);
void ChrDrawSprite(int spriteId, int posX, int posY, int paletteId);

#endif
