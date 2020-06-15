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

	// variables globales
	char title[SIZE_LINE_TITLE];
	char line1[SIZE_LINES];
	char line2[SIZE_LINES];

	// Title, Line1, Line2
	void init_lines();
	void set_line(int opcion, char *text);
	char *get_line(int opcion, char *arr_t);

	// Otros
	void TLE_set_string(int opcio, char *arr_t, int origen, int _final);
	char *TLE_get_string(int opcio, char *arr_t, int origen, int _final);

#ifdef __cplusplus
}
#endif

#endif
