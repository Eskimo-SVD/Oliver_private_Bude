// Datei HelloPi4J.java

import com.pi4j.io.gpio.*;

class HelloPi4J {
  // Zugriff auf die GPIOs
  public static final GpioController gpio = GpioFactory.getInstance();
  
  public static void main(String[] args) {

    try {
      GpioPinDigitalOutput led = 
        gpio.provisionDigitalOutputPin(RaspiPin.GPIO_11);
      led.setShutdownOptions(true, PinState.LOW);
      led.setState(PinState.HIGH);  // LED einschalten
      Thread.sleep(2000);           // 2 Sekunden warten
      led.setState(PinState.LOW);   // LED wieder ausschalten
    } catch(InterruptedException ex) {
      Thread.currentThread().interrupt();
    }
    gpio.shutdown();      
  }
  
}
