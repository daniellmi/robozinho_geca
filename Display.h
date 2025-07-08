#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_SSD1306.h>

class Display {

  Adafruit_SSD1306 display;
  char message[7];
  int x;
  int y;
  int i;

  int length() {
    return sizeof(this->message) / sizeof(char);
  }
public:

  Display(const char* message) {
    x = 15;
    y = 2;
    i = 0;
    strncpy(this->message, message, sizeof(this->message));
  }

  void Display::startDisplay(int size) {
    display.begin();
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(size);
    display.setCursor(x, y);
    display.display();
  }

  void Display::showMessageOnDisplay() {

display.clearDisplay();
display.print(message);
display.setCursor(x, 5);
display.display();
    // display.print(message[i]);
    // i++;
    // display.display();
    // delay(300);

    // if (i == this->length()) {
    //   display.clearDisplay();
    //   i = 0;
    //   display.display();
    // }
  }

};
#endif
