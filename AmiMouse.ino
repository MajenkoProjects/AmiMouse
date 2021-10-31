#include <PS2Mouse.h>
#define MOUSE_DATA 5
#define MOUSE_CLOCK 6

int8_t ph = 0;
int8_t pv = 0;
int8_t pb = 0;

const uint8_t pins_h[] = { 7, 8 };
const uint8_t pins_v[] = { 9, 10 };
const uint8_t pins_b[] = { 11, 12, 13 };

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);

/**
 * Setup
 */
void setup()
{
  for (int i = 0; i < 2; i++) {
    pinMode(pins_h[i], OUTPUT);
    pinMode(pins_v[i], OUTPUT);
    pinMode(pins_b[i], OUTPUT);
    digitalWrite(pins_b[i], HIGH);
  }
  mouse.initialize();
}

/**
 * Main program loop
 */
void loop()
{
  int16_t data[3];
  mouse.report(data);

  if (data[1] != 0) {
    pulse(pins_h, &ph, data[1]);
  }
  if (data[2] != 0) {
    pulse(pins_v, &pv, data[2]);
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(pins_b[i], data[0] & (1 << i) ? LOW : HIGH);
  }
}

void pulse(const uint8_t *pins, int8_t *p, int amt) {
  if (amt == 0) return;
  int8_t dir = 0;
  if (amt < 0) {
    dir = -1;
    amt = 0 - amt;
  } else {
    dir = 1;
  }

  for (int i = 0; i < amt; i++) {
    *p += dir;
    if (*p == 4) *p = 0;
    if (*p == -1) *p = 3;

    switch (*p) {    
      case 0:
        digitalWrite(pins[0], LOW);
        digitalWrite(pins[1], LOW);
        break;
      case 1:
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], LOW);
        break;
      case 2:
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        break;
      case 3:
        digitalWrite(pins[0], LOW);
        digitalWrite(pins[1], HIGH);
        break;
    }
  }
}
