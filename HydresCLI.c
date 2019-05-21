#include "HydresCLI.h"



field* fieldInitialize(const int size_x, const int size_y)
{
    field* terrain = malloc(sizeof(*terrain));
    short int errset = 0;
    if (size_x < 1)
    {
        fprintf(stdout,"Runtime error : tried to initialize a field with a nil or negative x size (%d)\n",size_x);
        errset = 1;
    }
    if (size_y < 1)
    {
        fprintf(stdout,"Runtime error : tried to initialize a field with a nil or negative y size (%d)\n",size_y);
        errset = 1;
    }
    if (errset)
        exit(EXIT_FAILURE);

    terrain->fsize_x = size_x;
    terrain->fsize_y = size_y;

    f_part* ptrToFPart = NULL;
    terrain->fbody = malloc(sizeof(ptrToFPart) * size_x);
    //printf("Entry point: fbody located at %p\n",terrain->fbody);
    if (terrain->fbody == NULL)
    {
        fprintf(stdout,"Runtime error : out of memory during field initialization\n");
        exit(EXIT_FAILURE);
    }

    terrain->fsize_x = size_x;
    terrain->fsize_y = size_y;


    int i,j;
    for (i = 0 ; i < size_x ; i++)
    {
        terrain->fbody[i] = malloc(sizeof(f_part) * size_y);
        if (terrain->fbody[i] == NULL)
        {
            fprintf(stdout,"Runtime error : out of memory during field initialization\n");
            exit(EXIT_FAILURE);
        }

        for (j = 0 ; j < size_y ; j++)
        {
            terrain->fbody[i][j].caractere = DEFAULT_F_PART_CHAR;
            terrain->fbody[i][j].color = DEFAULT_F_PART_COLOR;
            //printf("initialized [%d][%d] of terrain : %c at address %p, accessed from %p\n",i,j,terrain->fbody[i][j].caractere,&terrain->fbody[i][j],terrain->fbody[i]);
        }
    }







    return terrain;
}




void fieldDestroy(field* terrain)
{
    int i;
    for (i = 0 ; i < terrain->fsize_x ; i++)
    {
        //printf("Freeing memory at %p...",terrain->fbody[i]);
        free(terrain->fbody[i]);
        //printf("freed!\n");
    }
    free(terrain->fbody);
    free(terrain);

}

void fieldDisplay(const field* terrain)
{




    int i, j, size_x = terrain->fsize_x, size_y = terrain->fsize_y;

    char* display = NULL;




    for (j = 0 ; j < size_y ; j++)
    {
        display = malloc(sizeof(char) * (size_x + 1));
        for (i = 0 ; i < size_x ; i++)
        {
            //putc(terrain->fbody[i][j].caractere,stdout);
            display[i] = terrain->fbody[i][j].caractere;
        }
        display[size_x] = '\0';

        fputs(display,stdout);
        putc('\n',stdout);

        free(display);
    }
}

/*
field* fieldReInitialize(field* terrain, const int size_x, const int size_y)
{
    fieldDestroy(terrain);
    terrain = fieldInitialize(size_x, size_y);
    return terrain;
}
*/

field* fieldCopy(const field* source)
{
    //printf("fieldCopy called\n");

    int i, j, size_x = source->fsize_x, size_y = source->fsize_y;
    field* target = fieldInitialize(size_x, size_y);

    //printf("target initialised\n");

    for (i = 0 ; i < size_x ; i++)
    {
        for (j = 0 ; j < size_y ; j++)
        {
            target->fbody[i][j].caractere = source->fbody[i][j].caractere;
            target->fbody[i][j].color = source->fbody[i][j].color;

        }
    }
    return target;
}


