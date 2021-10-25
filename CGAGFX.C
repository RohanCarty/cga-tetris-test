#include "CGAGFX.H"
#include <dos.h>

//Set's the display up to be ready to draw CGA graphics, make sure to call Destroy
int initCGA() // Return 0 on success, -1 on failure
{
    printf("Attempting to initialise CGA Graphics...\n");

	//printf("Placeholder CGA Graphics Library");

    setVideoMode(CGA_4_COLOR_MODE);

    return 0;
}

void setVideoMode(byte mode)
{
  union REGS regs;

  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86(VIDEO_INT, &regs, &regs);
}

int clearScreen()
{
    return 0;
}

void destroyCGA()
{
    setVideoMode(TEXT_MODE);

    return;
}