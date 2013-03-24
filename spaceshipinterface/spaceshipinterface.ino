/**
 *  This is the Spaceship Interface that will blink the two Red LEDs (on pin 4 and 5) if you click the button on the breadboard.
 *
 *  Author: Ralph Lepore
 */
 //Globals
 int switchState = 0;
 
 /** 
  *  Setting up our pins. Pin number 2 will be our input pin (this should be connected to the switch).
  *  Pin numbers 3, 4 and 5 are our output pins and should be connected to the LEDs.
  */ 
 void setup() {
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(2, INPUT);
 
 
   //Lets make the LEDs flash when we first turn it on, to simulate the system configuring itself.
   for(int i=0; i < 6; i++) {
     flash(3);
     flash(4);
     flash(5);
   }
 }
 
 /**
  *  Flash the LED on the pin number provided by first writing a high bit, sleeping for a quarter of a second
  *  and the writing a low bit to the pin.
  */
 void flash(int pinNumber) {
   digitalWrite(pinNumber, HIGH);
   delay(250);
   digitalWrite(pinNumber, LOW);
 }
 
 /**
  *  Read the voltage in from pin 2, if we get a high bit (electricity) then we are going to "Blink" the two 
  *  red LEDs (the LEDs on pins 4 and 5).  If we have a Low bit (meaning no electricity, button is not being pressed)
  *  we are going to write a high bit to pin 3 (this should be the Green LED).
  */
 void loop() {
   switchState = digitalRead(2);  //Read the input voltage from pin number 2 
   
    if(switchState == LOW) { //The button is not pressed
       digitalWrite(3, HIGH);
       digitalWrite(4, LOW);
       digitalWrite(5, LOW);
    } else { //The button has been pressed
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
       digitalWrite(5, HIGH);
       
       //Below we are going to blink the two red LED lights
       delay(250);  //wait for a quarter second
       
       //Toggle the LEDs
       digitalWrite(4, HIGH);
       digitalWrite(5, LOW);
       delay(250); //wait for a quarter second again.
    }
 }
