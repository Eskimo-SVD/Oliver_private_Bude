// Datei TriggerPi4J.java

import com.pi4j.io.gpio.*;
import com.pi4j.io.gpio.trigger.*;

class TriggerPi4J {
  // Zugriff auf die GPIOs
  public static final GpioController gpio = GpioFactory.getInstance();
  
  public static void main(String[] args) {
    try {
      // Taster auf Pin 21 (entspricht RaspiPin.GPIO_13)
      GpioPinDigitalInput btn = 
        gpio.provisionDigitalInputPin(RaspiPin.GPIO_13);
        
      // Leuchtdiode auf Pin 26 (entspricht RaspiPin.GPIO_11)
      GpioPinDigitalOutput led = 
        gpio.provisionDigitalOutputPin(RaspiPin.GPIO_11);
      led.setShutdownOptions(true, PinState.LOW);

      // LED einschalten wenn Taste gedrückt wird
      btn.addTrigger(new GpioSetStateTrigger(PinState.LOW, led, PinState.HIGH));
 
      // LED ausschalten, wenn Taste losgelassen wird 
      btn.addTrigger(new GpioSetStateTrigger(PinState.HIGH, led, PinState.LOW));

      // zehn Sekunden lang auf Tastendrücke reagieren
      System.out.println("Drücken Sie den Taster!");
      Thread.sleep(10000); 
    } catch(InterruptedException ex) {
      Thread.currentThread().interrupt();
    }
    gpio.shutdown();      
  }
}
