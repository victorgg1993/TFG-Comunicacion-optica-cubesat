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

	// Struct
	typedef struct TLE
	{
		char title[SIZE_LINE_TITLE];
		char line1[14][12]; // [Y][X]
		char line2[70];		// trabajar, no tenemos que estar sumando y restando índices
	} TLE;

	TLE protocolo_TLE;

	// Funciones Title
	void set_title(char *titol);
	char *get_title();

	// Funciones Line 1
	char *get_line1();

	void set_line1_params(int opcion, char *text);
	char *get_line1_params(int opcion);

	// Funciones Line 2
	void set_line2_params(int opcion, char *text);
	char *get_line2_params(int opcion);

	// Otros
	void TLE_set_string(int opcio, int n_linia, char *origen, int tamany);

#ifdef __cplusplus
}
#endif

#endif
