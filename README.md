ESP32 Lab 1a - GPIO Input and Output

Description
    This project uses a microcontroller to control a LED using a button

Hardware
    ESP32 microcontroller board
    LED
    Push Button
    BreadBoard
    Resistor
    Wires

Functionality
    The program uses a button as a digital input and a LED as a digital output
    The LED blinks, and each button press changes the speed:
    slow (1000 ms) -> medium (500 ms) -> fast (150 ms) -> off -> slow
    The button is wired from GPIO 22 to GND (uses the internal pull-up)

Software
    PlatformIO
    VS Code
    Arduino Framework
    C++

Purpose
    To practice GPIO input and output.