#include <stdio.h>
#include "CGAGFX.H"

int main()
{
    printf("Hello World\n");

    initCGA();

    delay(3000);

    destroyCGA();

    return 0;
}