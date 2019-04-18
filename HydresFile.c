#include "HydresFile.h"

field* fieldFromFile(const char* filename)
{
    FILE* fichier = fopen(filename, "r");
    if (fichier == NULL)
    {
        fprintf(stderr,"Runtime error: out of memory during file opening\n");
        puts(strerror(errno));
        exit(EXIT_FAILURE);
    }
    rewind(fichier);

    int size_x, size_y, i, j;
    fscanf(fichier,"%d %d",&size_x,&size_y);


    char current;
    current = getc(fichier);        //on passe le saut de ligne

    field* terrain = fieldInitialize(size_x,size_y);
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
        if (current != '\n')
            current = getc(fichier);
    }

    fclose(fichier);
    return terrain;
}

void fieldToFile(const char* filename, const field* terrain)
{
    FILE* fichier = fopen(filename,"w+");
    int size_x = terrain->fsize_x, size_y = terrain->fsize_y, i, j;
    fprintf(fichier,"%d %d\n",size_x, size_y);
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
