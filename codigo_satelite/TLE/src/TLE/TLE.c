#include <string.h>
#include "TLE.h"

// -------------------------------------- Title
void set_title(char *text) // done
{
    TLE_set_string(LINE_TITLE, 0, text, SIZE_LINE_TITLE);
}

char *get_title() // done
{
    return protocolo_TLE.title;
}

// -------------------------------------- Line 1
char *get_line1() // to-do
{
    return "devolverá el string tal como dice el estándar";
}

void set_line1_params(int opcion, char *text) // done
{
    switch (opcion)
    {
    case CLASSIFICATION:
        protocolo_TLE.line1[opcion][0] = text;
        break;

    case CATALOG_NUM:
    case INTER_DESIGN_LAUNCH_YEAR:
    case INTER_DESIGN_NUM_YEAR:
    case INTER_DESIGN:
    case EPOCH_YEAR:
    case EPOCH_DAY:
    case FIRST_DERIV_MEAN_MOTION:
    case SECOND_DERIV_MEARN_MOTION:
    case DRAG_TERM:
    case EPHEM_TYPE:
    case ELEM_SET_NUM:
    case CHECKSUM:
        TLE_set_string(LINE_LINE1, opcion, text, strlen(text));
        break;
    }
}

char *get_line1_params(int opcion) // done
{
    switch (opcion)
    {
    case LINE_NUMBER:
        return '1';

    case CLASSIFICATION:
        return protocolo_TLE.line1[CLASSIFICATION][0];

    case CATALOG_NUM:
    case INTER_DESIGN_LAUNCH_YEAR:
    case INTER_DESIGN_NUM_YEAR:
    case INTER_DESIGN:
    case EPOCH_YEAR:
    case EPOCH_DAY:
    case FIRST_DERIV_MEAN_MOTION:
    case SECOND_DERIV_MEARN_MOTION:
    case DRAG_TERM:
    case EPHEM_TYPE:
    case ELEM_SET_NUM:
    case CHECKSUM:
        return protocolo_TLE.line1[opcion];
    }

    return "ERROR";
}

// -------------------------------------- Line 2
void set_line2_params(int opcion, char *text) // to-do
{
    
}

char *get_line2_params(int opcion) // to-do
{
    return "ok";
}

// Otros

void TLE_set_string(int opcio, int n_linia, char *origen, int tamany)
{
    switch (opcio)
    {
    case LINE_TITLE:

        for (int i = 0; i < tamany; i++)
        {
            protocolo_TLE.title[i] = origen[i];
        }
        break;

    case LINE_LINE1:

        for (int i = 0; i < tamany; i++)
        {
            protocolo_TLE.line1[n_linia][i] = origen[i];
        }
        break;

    case LINE_LINE2:

        for (int i = 0; i < tamany; i++)
        {
            protocolo_TLE.line2[i] = origen[i];
        }
        break;

    default:
        break;
    }
}