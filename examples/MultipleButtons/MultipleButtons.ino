#include <SmartSW.h>

// Define LED and button pins
#define LED_PIN 9
const uint8_t buttonPins[] = {7, 4, 8, 12}; // Pins for the 4 buttons
#define NUM_BUTTONS 4                       // Number of buttons and LEDs

// Create an instance of SmartSW
SmartSW smartSwitch(LED_PIN, buttonPins, NUM_BUTTONS);

void setup() {
    smartSwitch.begin();
    smartSwitch.setBlinkSpeed(500); // Set blink speed in ms

    // Set colors for each button's LED
    for (uint8_t i = 0; i < NUM_BUTTONS; ++i) {
        smartSwitch.setButtonColors(
            i,                           // Button index
            255, 0, 0,                   // ON Color: Red (r, g, b)
            0, 0, 255                    // BLINK Color: Blue (r, g, b)
        );
    }
}

void loop() {
    smartSwitch.loop();

    // Update each button's light state based on physical state
    for (uint8_t i = 0; i < NUM_BUTTONS; ++i) {
        if (smartSwitch.getPhysicalState(i) == 1) { // Button is pressed
            smartSwitch.setLightState(i, 2);        // Set LED to BLINKING
        } else {
            smartSwitch.setLightState(i, 0);        // Turn LED OFF
        }
    }
}
