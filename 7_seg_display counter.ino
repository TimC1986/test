#include "display.h"

int old_switch1_state=1, new_switch1_state=1;
int old_switch2_state=1, new_switch2_state=1;
int count = 0;

void setup() {
  setupDisplay();
  DDRB &= 0b11111100;   // PB0 en PB1 zijn ingang
  PORTB |= 0b00000011;  // Activeer pull-up weerstanden
}

void loop() {
  old_switch1_state = new_switch1_state;
  old_switch2_state = new_switch2_state;

  new_switch1_state = bool(PINB & 0b00000001);
  new_switch2_state = bool(PINB & 0b00000010);

  if(old_switch1_state==1 && new_switch1_state==0) {
    delay(200);
    count++;
  }
  if(old_switch2_state==1 && new_switch2_state==0) {
    delay(200);
    count--;
  }
  if(count < 0)
    count = 0;
  if(count > 9)
    count = 9;
  
  writeDisplay(count);
}
