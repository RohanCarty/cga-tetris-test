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

void clearScreen(int a_iColour)
{
    for(unsigned int uiDx = 0; uiDx < SCREEN_WIDTH; uiDx++)
    {
        for(unsigned int uiDy = 0; uiDy < SCREEN_HEIGHT; uiDy++)
        {
            g_ScreenBuffer[uiDx][uiDy] = (byte)a_iColour;
        }
    }

    return;
}

void destroyCGA()
{
    setVideoMode(TEXT_MODE);

    return;
}