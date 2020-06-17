/*
  Ejemplo de cómo acceder a los distintos strings del TLE.
  No necesita el emisor ARM, simplemente escribe y lee
  La librería está dentro de src/ porque sino la IDE
  de arduino no lo encuentra.
*/

#include "src/TLE/TLE.h"

void setup()
{
  char title[SIZE_LINES];
  char line1[SIZE_LINES];
  char line2[SIZE_LINES];

  init_line(LINE_TITLE, title); // las limpiamos
  init_line(LINE1, line1);
  init_line(LINE2, line2);

  Serial.begin(9600);

  Serial.println("------------------------------------");
  Serial.println("Ejemplo implementación protocolo TLE");
  Serial.println("------------------------------------\n\n");

  // Title
  Serial.println("-----------------Title-----------------\n");
  Serial.print("Título escrito: hola mundo    Título recibido: ");
  set_line(LINE_TITLE, "hola mundo", title);
  Serial.println(get_line(LINE_TITLE, title));

  // Line 1
  Serial.println("-----------------Line 1-----------------\n");

  // Line title
  Serial.print("Line number recibido: ");
  Serial.println(get_line(LINE1_NUM, line1));

  // Catalog number
  Serial.print("Catalog number escrito: 25544.    Recibido: ");
  set_line(LINE1_CATALOG_NUM, "25544", line1);
  Serial.println(get_line(LINE1_CATALOG_NUM, line1));

  // Classification
  Serial.print("Classification escrito: U.    Recibido: ");
  set_line(LINE1_CLASSIFICATION, "U", line1);
  Serial.println(get_line(LINE1_CLASSIFICATION, line1));

  // Launch year
  Serial.print("Launch year escrito: 98.    Recibido: ");
  set_line(LINE1_INTERN_DES_LAUNCH_YEAR, "98", line1);
  Serial.println(get_line(LINE1_INTERN_DES_LAUNCH_YEAR, line1));

  // Num year
  Serial.print("Num year escrito: 067.    Recibido: ");
  set_line(LINE1_INTERN_DES_LAUNCH_NUM_YEAR, "067", line1);
  Serial.println(get_line(LINE1_INTERN_DES_LAUNCH_NUM_YEAR, line1));

  // International designator
  Serial.print("International designator escrito: A.  Recibido: ");
  set_line(LINE1_INTERN_DESIGN, "A", line1);
  Serial.println(get_line(LINE1_INTERN_DESIGN, line1));

  // Epoch year
  Serial.print("Epoch year escrito: 08.    Recibido: ");
  set_line(LINE1_EPOCH_YEAR, "08", line1);
  Serial.println(get_line(LINE1_EPOCH_YEAR, line1));

  // Epoch day
  Serial.print("Epoch day escrito: 264.51782528.    Recibido: ");
  set_line(LINE1_EPOCH_DAY, "264.51782528", line1);
  Serial.println(get_line(LINE1_EPOCH_DAY, line1));

  // 1 derivative mean motion
  Serial.print("First derivative mean motion: -.00002182.    Recibido: ");
  set_line(LINE1_FIRST_DERIV_MEAN_MOTION, "-.00002182", line1);
  Serial.println(get_line(LINE1_FIRST_DERIV_MEAN_MOTION, line1));

  // 2 derivative mean motion
  Serial.print("Second derivative mean motion: 00000-0.    Recibido: ");
  set_line(LINE1_SECOND_DERIV_MEAN_MOTION, "00000-0", line1);
  Serial.println(get_line(LINE1_SECOND_DERIV_MEAN_MOTION, line1));

  // drag term
  Serial.print("Drag term: -11606-4.    Recibido: ");
  set_line(LINE1_DRAG_TERM_COEF, "-11606-4", line1);
  Serial.println(get_line(LINE1_DRAG_TERM_COEF, line1));

  // ephem type
  Serial.print("Ephemeris type: 6.    Recibido: ");
  char s10[1];
  set_line(LINE1_EPHEMERIS, "6", line1);
  Serial.println(get_line(LINE1_EPHEMERIS, line1));

  // Element set number
  Serial.print("Element set number: 292.    Recibido: ");
  set_line(LINE1_ELEM_SET_NUM, "292", line1);
  Serial.println(get_line(LINE1_ELEM_SET_NUM, line1));

  // checksum
  Serial.print("Checksum: 7.    Recibido: ");
  set_line(LINE1_CHECKSUM, "7", line1);
  Serial.println(get_line(LINE1_CHECKSUM, line1));

  // Line1 completa
  Serial.print("Line 1 completa: ");
  Serial.println(line1);

  // Line 2
  Serial.println("-----------------Line 2-----------------\n");

  // Line number
  Serial.print("Line number recibido: ");
  Serial.println(get_line(LINE2_NUM, line2));

  // Satellite Catalog number
  Serial.print("Catalog number escrito: 25544.    Recibido: ");
  set_line(LINE2_CATALOG_NUM, "25544", line2);
  Serial.println(get_line(LINE2_CATALOG_NUM, line2));

  // Inclination (degrees)
  Serial.print("Inclination degrees escrito: 51.6416.    Recibido: ");
  set_line(LINE2_INCLINATION, "51.6416", line2);
  Serial.println(get_line(LINE2_INCLINATION, line2));

  // Right Ascension of the Ascending Node (degrees)
  Serial.print("Right Ascension Ascen. Node escrito: 247.4627.    Recibido: ");
  set_line(LINE2_RIGHT_ASCEN, "247.4627", line2);
  Serial.println(get_line(LINE2_RIGHT_ASCEN, line2));

  // Eccentricity (decimal point assumed)
  Serial.print("Eccentricity escrito: 0006703.    Recibido: ");
  set_line(LINE2_ECCENTRICITY, "0006703", line2);
  Serial.println(get_line(LINE2_ECCENTRICITY, line2));

  // Argument of Perigee (degrees)
  Serial.print("Eccentricity escrito: 130.5360.    Recibido: ");
  set_line(LINE2_PERIGEE, "130.5360", line2);
  Serial.println(get_line(LINE2_PERIGEE, line2));

  // Mean Anomaly (degrees)
  Serial.print("Mean Anomaly escrito: 325.0288.    Recibido: ");
  set_line(LINE2_MEAN_ANOMALY, "325.0288", line2);
  Serial.println(get_line(LINE2_MEAN_ANOMALY, line2));

  // Mean Motion (revolutions per day)
  Serial.print("Mean Motion escrito: 15.72125391.    Recibido: ");
  set_line(LINE2_MEAN_MOTION, "15.72125391", line2);
  Serial.println(get_line(LINE2_MEAN_MOTION, line2));

  // Revolution number at epoch (revolutions)
  Serial.print("Mean Motion escrito: 56353.    Recibido: ");
  set_line(LINE2_REVOLUTIONS, "56353", line2);
  Serial.println(get_line(LINE2_REVOLUTIONS, line2));

  // Checksum (modulo 10)
  Serial.print("Mean Motion escrito: 7.    Recibido: ");
  set_line(LINE2_CHECKSUM, "7", line2);
  Serial.println(get_line(LINE2_CHECKSUM, line2));

  // Line2 completa
  Serial.print("Line 2 completa: ");
  Serial.println(line2);
}

void loop()
{
}
