#include "UV_dat.h"

void writeUV(UV_def *UV_source)
{
    UV_file UV_w;
    int i;
    for (i = 0 ; i <= 4 ; i++)
    {
        UV_w.name[i] = UV_source->name[i];
    }
    UV_w.hours = UV_source->hCM;
    UV_w.hours += UV_source->hTD * 0x100;
    UV_w.hours += UV_source->hTP * 0x10000;

    FILE* fichier = fopen(UV_DATABASE_FILE,"r+");
    if (!fichier)
    {
        printf("Erreur : impossible d'ouvrir %s\n",UV_DATABASE_FILE);
    }

    fseek(fichier, 0, SEEK_SET);

    if (UV_source->ID == 0)      // Opérations à effectuer si l'UV est encore inconnue (ID 0)
    {
        if(getc(fichier) == EOF)
        {
            fseek(fichier, 0, SEEK_SET);
            UV_w.ID = 1;
            fwrite(&UV_w, sizeof(UV_file),1,fichier);
        }
        else
        {
            fseek(fichier, - sizeof(UV_file),SEEK_END);
            UV_file lastUV;
            fread(&lastUV, sizeof(UV_file), 1, fichier);
            UV_w.ID = lastUV.ID + 1;
            UV_source->ID = UV_w.ID;

        }
    }
    else            //  Si l'UV est connue (ID != 0), il s'agit alors d'une opération d'édition
    {
        fseek(fichier, sizeof(UV_file) * UV_source->ID, SEEK_SET);

    }

    fclose(fichier);
}

void readUV(UV_def* UV, long ID)
{
    UV->ID = ID;
    FILE* fichier = fopen(UV_DATABASE_FILE,"r");
    fseek(fichier, ID * sizeof(UV_file), SEEK_SET);




}
