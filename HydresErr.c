#include "HydresErr.h"
static void HydresErrSwitch (int no);

void HydresErr(int no)
{
    fputs(DEFAULT_ERR_MESS,errstream);
    HydresErrSwitch(no);
    herr.x = 0;
    herr.y = 0;
    herr.err = 0;
    int i;
    for (i = 0; i < SIZE_HERR_T ; i++)
        herr.t[i] = 0;
}

static void HydresErrSwitch(int no)
{
    switch (no)
    {
    case S_ERR:
        #ifdef WIN32
        fprintf(errstream, "Error while using a standard function : %s", strerror(errno));
        #elif
        fprintf(errstream, "Error while using a standard function : %s", strerror_r(errno));
        #endif
        break;
    case err_fieldInitialize_OutOfMemory:
        fprintf(errstream, "fieldInitialize ran out of usable memory (allocation attempt : %d bytes)",herr.x);
        break;
    case err_fieldInitialize_Misc:
        fprintf(errstream, "fieldInitialize() attempt to create a negative-size : x %d or y %d", herr.x, herr.y);
        break;
    case err_fieldDestroy:
        fprintf(errstream, "Can't use fieldDestroy on NULL");
        break;
    case err_copy_no_source:
        fprintf(errstream, "No field to copy @ NULL");
        break;
    case err_display_no_source:
        fprintf(errstream, "No field to display @ NULL");
        break;
    case err_fuse_size:
        fprintf(errstream, "Error fusing fields: pasted element is misplaced or too big for the target (x %d > sx %d or y %d > sy %d)\n", herr.t[0], herr.t[1],herr.t[2],herr.t[3]);
        switch (herr.err)
        {
        case errtag_sfuse:
            fputs("tag : fieldFuse",errstream);
            break;
        case errtag_stfuse:
            fputs("tag : fieldFuseST", errstream);
            break;
        }
        break;
    case err_fuse_nosource:
        fprintf(errstream,"Error fusing fields: either arg 1 (%s) or arg 2 (%s) is NULL (tag : %s)",(herr.x & 1) ? "yes" : "no", (herr.x & 2) ? "yes" : "no", (herr.x & 4) ? "seethrough" : "normal");
        break;
    case err_append_nosource:
        fprintf(errstream,"Error appending fields: either arg 1 (%s) or arg 2 (%s) is NULL",(herr.x & 1) ? "yes" : "no", (herr.x & 2) ? "yes" : "no");
        break;
    case err_paint_nosource:
        fprintf(errstream, "Error painting a field : source is NULL");
        break;
    case err_paint_miscall:
        fprintf(errstream,"Error: fieldPaintPart miscalled, either:\n");
        fprintf(errstream,"s_x %d < 0\n",herr.t[0]);
        fprintf(errstream,"s_y %d < 0\n",herr.t[1]);
        fprintf(errstream,"e_x %d >= terrain->fsize_x %d\n",herr.t[2],herr.x);
        fprintf(errstream,"e_y %d >= terrain->fsize_y %d\n",herr.t[3],herr.y);
        break;
    case err_inputstring_nosource:
        fprintf(errstream,"Error calling fieldInputString : source is NULL");
        if (herr.x == 1)
            HydresErrSwitch(err_misc_oom);
        break;
    case err_misc_oom:
        fprintf(errstream,"\nMiscellanous error - Out of memory\n");
        HydresErrSwitch(S_ERR);
        exit(EXIT_FAILURE);
        break;
    case err_strpaste_nosource:
        fprintf(errstream,"Error pasting a string : source is NULL");
        break;
    case err_strextract_nosource:
        fprintf(errstream,"Error extracting a string : source is NULL");
        if (herr.x)
            HydresErrSwitch(err_misc_oom);
        break;



    }

}




