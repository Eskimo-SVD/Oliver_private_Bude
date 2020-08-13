#include <wiringPi.h>

// Die Leuchtdiode ist mit Pin 26 des P1-Headers verbunden.
// Die Wiring-Nummer dieses Pins lautet 11.
#define LEDPIN 11

int main(void) {
  if(wiringPiSetup() == -1)
    return 1;

  // GPIO-Pin als Signalausgang verwenden
  pinMode(LEDPIN, OUTPUT);

  // LED zehnmal ein- und ausschalten
  int i;
  for (i=0; i<10; i++) {
    digitalWrite(LEDPIN, 1);
    delay(500);               // 1/2 Sekunden
    digitalWrite(LEDPIN, 0);    
    delay(500);
  }
  return 0;
}
