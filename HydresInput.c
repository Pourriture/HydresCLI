#include "HydresInput.h"

int KeyGet()
{
    int loop = 1;
    while ((loop != -32) && (loop != 224))
    {
        loop = getch();
    }
    switch(getch())
    {
    case 72:
        return UPKEY;
    case 75:
        return LEFTKEY;
    case 80:
        return DOWNKEY;
    case 77:
        return RIGHTKEY;
    default:
        printf("getch() error during KeyGet() operation\nreturning right key by default");
        return RIGHTKEY;
    }
}
