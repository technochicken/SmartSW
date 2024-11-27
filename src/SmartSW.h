/*
  SmartSW.h - Library for managing Smart CHERRY MX LOW Profile RGB switches.

  Created by Christian Schaffner, 27.11.2024.

  This library is designed to control Smart CHERRY MX LOW Profile RGB switches with 
  integrated LEDs and buttons. It allows users to manage the physical state 
  (pressed/released) of buttons and the light state (off, on, blinking) of corresponding LEDs. 

  Features:
  - Easy setup and management of multiple buttons and LEDs.
  - Separate handling of physical button states and LED light states.
  - Customizable LED colors and blinking behavior.
  - Scalable design for use with multiple switches.

  Released into the public domain.
*/


#ifndef SMARTSW_H
#define SMARTSW_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class SmartSW {
public:
    // Constructor
    SmartSW(uint8_t ledPin, const uint8_t* buttonPins, uint8_t buttonCount);

    // Initializes the LED and buttons
    void begin();

    // Sets colors for a specific button
    void setButtonColors(uint8_t buttonIndex, uint8_t redA, uint8_t greenA, uint8_t blueA, uint8_t redB, uint8_t greenB, uint8_t blueB);

    // Sets the light state (OFF, ON, BLINKING) for a specific button
    void setLightState(uint8_t buttonIndex, uint8_t lightState);

    // Gets the light state of a button
    uint8_t getLightState(uint8_t buttonIndex);

    // Gets the physical state of a button (pressed/released)
    uint8_t getPhysicalState(uint8_t buttonIndex);

    // Updates the LEDs based on their light state
    void updateLEDs();

    // Reads and updates the physical states of the buttons
    void loop();

    void setBlinkSpeed(uint8_t speed);


private:
    uint8_t _ledPin;
    uint8_t* _buttonPins;
    uint8_t _buttonCount;
    uint32_t _blinkDelay;

    struct Button {
        uint8_t pin;
        uint8_t lightState; // 0 = OFF, 1 = ON, 2 = BLINKING
        uint8_t physicalState; // 0 = Released, 1 = Pressed
        uint32_t colorA;
        uint32_t colorB;
    };

    Button* _buttons;
    Adafruit_NeoPixel _leds;
};

#endif
