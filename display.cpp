#include <Arduino.h>

int displayValue = -1;

void setupDisplay() {
  DDRD = 0xFF;        // PORTD uitgang
}

int readDisplay() {
  return displayValue;
}

void writeDisplay(int val) {
  if(displayValue != val) {
    switch(val) {   // gfabDcde
      case 0:
        PORTD = 0b01110111;
        break;
      case 1:
        PORTD = 0b00010100;
        break;
      case 2:
        PORTD = 0b10110011;
        break;
      case 3:
        PORTD = 0b10110110;
        break;
      case 4:
        PORTD = 0b11010100;
        break;
      case 5:
        PORTD = 0b11100110;
        break;
      case 6:
        PORTD = 0b11100111;
        break;
      case 7:
        PORTD = 0b00110100;
        break;
      case 8:
        PORTD = 0b11110111;
        break;
      case 9:
        PORTD = 0b11110110;
        break;
      default:
        PORTD = 0b00000000;
        break;
    }
  }
  else
    displayValue = val;

}
