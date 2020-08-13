// Datei InputPi4J.java

import com.pi4j.io.gpio.*;

class InputPi4J {
  // Zugriff auf die GPIOs
  public static final GpioController gpio = GpioFactory.getInstance();
  
  public static void main(String[] args) {
    try {
      GpioPinDigitalInput btn = 
        gpio.provisionDigitalInputPin(RaspiPin.GPIO_13);
      for(int i=0; i<20; i++) {
        System.out.println(btn.getState());
        Thread.sleep(300);
      }
    } catch(InterruptedException ex) {
      Thread.currentThread().interrupt();
    }
    gpio.shutdown();      
  }
}
