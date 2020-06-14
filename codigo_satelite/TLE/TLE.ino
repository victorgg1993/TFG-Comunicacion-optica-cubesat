/*
  Ejemplo de cómo acceder a los distintos strings del TLE.
  No necesita el emisor ARM, simplemente escribe y lee.
*/

#include "src/TLE/TLE.h"

void setup()
{
  Serial.begin(9600);
  Serial.println("------------------------------------");
  Serial.println("Ejemplo implementación protocolo TLE");
  Serial.println("------------------------------------\n\n");

  // Title
  Serial.println("-----------------Title-----------------\n");
  Serial.println("Título escrito: hola mundo");
  set_title("hola mundo");

  Serial.print("Título recibido: ");
  char *text = get_title();
  Serial.println(text);
  Serial.println("\n");

  // Line 1
  Serial.println("-----------------Line 1-----------------\n");

  // Line title
  Serial.print("Line number recibido: ");
  char line_num_L1 = get_line1_params(LINE_NUMBER);
  Serial.println(line_num_L1);

  // Catalog number
  Serial.print("Catalog number escrito: 25544. Recibido: ");
  set_line1_params(CATALOG_NUM, "25544");
  char *cat_num_L1 = get_line1_params(CATALOG_NUM);
  Serial.println(cat_num_L1);

  // Classification
  Serial.print("Classification escrito: U. Recibido: ");
  set_line1_params(CLASSIFICATION, 'U');
  char classif_num_L1 = get_line1_params(CLASSIFICATION);
  Serial.println(classif_num_L1);

  // Launch year
  Serial.print("Launch year escrito: 98. Recibido: ");
  set_line1_params(INTER_DESIGN_LAUNCH_YEAR, "98");
  char *launch_y_L1 = get_line1_params(INTER_DESIGN_LAUNCH_YEAR);
  Serial.println(launch_y_L1);

  // Num year
  Serial.print("Num year escrito: 067. Recibido: ");
  set_line1_params(INTER_DESIGN_NUM_YEAR, "067");
  char *launch_num_y_L1 = get_line1_params(INTER_DESIGN_NUM_YEAR);
  Serial.println(launch_num_y_L1);
}

void loop()
{
}
