#ifndef display_h
#define display_h

#include <Arduino.h>

extern int displayValue;

void setupDisplay(void);
int readDisplay();
void writeDisplay(int);

#endif
