#include "HydresAdvDisplay.h"

void fieldCDisplay(const field* terrain, const int s_posx, const int e_posx, const int s_posy, const int e_posy)
{
    if ((s_posx < 0) || (s_posy < 0) || (e_posx >= terrain->fsize_x) || (e_posy >= terrain->fsize_y))
    {
        fprintf(stdout,"Error: fieldCDisplay miscalled, either:\n");
        fprintf(stdout,"s_posy %d < 0\n",s_posy);
        fprintf(stdout,"e_posx %d >= terrain->fsize_x %d\n",e_posx,terrain->fsize_x);
        fprintf(stdout,"e_posy %d >= terrain->fsize_y %d\n",e_posy,terrain->fsize_y);
        return;
    }

    int i, j;
    for (i = s_posx ; i <= e_posx ; i++)
    {
        for (j = s_posy ; j <= e_posy ; j++)
        {
            putc(terrain->fbody[i][j].caractere,stdout);
        }
    }
}

