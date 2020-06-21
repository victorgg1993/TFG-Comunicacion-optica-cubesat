/*
  Arduino Uno, al ir a 16MHz, los micros no los lleva muy bien,
  así que la resolución de arduino es de múltiplos de 4

  ( vamos, que salta de 4 en 4 ), hay que tenerlo en cuenta para ajustar
  el TIM4 del STM32
*/

#include <LiquidCrystal.h>
#include "src/defines.h" // aquí hay algunos defines usados en el código (bit stop y cosas así)
#include "src/drivers.h" // aquí tenemos los pines y sus definiciones
#include "src/TLE/TLE.h"

// ARM, PB12 (PWM)      => Arduino, 3 (PWM)
#define NUM_CALIBRACION 2568

// Variables
volatile char paquetes[SIZE_LINES];

volatile unsigned long tiempo = 0;
volatile byte puntero = 0;
volatile bool EOT = false;

// Objetos
LiquidCrystal lcd(PIN_RS, PIN_E, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

void setup()
{
  Serial.begin(9600);
  Serial.println("Init!");

  lcd.setCursor(0, 0);
  lcd.begin(16, 2);
  lcd.print("Esperando datos");
  lcd.setCursor(0, 1);
  lcd.print("Modo: PWM");

  pinMode(PIN_PWM, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_PWM), ISR_pin_PWM, CHANGE); // cambio estado pin = ISR PWM
}
void loop()
{
  if (EOT == true)
  {
    imprimir_datos_recibidos();

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

    while (1);   // temporal
    delay(1000); // volvemos a empezar

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Esperando datos");

    reset_variables_pwm();
    EOT = false;
  }
}

void ISR_pin_PWM()
{
  switch (digitalRead(PIN_PWM))
  {
  case HIGH:
    tiempo = micros();
    break;

  case LOW:
    unsigned long palabra = ((micros() - tiempo) / NUM_CALIBRACION);

    if (palabra == BIT_STOP) // if señal de stop => end of transmission
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
}

inline void reset_variables_pwm()
{
  puntero = 0;
  tiempo = 0;
}

void imprimir_datos_recibidos()
{
  Serial.print("Data: ");

  for (int i = 0; i < strlen(paquetes); i++)
  {
    Serial.print(paquetes[i]);
  }
  Serial.println("");
}