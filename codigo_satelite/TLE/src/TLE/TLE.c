#include <string.h>
#include "TLE.h"

void init_lines()
{
    for (int i = 0; i < SIZE_LINE_TITLE; i++)
    {
        title[i] = ' ';
    }

    for (int i = 0; i < SIZE_LINES; i++)
    {
        if (i == LINE1_NUM)
        {
            line1[i] = '1';
            continue;
        }

        line1[i] = ' ';
    }

    for (int i = 0; i < SIZE_LINES; i++)
    {
        if (i == LINE2_NUM)
        {
            line2[i] = '2';
            continue;
        }
        line2[i] = ' ';
    }
}

// -------------------------------------- Title, Line 1, Line2
void set_line(int opcion, char *text) // Done
{
    int pos_inicio = opcion;
    int pos_final = 0;

    switch (opcion)
    {
    // Genéricos
    case LINE_TITLE:
        TLE_set_string(LINE_TITLE, text, 0, strlen(text));
        return;

    case LINE1:
        pos_inicio = 0;
        pos_final = SIZE_LINES - 1; //strlen(text);
        break;

    case LINE2:
        TLE_set_string(LINE_LINE2, text, 0, SIZE_LINES - 1);
        return;

    // Line 1
    case LINE1_CLASSIFICATION:
        pos_final = LINE1_CLASSIFICATION_END;
        break;

    case LINE1_CATALOG_NUM:
        pos_final = LINE1_CATALOG_NUM_END;
        break;

    case LINE1_INTERN_DES_LAUNCH_YEAR:
        pos_final = LINE1_INTERN_DES_LAUNCH_YEAR_END;
        break;

    case LINE1_INTERN_DES_LAUNCH_NUM_YEAR:
        pos_final = LINE1_INTERN_DES_LAUNCH_NUM_YEAR_END;
        break;

    case LINE1_INTERN_DESIGN:
        pos_final = LINE1_INTERN_DESIGN_END;
        break;

    case LINE1_EPOCH_YEAR:
        pos_final = LINE1_EPOCH_YEAR_END;
        break;

    case LINE1_EPOCH_DAY:
        pos_final = LINE1_EPOCH_DAY_END;
        break;

    case LINE1_FIRST_DERIV_MEAN_MOTION:
        pos_final = LINE1_FIRST_DERIV_MEAN_MOTION_END;
        break;

    case LINE1_SECOND_DERIV_MEAN_MOTION:
        pos_final = LINE1_SECOND_DERIV_MEAN_MOTION_END;
        break;

    case LINE1_DRAG_TERM_COEF:
        pos_final = LINE1_DRAG_TERM_COEF_END;
        break;

    case LINE1_EPHEMERIS:
        pos_final = LINE1_EPHEMERIS_END;
        break;

    case LINE1_ELEM_SET_NUM:
        pos_final = LINE1_ELEM_SET_NUM_END;
        break;

    case LINE1_CHECKSUM:
        pos_final = LINE1_CHECKSUM_END;
        break;

        // Line 2
    }

    TLE_set_string(LINE_LINE1, text, pos_inicio, pos_final);
}

char *get_line(int opcion, char *arr_t) // Done
{
    int pos_final = 0;

    switch (opcion)
    {
    // Genéricos
    case LINE_TITLE:
        return TLE_get_string(LINE_TITLE, arr_t, 0, SIZE_LINE_TITLE - 1); //strlen(title));

    case LINE1:
        opcion = 0;
        pos_final = SIZE_LINES - 1;
        break;

    case LINE2:
        pos_final = SIZE_LINES - 1;
        return TLE_get_string(LINE_LINE2, arr_t, 0, pos_final);

    // Line 1
    case LINE1_NUM:
        return "1";
    case LINE1_CLASSIFICATION:
        pos_final = LINE1_CLASSIFICATION;
        break;
    case LINE1_CATALOG_NUM:
        pos_final = LINE1_CATALOG_NUM_END;
        break;
    case LINE1_INTERN_DES_LAUNCH_YEAR:
        pos_final = LINE1_INTERN_DES_LAUNCH_YEAR_END;
        break;
    case LINE1_INTERN_DES_LAUNCH_NUM_YEAR:
        pos_final = LINE1_INTERN_DES_LAUNCH_NUM_YEAR_END;
        break;
    case LINE1_INTERN_DESIGN:
        pos_final = LINE1_INTERN_DESIGN_END;
        break;
    case LINE1_EPOCH_YEAR:
        pos_final = LINE1_EPOCH_YEAR_END;
        break;
    case LINE1_EPOCH_DAY:
        pos_final = LINE1_EPOCH_DAY_END;
        break;
    case LINE1_FIRST_DERIV_MEAN_MOTION:
        pos_final = LINE1_FIRST_DERIV_MEAN_MOTION_END;
        break;
    case LINE1_SECOND_DERIV_MEAN_MOTION:
        pos_final = LINE1_SECOND_DERIV_MEAN_MOTION_END;
        break;
    case LINE1_DRAG_TERM_COEF:
        pos_final = LINE1_DRAG_TERM_COEF_END;
        break;
    case LINE1_EPHEMERIS:
        pos_final = LINE1_EPHEMERIS_END;
        break;
    case LINE1_ELEM_SET_NUM:
        pos_final = LINE1_ELEM_SET_NUM_END;
        break;
    case LINE1_CHECKSUM:
        pos_final = LINE1_CHECKSUM_END;
        break;

        // Line 2
    }

    return TLE_get_string(LINE_LINE1, arr_t, opcion, pos_final);
}

// Otros
void TLE_set_string(int opcio, char *arr_t, int origen, int _final)
{
    int j = 0;
    int i = 0;
    switch (opcio)
    {
    case LINE_TITLE:
        for (i = origen; i < _final; i++)
        {
            title[i] = arr_t[i];
        }
        title[i] = 0x00;
        break;

    case LINE_LINE1:

        for (i = origen; i <= _final; i++)
        {
            line1[i] = arr_t[j];
            j++;
        }
        break;

    case LINE_LINE2:

        for (i = origen; i <= _final; i++)
        {
            line2[i] = arr_t[j];
            j++;
        }
        break;

    default:
        break;
    }
}

char *TLE_get_string(int opcio, char *arr_t, int origen, int _final)
{
    int j = 0;

    switch (opcio)
    {
    case LINE_TITLE:

        for (int i = origen; i < _final; i++)
        {
            arr_t[j] = title[i];
            j++;
        }
        break;

    case LINE_LINE1:

        for (int i = origen; i <= _final; i++)
        {
            arr_t[j] = line1[i];
            j++;
        }
        break;

    case LINE_LINE2:

        for (int i = origen; i <= _final; i++)
        {
            arr_t[j] = line2[i];
            j++;
        }
        break;
    }

    arr_t[j] = 0;
    return arr_t;
}
