/**
 *  Love-O-Meter 
 *
 *  Auther: Ralph Lepore 05-11-2013
 */
 const int sensorPin = A0;
 const float baselineTemp = 20.0;
 
 void setup() {
    //open a serial connection between the arduino and my computer so we can see the values from the analog input.
    //We are going to set it to 9600 bits per second, this is the speed in which the Arduino will communicate with us.
    Serial.begin(9600);
  
    //Set up our pins as outputs
    for(int pin = 2; pin < 5; pin++) {
       pinMode(pin, OUTPUT);
       digitalWrite(pin, LOW);
    } 
 }
 
 void loop() {
   int sensorVal = analogRead(sensorPin); //Read from the analog pin provided.
   
   //Send information to the connected computer.  
   Serial.print("Sensor Value: "); 
   Serial.print(sensorVal);
   
   //Convert the ADC reading to voltage.
   float voltage = (sensorVal/1024.0) * 5.0;
   
   Serial.print(", Volts: ");
   Serial.print(voltage);
   
   //Convert the voltage into temperature degrees.
   float temperature = (voltage - .5) * 100;
   Serial.print(", Degrees C: ");
   Serial.println(temperature);
 
   if(temperature < baselineTemp) {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
   } else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
   } else if(temperature >= baselineTemp + 6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
    }
    delay(500);  //set a delay because the analog-to-digital converter can only read so fast, without a delay the outputs may seem erratic.
 }
