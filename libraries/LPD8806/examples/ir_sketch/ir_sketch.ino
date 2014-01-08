

#include <LPD8806.h>
#include <SPI.h>

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Number of RGB LEDs in strand:
int nLEDs = 32;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 2;
int clockPin = 3;

// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

#define IR 5

int pirState = LOW;
int val = 0;

void setup() {
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
pinMode(IR, INPUT);
Serial.begin(9600);
}

void loop () {
	val = digitalRead(IR);
	if (val == HIGH) {
		if (pirState == LOW) {
			Serial.println("Motion Dected!");
			  // Send a simple pixel chase in...
  colorChase(strip.Color(127, 127, 127), 50); // White
  colorChase(strip.Color(127,   0,   0), 50); // Red
  colorChase(strip.Color(127, 127,   0), 50); // Yellow
  colorChase(strip.Color(  0, 127,   0), 50); // Green
  colorChase(strip.Color(  0, 127, 127), 50); // Cyan
  colorChase(strip.Color(  0,   0, 127), 50); // Blue
  colorChase(strip.Color(127,   0, 127), 50); // Violet

  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127,   0,   0), 50); // Red
  theaterChase(strip.Color(127, 127,   0), 50); // Yellow
  theaterChase(strip.Color(  0, 127,   0), 50); // Green
  theaterChase(strip.Color(  0, 127, 127), 50); // Cyan
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
  theaterChase(strip.Color(127,   0, 127), 50); // Violet

  // Fill the entire strip with...
  colorWipe(strip.Color(127,   0,   0), 50);  // Red
  colorWipe(strip.Color(  0, 127,   0), 50);  // Green
  colorWipe(strip.Color(  0,   0, 127), 50);  // Blue

  rainbow(10);
  rainbowCycle(0);  // make it go through the cycle fairly fast
  theaterChaseRainbow(50);
			pirState = HIGH;
		}
	} else {

		if (pirState == HIGH) {
			Serial.println("Motion ended!");		
			pirState = LOW;
		}
	}
}