#include "HydresAdvDisplay.h"

void fieldCDisplay(const field* terrain, const int s_posx, const int e_posx, const int s_posy, const int e_posy)
{
    if ((s_posx < 0) || (s_posy < 0) || (e_posx >= terrain->fsize_x) || (e_posy >= terrain->fsize_y))
    {
        fprintf(stdout,"Error: fieldCDisplay miscalled, either:\n");
        fprintf(stdout,"s_posx %d < 0\n",s_posx);
        fprintf(stdout,"s_posy %d < 0\n",s_posy);
        fprintf(stdout,"e_posx %d >= terrain->fsize_x %d\n",e_posx,terrain->fsize_x);
        fprintf(stdout,"e_posy %d >= terrain->fsize_y %d\n",e_posy,terrain->fsize_y);
        return;
    }

    int i, j;
    char* display = NULL;

    for (j = s_posy ; j < e_posy ; j++)
    {
        display = malloc(sizeof(char) * (e_posx - s_posx + 1));
        for (i = s_posx ; i < e_posx ; i++)
        {
            //putc(terrain->fbody[i][j].caractere,stdout);
            display[i] = terrain->fbody[s_posx + i][j].caractere;
        }
        display[e_posx - s_posx] = '\0';

        fputs(display,stdout);
        putc('\n',stdout);

        free(display);
    }


    /*
    for (j = s_posy ; j <= e_posy ; j++)
    {
        for (i = s_posx ; i <= e_posx ; i++)
        {
            putc(terrain->fbody[i][j].caractere,stdout);
        }
        putc('\n',stdout);


    }

    */
}

void fieldACDisplay(const field* terrain, const int s_posx, const int e_posx, const int s_posy, const int e_posy)
{
    if ((s_posx < 0) || (s_posy < 0) || (e_posx >= terrain->fsize_x) || (e_posy >= terrain->fsize_y))
    {
        fprintf(stdout,"Error: fieldACDisplay miscalled, either:\n");
        fprintf(stdout,"s_posx %d < 0\n",s_posx);
        fprintf(stdout,"s_posy %d < 0\n",s_posy);
        fprintf(stdout,"e_posx %d >= terrain->fsize_x %d\n",e_posx,terrain->fsize_x);
        fprintf(stdout,"e_posy %d >= terrain->fsize_y %d\n",e_posy,terrain->fsize_y);
        return;
    }

    HANDLE consoleSc = GetStdHandle(STD_OUTPUT_HANDLE);
    if(consoleSc == INVALID_HANDLE_VALUE)
    {
        fprintf(stdout,"Error: GetStdHandle fail, screen displayed will be stripped of color\n");

        fieldCDisplay(terrain, s_posx, e_posx, s_posy, e_posy);
    }

    int curCol = terrain->fbody[s_posx][s_posy].color, i, j, k = 0;
    char* curStr = malloc(sizeof(char) * (4 * (e_posx - s_posx) + 2));
    SetConsoleTextAttribute(consoleSc, curCol);

    for (j = s_posy ; j <= e_posy ; j++)
    {
        for (i = s_posx ; i <= e_posx ; i++)
        {
            if((terrain->fbody[i][j].color != curCol) && (k != 0))
            {
                curStr[k] = '\0';
                fputs(curStr,stdout);
                free(curStr);
                curStr = NULL;
                k = 0;
                curCol = terrain->fbody[i][j].color;
                SetConsoleTextAttribute(consoleSc, curCol);
                curStr = malloc(sizeof(char) * 4 * (e_posx - s_posx + 2));
            }
            curStr[k] = terrain->fbody[i][j].caractere;
            k++;
            if (k >= 4 * (e_posx - s_posx))
            {
                //curStr = realloc(curStr,sizeof(char) * (4 * (e_posx - s_posx + 3)));
                curStr[k] = '\0';
                fputs(curStr, stdout);
                free(curStr);
                curStr = NULL;
                k = 0;
                curCol = terrain->fbody[i][j].color;
                SetConsoleTextAttribute(consoleSc, curCol);
                curStr = malloc(sizeof(char) * 4 * (e_posx - s_posx + 2));
            }
        }
        curStr[k] = '\n';
        k++;
    }
    if (k != 0)
    {
        curStr[k] = '\0';
        fputs(curStr, stdout);
    }
    if (!curStr)
        free(curStr);



    printf("advDisplay successfully finished.\n");

    /*
    int i, j;
    for (j = s_posy ; j <= e_posy ; j++)
    {
        for (i = s_posx ; i <= e_posx ; i++)
        {
            SetConsoleTextAttribute(consoleSc, terrain->fbody[i][j].color);
            putc(terrain->fbody[i][j].caractere,stdout);
        }
        putc('\n',stdout);
    }

    */
}

void fieldADisplay(const field* terrain)
{
        fieldACDisplay(terrain, 0, terrain->fsize_x - 1, 0, terrain->fsize_y - 1);
}

