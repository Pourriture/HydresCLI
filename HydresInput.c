#include "HydresInput.h"

int ArrowGet()
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
        printf("getch() error during ArrowGet() operation\nreturning right key by default");
        return RIGHTKEY;
    }
}


int KeyGet()
{
    int loop = 0;
    while (loop == 0)
    {
        loop = getch();
        switch (loop)
        {
        case 1 ... 7:
        case 10 ... 12:
        case 14 ... 26:
            loop = 0;
            break;
        case -32:
        case 224:
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
                }
            default:
            return loop;
        }

    }
    return loop;
}
