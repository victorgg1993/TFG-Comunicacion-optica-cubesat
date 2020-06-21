/*
  Notas importantes:

  Arduino Uno, al ir a 16MHz, los micros no los lleva muy bien,
  así que la resolución de arduino es de múltiplos de 4
  ( vamos, que salta de 4 en 4 ), hay que tenerlo en cuenta para ajustar
  el TIM4 del STM32

  *****************> ARM, PB12 (PPM)      => Arduino, 3 (PPM) <*****************
*/

#include <LiquidCrystal.h>
#include "src/defines.h" // aquí hay algunos defines usados en el código (bit stop y cosas así)
#include "src/drivers.h" // aquí tenemos los pines y sus definiciones
#include "src/TLE/TLE.h"

// Variables
volatile char paquetes[SIZE_LINES];
volatile byte puntero = 0;

volatile unsigned long tiempo = 0;
volatile byte bit_start = BIT_START;
volatile bool EOT = false;

// Objetos
LiquidCrystal lcd(PIN_RS, PIN_E, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

void setup()
{
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  Serial.println("Init!");

  lcd.begin(16, 2);
  lcd.print("Esperando datos");

  pinMode(PIN_PPM, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_PPM), ISR_pin_PPM, CHANGE); // cambio estado pin = ISR PPM
}

void loop()
{
  if (EOT == true)
  {
    imprimir_datos_recibidos(); // por la uart

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nuevos datos!");
    delay(1500);
    lcd.clear();

    lcd.setCursor(0, 0); // línea 1
    lcd.print("Sat. c. n: ");
    lcd.print(get_line(LINE1_CATALOG_NUM, paquetes));

    lcd.setCursor(0, 1); // línea 2
    lcd.print("Launch year: ");
    lcd.print(get_line(LINE1_INTERN_DES_LAUNCH_YEAR, paquetes));

    while(1); // temporal
    delay(1000); // volvemos a empezar
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Esperando datos");

    reset_variables_ppm();
    EOT = false;
  }
}

void ISR_pin_PPM()
{
  switch (bit_start)
  {
  case BIT_START: // Sólo se usa para iniciar la trama
    bit_start++;
    break;

  case BIT_DATA: // Data
  default:

    switch (digitalRead(PIN_PPM))
    {
    case LOW:
      tiempo = micros();
      break;

    case HIGH:
      char palabra = ((micros() - tiempo) / 133);

      if (palabra <= BIT_STOP) // if señal de stop => end of transmission
      {
        EOT = true;
      }
      else // byte normal
      {
        paquetes[puntero] = palabra;
        puntero++;
      }
      break;
    }
    break;
  }
}

void reset_variables_ppm()
{
  puntero = 0;
  bit_start = BIT_START; // reset start para la próxima irq
  tiempo = 0;
}

void imprimir_datos_recibidos()
{
  Serial.print("Data: ");

  for (int i = 0; i < sizeof(paquetes); i++)
  {
    Serial.print((char)paquetes[i]);
  }
  Serial.println("");
}