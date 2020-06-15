/*
  Ejemplo de cómo acceder a los distintos strings del TLE.
  No necesita el emisor ARM, simplemente escribe y lee
  La librería está dentro de src/ porque sino la IDE
  de arduino no lo encuentra.
*/

#include "src/TLE/TLE.h"

void setup()
{
  init_lines(); // las limpiamos

  Serial.begin(9600);
  Serial.println("------------------------------------");
  Serial.println("Ejemplo implementación protocolo TLE");
  Serial.println("------------------------------------\n\n");

 
  // Title
  Serial.println("-----------------Title-----------------\n");
  Serial.print("Título escrito: hola mundo    Título recibido: ");
  char text[SIZE_LINE_TITLE];
  set_line(LINE_TITLE, "hola mundo");
  Serial.println(get_line(LINE_TITLE, text));
 

  // Line 1
  Serial.println("-----------------Line 1-----------------\n");

  // Line title
  char s_temp[SIZE_LINES];

  Serial.print("Line number recibido: ");
  Serial.println(get_line(LINE1_NUM, s_temp));

  // Catalog number
  Serial.print("Catalog number escrito: 25544    Recibido: ");
  set_line(LINE1_CATALOG_NUM, "25544");
  Serial.println(get_line(LINE1_CATALOG_NUM, s_temp));

  // Classification
  Serial.print("Classification escrito: U    Recibido: ");
  set_line(LINE1_CLASSIFICATION, "U");
  Serial.println(get_line(LINE1_CLASSIFICATION, s_temp));

  // Launch year
  Serial.print("Launch year escrito: 98    Recibido: ");
  set_line(LINE1_INTERN_DES_LAUNCH_YEAR, "98");
  Serial.println(get_line(LINE1_INTERN_DES_LAUNCH_YEAR, s_temp));

  // Num year
  Serial.print("Num year escrito: 067    Recibido: ");
  set_line(LINE1_INTERN_DES_LAUNCH_NUM_YEAR, "067");
  Serial.println(get_line(LINE1_INTERN_DES_LAUNCH_NUM_YEAR, s_temp));

  // International designator
  Serial.print("International designator escrito: A  .  Recibido: ");
  set_line(LINE1_INTERN_DESIGN, "A  ");
  Serial.println(get_line(LINE1_INTERN_DESIGN, s_temp));

  // Epoch year
  Serial.print("Epoch year escrito: 08    Recibido: ");
  set_line(LINE1_EPOCH_YEAR, "08");
  Serial.println(get_line(LINE1_EPOCH_YEAR, s_temp));

  // Epoch day
  Serial.print("Epoch day escrito: 264.51782528    Recibido: ");
  set_line(LINE1_EPOCH_DAY, "264.51782528");
  Serial.println(get_line(LINE1_EPOCH_DAY, s_temp));

  // 1 derivative mean motion
  Serial.print("First derivative mean motion: -.00002182    Recibido: ");
  set_line(LINE1_FIRST_DERIV_MEAN_MOTION, "-.00002182");
  Serial.println(get_line(LINE1_FIRST_DERIV_MEAN_MOTION, s_temp));

  // 2 derivative mean motion
  Serial.print("Second derivative mean motion: 00000-0    Recibido: ");
  set_line(LINE1_SECOND_DERIV_MEAN_MOTION, "00000-0");
  Serial.println(get_line(LINE1_SECOND_DERIV_MEAN_MOTION, s_temp));

  // drag term
  Serial.print("Drag term: -11606-4    Recibido: ");
  set_line(LINE1_DRAG_TERM_COEF, "-11606-4");
  Serial.println(get_line(LINE1_DRAG_TERM_COEF, s_temp));

  // ephem type
  Serial.print("Ephemeris type: 6    Recibido: ");
  char s10[1];
  set_line(LINE1_EPHEMERIS, "6");
  Serial.println(get_line(LINE1_EPHEMERIS, s_temp));

  // Element set number
  Serial.print("Element set number: 292    Recibido: ");
  set_line(LINE1_ELEM_SET_NUM, "292");
  Serial.println(get_line(LINE1_ELEM_SET_NUM, s_temp));

  // checksum
  Serial.print("Checksum: 7    Recibido: ");
  set_line(LINE1_CHECKSUM, "7");
  Serial.println(get_line(LINE1_CHECKSUM, s_temp));

  // Line1 completa
  Serial.print("Line 1 completa: ");
  //Serial.println(get_line(LINE1, s_temp)); //todavía no va perfectamente

  for(int i = 0 ; i < SIZE_LINES; i++)
  {
    Serial.print(line1[i]);
  }

}

void loop()
{
}
