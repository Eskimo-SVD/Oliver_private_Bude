// Datei PWMPi4J.java

import com.pi4j.io.gpio.*;

class PWMPi4J {
  // Zugriff auf die GPIOs
  public static final GpioController gpio = GpioFactory.getInstance();
  
  public static void main(String[] args) {
    GpioPinPwmOutput pwm = null;
    try {
      pwm = gpio.provisionPwmOutputPin(RaspiPin.GPIO_01);
      for(int i=0; i<=1000; i++) {
        pwm.setPwm(i);
        Thread.sleep(10);  
      }
    } catch(InterruptedException ex) {
      Thread.currentThread().interrupt();
    }
    pwm.setPwm(0);
    gpio.shutdown();      
  }
}
