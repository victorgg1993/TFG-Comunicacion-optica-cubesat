/*
  Arduino Uno, al ir a 16MHz, los micros no los lleva muy bien,
  así que la resolución de arduino es de múltiplos de 4

  ( vamos, que salta de 4 en 4 ), hay que tenerlo en cuenta para ajustar
  el TIM4 del STM32
*/

// ARM, PB12 (PWM)      => Arduino, 3 (PWM)
#define NUM_CALIBRACION 2568

#define PIN_PWM 3
#define BIT_STOP 4
#define SIZE_BUFFER 4 // relacionado con el nº de paquetes que envía el ARM

volatile unsigned long tiempo = 0;
volatile char paquetes[(SIZE_BUFFER)];

volatile byte puntero = 0;
volatile bool EOT = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Init!");
  pinMode(PIN_PWM, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_PWM), ISR_pin_PWM, CHANGE); // cambio estado pin = ISR PWM
}
void loop()
{
  if (EOT == true)
  {
    imprimir_datos_recibidos();
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
    unsigned long palabra = ((micros() - tiempo) / NUM_CALIBRACION );

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

  for (int i = 0; i < SIZE_BUFFER; i++)
  {
    Serial.print(paquetes[i]);
  }
  Serial.println("");
}