// Juraj Bazelides | 25076876

// adds Arduino functions
#include <Arduino.h>

// defines on which pins the LED and button are connected
#define LED_PIN 23
#define BUTTON_PIN 22

// how long to wait for the button to stop bouncing (ms)
#define DEBOUNCE_MS 50

// blink speeds in ms between LED on/off flips, 0 = LED off
// each button press moves to the next speed: slow -> medium -> fast -> off -> slow ...
const unsigned long BLINK_SPEEDS[] = {1000, 500, 150, 0};
const int NUM_SPEEDS = sizeof(BLINK_SPEEDS) / sizeof(BLINK_SPEEDS[0]);

// which speed is active, starts at slow
int speedIndex = 0;

// current LED state, starts on
bool ledState = true;

// time (ms since start) of the last LED flip
unsigned long lastToggle = 0;

// runs once at start
void setup()
{
  // defines that LED is an output and button is an input (HIGH when released, LOW when pressed), sets the LED to the current state
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED_PIN, ledState);
}

// runs loop forever
void loop()
{
  // check if button is pressed
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    // wait out button bounce
    delay(DEBOUNCE_MS);
    // still pressed, so it's an actual press
    if (digitalRead(BUTTON_PIN) == LOW)
    {
      // move to the next blink speed, wrapping back to the first
      speedIndex = (speedIndex + 1) % NUM_SPEEDS;
      // restart the blink with the LED on (or keep it off in the "off" setting)
      ledState = BLINK_SPEEDS[speedIndex] != 0;
      digitalWrite(LED_PIN, ledState);
      lastToggle = millis();
      // wait until the button is released
      while (digitalRead(BUTTON_PIN) == LOW)
      {
        delay(10);
      }
      // wait out bounce on release
      delay(DEBOUNCE_MS);
    }
  }

  // blink: flip the LED once enough time has passed for the current speed
  unsigned long interval = BLINK_SPEEDS[speedIndex];
  if (interval != 0 && millis() - lastToggle >= interval)
  {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    lastToggle = millis();
  }
}
