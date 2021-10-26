#include <stdio.h>
#include <dos.h>

#define VIDEO_INIT 0x10
#define SET_MODE 0x00
#define VIDEO_MODE 0x04
#define TEXT_MODE 0x03
typedef unsigned char byte;

void setVideoMode(byte mode)
{
	union REGS regs;
	regs.h.ah = SET_MODE;
	regs.h.al = mode;
	int86(VIDEO_INIT, &regs, &regs);
}

int main()
{
	int i;
    unsigned short int far *Video = (unsigned short int far *)MK_FP(0xB800,0x0000);
    unsigned short int far *Index = Video;

    setVideoMode(VIDEO_MODE);

    *Video = 0xFFFF;
    for(i = 0; i < 8192; i++)
    {
	*Index++;
	*Index = 0x5656

	;
    }

    getchar();

    setVideoMode(TEXT_MODE);

    return 0;
}