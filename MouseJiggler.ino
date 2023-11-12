#include <DigiMouse.h>

void setup() {
  randomSeed(analogRead(0));
  DigiMouse.begin(); //start
}

void loop() {
  //Moves mouse anywhere between -10 to 10 pixels in X, Y, scroll
  DigiMouse.move(random(-11,11), random(-11,11), random(-11,11));
  // Waits anywhere between 10 secs and 40 secs to move mouse again 
  DigiMouse.delay(random(10000, 40000));
}