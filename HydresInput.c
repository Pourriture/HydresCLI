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

int CharGet()
{
    int loop = 0;
    while (loop == 0)
    {
        loop = getch();
        switch(loop)
        {
        case 13:
            loop = ENTERKEY;
            break;
        case 8:
            loop = ERASEKEY;
            break;
        case -32:
        case 224:
            getch();
        case 1 ... 7:
        case 9 ... 12:
        case 14 ... 26:
            loop = 0;
            break;
        }
    }
    return loop;
}

char* fieldInputString(field* source, int posx, int posy, int length)
{
    field* tempDisplay = NULL;
    char input = 0, *string = malloc(sizeof(char) * length), *dstring = malloc(sizeof(char) * (length + 1));
    int loop = 1, counter = 0, i, lastErased = 0;

    for (i = 0 ; i < length ; i++)
        string[i] = ' ';

    while (loop)
    {
        for(i = 0 ; i < length ; i++)
        {
            dstring[i] = string[i];
        }
        dstring[length] = '\0';

        tempDisplay = fsFuse(source,dstring,posx, posy, source->fbody[posx][posy].color);
        if (counter < length)
            tempDisplay->fbody[posx + counter][posy].color = BACKGROUND_WHITE;
        else
            tempDisplay->fbody[posx + length - 1][posy].color = BACKGROUND_WHITE;

        if ((!((input == ERASEKEY) && (counter == 0)) && (counter <= length)) || lastErased)
        {
            system("cls");
            fieldADisplay(tempDisplay);
            lastErased = 0;
        }


        fieldDestroy(tempDisplay);


        input = CharGet();

        if (counter >= MAX_INPUT_LENGTH)
        {
            input = ERASEKEY;
        }

        if (input == ENTERKEY)
        {
            string[counter] = '\0';
            loop = 0;
            for (i = 0 ; i < length ; i++)
            {
                dstring[i] = string[i];
            }
            dstring[length] = '\0';
            fsPaste(source, dstring, posx, posy, source->fbody[posx][posy].color);



        }
        else if (input == ERASEKEY)
        {
            if (counter == 1)
                lastErased = 1;
            if (counter > 0)
                counter--;

            string[counter] = ' ';
        }
        else
        {
            if (counter >= length)
            {
                string = realloc(string, sizeof(char) * (counter + 3));
            }


            string[counter] = input;
            counter++;
        }
    }



    free(dstring);
    return string;
}

void fieldInStr(field* t, int x, int y, int l)
{
    free(fieldInputString(t, x,y, l));
}

