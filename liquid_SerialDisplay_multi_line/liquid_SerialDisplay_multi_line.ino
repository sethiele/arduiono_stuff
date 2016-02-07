/**
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * Original: https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library/tree/master/examples/SerialDisplay
 * ADD: display two lines
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
  
  // Initialize the serial port at a speed of 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // If characters arrived over the serial port...
  if (Serial.available()) {
    // Wait a bit for the entire message to arrive
    delay(100);
    // Clear the screen
    lcd.clear();

    // Write all characters received with the serial port to the LCD.
    // 15
    while (Serial.available() > 0) {
      String read = Serial.readString();
      if (read.length() <= 17){
        lcd.print(read);
      } else {
        lcd.setCursor(0,0);
        lcd.print(read);
        lcd.setCursor(0,1);
        printRest(read);
      }
    }
  }
}

void printRest(String text){
  int max_length = 0;
  if (text.length() >= 33){
    max_length = 33;
  } else {
    max_length = text.length();
  }
  
  for(int i = 16; i <= max_length - 1; i++){
    lcd.print(text[i]);
  }
}

