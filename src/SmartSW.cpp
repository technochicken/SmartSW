#include "SmartSW.h"

SmartSW::SmartSW(uint8_t ledPin, const uint8_t* buttonPins, uint8_t buttonCount)
    : _ledPin(ledPin), _buttonCount(buttonCount), _leds(buttonCount, ledPin, NEO_GRB + NEO_KHZ800) {
    _buttonPins = new uint8_t[_buttonCount];
    _buttons = new Button[_buttonCount];

    for (uint8_t i = 0; i < _buttonCount; ++i) {
        _buttonPins[i] = buttonPins[i];
        _buttons[i] = {buttonPins[i], 0, 0, 0, 0}; // Default OFF, no colors, Released
    }
}

void SmartSW::begin() {
    // Initialize NeoPixel LEDs
    _leds.begin();
    _leds.show(); // Ensure all LEDs are off initially
    _blinkDelay = 500;

    // Initialize button pins
    for (uint8_t i = 0; i < _buttonCount; ++i) {
        pinMode(_buttonPins[i], INPUT_PULLUP);
    }
}

void SmartSW::setButtonColors(uint8_t buttonIndex, uint8_t redA, uint8_t greenA, uint8_t blueA, uint8_t redB, uint8_t greenB, uint8_t blueB) {
    if (buttonIndex >= _buttonCount) return;

    // Set primary and secondary colors
    _buttons[buttonIndex].colorA = _leds.Color(redA, greenA, blueA);
    _buttons[buttonIndex].colorB = _leds.Color(redB, greenB, blueB);
}

void SmartSW::setLightState(uint8_t buttonIndex, uint8_t lightState) {
    if (buttonIndex >= _buttonCount) return;

    _buttons[buttonIndex].lightState = lightState;
}

uint8_t SmartSW::getLightState(uint8_t buttonIndex) {
    if (buttonIndex >= _buttonCount) return 0; // Invalid index
    return _buttons[buttonIndex].lightState;
}

uint8_t SmartSW::getPhysicalState(uint8_t buttonIndex) {
    if (buttonIndex >= _buttonCount) return 0; // Invalid index
    return _buttons[buttonIndex].physicalState;
}

void SmartSW::setBlinkSpeed(uint32_t speed){
  _blinkDelay = speed;
}

void SmartSW::updateLEDs() {
    for (uint8_t i = 0; i < _buttonCount; ++i) {
        switch (_buttons[i].lightState) {
            case 0: // OFF
                _leds.setPixelColor(i, 0); // Turn off LED
                break;
            case 1: // ON
                _leds.setPixelColor(i, _buttons[i].colorA);
                break;
            case 2: // BLINKING
                _leds.setPixelColor(i, (millis() / _blinkDelay % 2) ? _buttons[i].colorA : _buttons[i].colorB);
                break;
        }
    }
    _leds.show();
}

void SmartSW::loop() {
  updateLEDs();
    for (uint8_t i = 0; i < _buttonCount; ++i) {
        uint8_t currentState = digitalRead(_buttonPins[i]);
        _buttons[i].physicalState = (currentState == LOW) ? 1 : 0; // Pressed if LOW
    }
}
