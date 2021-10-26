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

    //*Video = 0x40C8;
    /*for(i = 0; i < 8192; i++)
    {
	*Index++;
	*Index = 0x0280

	;
    }*/

    //Draw my test sprite
    *Index = 0xAAAA;     	    // first even line
    Index[4096] = 0x0280;       // first odd line
    Index[40] = 0xAA8A;         // even line
    Index[4096+40] = 0x2A8A;    // odd line
    Index[80] = 0x2A88;         // even line
    Index[4096+80] = 0x828A;    // odd line
    Index[120] = 0x828A;        // even line
    Index[4096+120] = 0xAAAA;   // odd line

    getchar();

    setVideoMode(TEXT_MODE);

    return 0;
}