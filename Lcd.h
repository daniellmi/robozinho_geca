#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>

class Lcd : public LiquidCrystal_I2C { 

public:

Lcd(int hex, int col, int row): LiquidCrystal_I2C(hex,col,row) {}

void begin() {
  LiquidCrystal_I2C::init();
  backlight();
  clear();
}

void display(String text) {
   setCursor(0,0);
    print(text);
}

void displayColor(String color_1, String color_2) {
      setCursor(0,0);
      print("RIGHT C:");
      print(color_1);

      setCursor(0,1);
      print("LEFT C:");
      print(color_2);
}



};


#endif