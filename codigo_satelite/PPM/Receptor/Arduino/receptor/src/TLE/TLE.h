/*
	-------------------Fuente--------------------
	https://en.wikipedia.org/wiki/Two-line_element_set
	---------------------------------------------
*/

#ifndef _TLE_h_
#define _TLE_h_

#ifdef __cplusplus // para que pille C, ya que arduino usa C++
extern "C"
{
#endif

#include "TLE_defines.h"

	void init_line(int opcion, char *_array); // qué linea tocar (title, line1, line2), array de la línea
	void set_line(int opcion, char *text, char* arr_retorno); //(title, line1, line2), texto a cambiar, retorno línea cambiada
	char *get_line(int opcion, char *arr_envio); //(title, line1, line2), retorno línea cambiada

#ifdef __cplusplus
}
#endif

#endif
