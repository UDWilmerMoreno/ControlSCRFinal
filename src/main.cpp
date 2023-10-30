#include <Arduino.h>

#define PinDeInterrupcion 13
#define DisparoDelSCR 4

int Retardo = 1150;
int TiempoDisparoDelSCR = 100;

void ICACHE_RAM_ATTR InterrupcionExternaCrucePorCero();

void InterrupcionExternaCrucePorCero()
{
  delayMicroseconds(Retardo);
  digitalWrite(DisparoDelSCR, HIGH);
  delayMicroseconds(TiempoDisparoDelSCR);
  digitalWrite(DisparoDelSCR, LOW);
  if (Retardo >= 8150)
  {
    Retardo = 0;
    digitalWrite(DisparoDelSCR, LOW);
    delay(1000);
  }
}

void setup()
{
  pinMode(PinDeInterrupcion, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PinDeInterrupcion), InterrupcionExternaCrucePorCero, RISING);
  pinMode(DisparoDelSCR, OUTPUT);
}

void loop()
{
  Retardo++;
  delay(8);
}