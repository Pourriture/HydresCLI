#include "HydresFile.h"

field* fieldFromFile(const char* filename)
{
    FILE* fichier = fopen(filename, "r");
    if (fichier == NULL)
    {
        fprintf(stderr,"Runtime error: out of memory during file opening\n");
        exit(EXIT_FAILURE);
    }
    rewind(fichier);

    char colorStatus;

    int size_x, size_y, color, i, j;
    fscanf(fichier,"%c %d %d %d",&colorStatus,&size_x,&size_y,&color);


    char current;
    current = getc(fichier);        //on passe le saut de ligne

    field* terrain = fieldInitialize(size_x,size_y);

    if (colorStatus == 'N')
    {


        for(j = 0 ; j < size_y ; j++)
        {
            for (i = 0 ; i < size_x ; i++)
            {
                current = getc(fichier);
                if ((current == '\n') || (current == EOF))
                {
                    for (i = i ; i < size_x ; i++)
                    {
                        terrain->fbody[i][j].caractere = ' ';
                    }
                }
                else
                    terrain->fbody[i][j].caractere = current;

            }
            terrain->fbody[i][j].color = color;
            if (current != '\n')
                current = getc(fichier);
        }
    }
    else if (colorStatus == 'C')
    {
        for(j = 0 ; j < size_y ; j++)
        {
            for (i = 0 ; i < size_x ; i++)
            {
                fscanf(fichier,"%c%d",&current,&color);
                if ((current == '\n') || (current == EOF))
                {
                    for (i = i ; i < size_x ; i++)
                    {
                        terrain->fbody[i][j].caractere = ' ';
                        terrain->fbody[i][j].color = DEFAULT_F_PART_COLOR;
                    }
                }
                else
                    terrain->fbody[i][j].caractere = current;
                    terrain->fbody[i][j].color = color;
            }
            if (current != '\n')
                current = getc(fichier);
        }
    }

    fclose(fichier);
    return terrain;
}

void fieldToFile(const char* filename, const field* terrain, const int color)
{
    FILE* fichier = fopen(filename,"w+");
    int size_x = terrain->fsize_x, size_y = terrain->fsize_y, i, j;
    fprintf(fichier,"N %d %d %d\n",size_x, size_y, color);
    for(j = 0 ; j < size_y ; j++)
    {
        for (i = 0 ; i < size_x ; i++)
        {
            putc(terrain->fbody[i][j].caractere, fichier);
        }
        putc('\n', fichier);
    }

    fclose(fichier);
}

void fieldCToFile(const char* filename, const field* terrain)
{
    FILE* fichier = fopen(filename, "w+");
    int size_x = terrain->fsize_x, size_y = terrain->fsize_y, i, j;
    fprintf(fichier,"C %d %d %d\n", size_x, size_y, DEFAULT_F_PART_COLOR);
    for(j = 0 ; j < size_y ; j++)
    {
        for (i = 0 ; i < size_x ; i++)
        {
            fprintf(fichier,"%c%d",terrain->fbody[i][j].caractere,terrain->fbody[i][j].color);
        }
        putc('\n', fichier);
    }

    fclose(fichier);

}
