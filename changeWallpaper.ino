#include "DigiKeyboard.h"

// Arrow Keys not defined in DigiKeyboard.h for some reason
// Manually defining them
#define KEY_ARROW_LEFT 0x50
#define KEY_ARROW_RIGHT 0x4F
#define KEY_ARROW_DOWN 0x51
#define KEY_ARROW_UP 0x52

void setup() {
  // empty
}

void loop() {

  // Reset the randomiser seed to make sure it is actually random
  randomSeed(analogRead(0));
  // Choose random number between 1 and 6 for meme filenames
  int r = random(1, 7);

  // Initialise digispark
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(600);

  // Opens the run dialog and launches powershell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(600);

  // Downloads random image from hosted files on GitHub
  DigiKeyboard.print("iwr http://raw.githubusercontent.com/debbie-tommy/COMP6441_SomethingAwesome/main/memes/");
  DigiKeyboard.print(r);
  DigiKeyboard.print(".jpg -OutFile ");
  DigiKeyboard.print(r);
  DigiKeyboard.println(".jpg");
  DigiKeyboard.delay(600);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(600);

  // Launches MS Paint and opens the downloaded file
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.println("mspaint");
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_O, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("%userprofile%\\");
  DigiKeyboard.print(r);
  DigiKeyboard.println(".jpg");
  DigiKeyboard.delay(600);

  // Opens the "File" dropdown menu and sets image as wallpaper
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);

  for (;;) {/* Stops the loop */}
}