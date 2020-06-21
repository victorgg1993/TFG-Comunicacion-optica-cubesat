#include <string.h>
#include "TLE.h"

void init_line(int opcion, char *_array)
{
    int i = 0;

    for (i = 0; i < SIZE_LINES; i++)
    {
        _array[i] = ' ';

        if (opcion == LINE1 && i == LINE1_NUM)
        {
            _array[i] = '1';
        }
        else if (opcion == LINE2 && i == LINE2_NUM)
        {
            _array[i] = '2';
        }
    }
    _array[SIZE_LINES - 1] = 0; // evitamos overflows
}

void set_line(int opcion, char *text, char *arr_retorno)
{
    int pos_inicio = opcion;
    int pos_final = 0;

    switch (opcion)
    {
    // Genéricos
    case LINE_TITLE:
        pos_inicio = 0;
        pos_final = strlen(text) - 1;
        break;

    // Line 1
    case LINE1_CLASSIFICATION: // 1 solo char
    case LINE1_EPHEMERIS:
    case LINE1_CHECKSUM:    // también case LINE2_CHECKSUM:
        pos_final = opcion;
        break;

    case LINE1_INTERN_DES_LAUNCH_YEAR: //2 chars
    case LINE1_EPOCH_YEAR:
    case LINE1_INTERN_DES_LAUNCH_NUM_YEAR: // 3 chars
    case LINE1_INTERN_DESIGN:
    case LINE1_ELEM_SET_NUM: // 4 chars
    // 5 chars
    case LINE1_CATALOG_NUM: // también case LINE2_CATALOG_NUM:
    case LINE2_REVOLUTIONS:
    case LINE2_ECCENTRICITY:             // 7 chars
    case LINE1_SECOND_DERIV_MEAN_MOTION: // 8 chars
    case LINE1_DRAG_TERM_COEF:
    case LINE2_INCLINATION:
    case LINE2_RIGHT_ASCEN:
    case LINE2_PERIGEE:
    case LINE2_MEAN_ANOMALY:
    case LINE1_FIRST_DERIV_MEAN_MOTION: // 10 chars
    case LINE2_MEAN_MOTION:             // 11 chars
    case LINE1_EPOCH_DAY:               // 12 chars
        pos_final = opcion + strlen(text) - 1;
        break;
    }

    int j = 0;
    for (int i = pos_inicio; i <= pos_final; i++)
    {
        arr_retorno[i] = text[j];
        j++;
    }
}

char *get_line(int opcion, char *arr_lectura)
{
    static char arr_retorno[SIZE_LINES];
    int pos_final = 0;
    int j = 0;

    switch (opcion)
    {
    case LINE_TITLE:
        opcion = 0;
        pos_final = SIZE_LINE_TITLE;
        break;

    case LINE1:
    case LINE2:
        opcion = 0;
        pos_final = (SIZE_LINES - 1);
        break;

    case LINE1_NUM: // también case LINE2_NUM:
    case LINE1_CLASSIFICATION: // 1 solo char
    case LINE1_EPHEMERIS:
    case LINE1_CHECKSUM:   // también case LINE2_CHECKSUM:
        pos_final = opcion;
        break;

    case LINE1_INTERN_DES_LAUNCH_YEAR: //2 chars
    case LINE1_EPOCH_YEAR:
        pos_final = (opcion + 1);
        break;

    case LINE1_INTERN_DES_LAUNCH_NUM_YEAR: // 3 chars
    case LINE1_INTERN_DESIGN:
        pos_final = (opcion + 2);
        break;

    case LINE1_ELEM_SET_NUM: // 4 chars
        pos_final = (opcion + 3);
        break;

        // 5 chars
    case LINE1_CATALOG_NUM: // también case LINE2_CATALOG_NUM: , son el mismo
    case LINE2_REVOLUTIONS:
        pos_final = (opcion + 4);
        break;

    case LINE2_ECCENTRICITY: // 7 chars
        pos_final = (opcion + 6);
        break;

    case LINE1_SECOND_DERIV_MEAN_MOTION: // 8 chars
    case LINE1_DRAG_TERM_COEF:
    case LINE2_INCLINATION:
    case LINE2_RIGHT_ASCEN:
    case LINE2_PERIGEE:
    case LINE2_MEAN_ANOMALY:
        pos_final = (opcion + 7);
        break;

    case LINE1_FIRST_DERIV_MEAN_MOTION: // 10 chars
        pos_final = (opcion + 9);
        break;

    case LINE2_MEAN_MOTION: // 11 chars
        pos_final = (opcion + 10);
        break;

    case LINE1_EPOCH_DAY: // 12 chars
        pos_final = (opcion + 11);
        break;
    }

    for (int i = opcion; i <= pos_final; i++)
    {
        if (arr_lectura[i] == 0) // si contiene un char final de string, romperá la línea
        {
            arr_lectura[i] = ' ';
        }
        else
        {
            arr_retorno[j] = arr_lectura[i];
        }
        j++;
    }
    arr_retorno[j] = 0;
    return arr_retorno;
}