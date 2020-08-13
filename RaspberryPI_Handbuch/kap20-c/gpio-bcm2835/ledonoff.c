#include <bcm2835.h>

// die LED ist mit Pin 26 des P1-Headers verbunden
#define LEDPIN RPI_V2_GPIO_P1_26

int main(void) {
  // bcm2835_set_debug(1);
  if (!bcm2835_init())
    return 1;

  // den Pin als Signalausgang verwenden
  bcm2835_gpio_fsel(LEDPIN, BCM2835_GPIO_FSEL_OUTP);

  int i;
  for(i=0; i<10; i++) {
    bcm2835_gpio_write(LEDPIN, HIGH);
    delay(500);
    bcm2835_gpio_write(LEDPIN, LOW);
    delay(500);
  }
  return 0;
}
