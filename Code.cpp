#include<LiquidCrystal.h>                        // this library allows an arduino board to control lcds. the library works with in either 4 or 8 bit mode.  functions - setcursor, display

int a, b, c;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){              //Initial State of The Arduino.

pinMode(8, OUTPUT);        // Pin Functionality.

pinMode(9, OUTPUT);

pinMode(10, OUTPUT);

lcd,clear();

lcd.begin(16, 2);

lcd.setCursor(1, 0);                  // (column, row).      1, 0 means top right,    0, 1 means bottom left

lcd.print("STREET LIGHT");

lcd.setCursor(1, 1);

lcd.print("PROJECT");

delay(1000);                          // waits for a second.

lcd.clear();

Serial.begin(9600);                   //open serial port and set data rate

}

void loop(){                // it runs in a loop over and over again.    Loop describes the main logic.
 
a = analogRead(A0);               //it reads the value from the specified analog pin.

b = map(a, 0, 1023, 0, 255);          //remaps a number from one  range to another         i.e. from low, fromhigh, tolow, tohigh.

Serial.printIn(b);                      // //next line

if(b < 220){                             //220 is a common value to use as a currrent limiting ressistor for an LED.

lcd.setCursor(1, 0);

Serial.printIn("low light");                //next line

digitalWrite(8, HIGH);             //write a high or low value to digital pin.         in this case the high vollt is 5 and low volt is 0 because of pinmode functionality.

digitalWrite(9, HIGH);

digitalWrite(10, HIGH);

}

if(b > 220){

lcd.setCursor(1, 0);              // (column, row).      1, 0 means top right,    0, 1 means bottom left            // it is basically a cursor which you can modify according to your requirements.

lcd.printIn("NORMAL LIGHT");

digitalWrite(8, LOW);

digitalWrite(9, LOW);

digitalWrite(10, LOW);

}

}
