//CGA Graphics Library
#include <stdio.h>
#include <dos.h>

#ifdef WIN32
// Forward declare some dos specific items for VSCode to throw less errors
struct WORDREGS {
	unsigned int	ax, bx, cx, dx, si, di, cflag, flags;
};

struct BYTEREGS {
	unsigned char	al, ah, bl, bh, cl, ch, dl, dh;
};

union	REGS	{
	struct	WORDREGS x;
	struct	BYTEREGS h;
};

int	 int86	(int __intno, union REGS *__inregs, union REGS *__outregs);
void delay	(unsigned __milliseconds);

//finished with our forward declarations
#endif

#define VIDEO_INT           0x10      /* the BIOS video interrupt. */
#define WRITE_DOT           0x0C      /* BIOS func to plot a pixel. */
#define SET_MODE            0x00      /* BIOS func to set the video mode. */
#define VGA_256_COLOR_MODE  0x13      /* use to set 256-color mode. */
#define CGA_4_COLOR_MODE    0x06      /* use for CGA 4-color mode. */
#define TEXT_MODE           0x03      /* use to set 80x25 text mode. */

#define SCREEN_WIDTH        320       /* width in pixels of mode 0x06 */
#define SCREEN_HEIGHT       200       /* height in pixels of mode 0x06 */
#define NUM_COLORS          4       /* number of colors in mode 0x06 */

typedef unsigned char  byte;
typedef unsigned short word;

int initCGA();
void setVideoMode(byte mode);
int clearScreen();
void destroyCGA();