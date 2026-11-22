//Lab 1a - Changes made for my own branch
//This branch is used to practice Git and Github collaboration
#include <Arduino.h>

// Student name: kieran doherty
// Student number: 26058421

int ledPin = 23;
int buttonPin = 22;

int ledState = HIGH;
int buttonState = LOW;
int lastButtonReading = LOW;

unsigned long lastTime = 0;
int debounceDelay = 50;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLDOWN);

    digitalWrite(ledPin, ledState);
}

void loop()
{
    int reading = digitalRead(buttonPin);

    if (reading != lastButtonReading)
    {
        lastTime = millis();
    }

    if ((millis() - lastTime) > debounceDelay)
    {
        if (reading != buttonState)
        {
            buttonState = reading;

            if (buttonState == HIGH)
            {
                ledState = !ledState;
                digitalWrite(ledPin, ledState);
            }
        }
    }

    lastButtonReading = reading;
}
