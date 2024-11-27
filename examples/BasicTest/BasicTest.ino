#include <SmartSW.h>

// Define LED and button pins
#define LED_PIN 9
const uint8_t buttonPins[] = {7}; // Start with a single button
#define NUM_BUTTONS 1             // Adjust this if adding more buttons

// Create an instance of SmartSW
SmartSW smartSwitch(LED_PIN, buttonPins, NUM_BUTTONS);

void setup() {
    smartSwitch.begin();
    smartSwitch.setBlinkSpeed(100); // Set blink speed in ms

    for (uint8_t i = 0; i < NUM_BUTTONS; ++i) {
        smartSwitch.setButtonColors(i, 255, 0, 0, 0, 0, 255); // (Color ON)(r,g,b) and (Color ON/Blink)(r,g,b)
    }
}

void loop() {
    smartSwitch.loop();

    // Update each button's light state based on physical state
    for (uint8_t i = 0; i < NUM_BUTTONS; ++i) {
        if (smartSwitch.getPhysicalState(i) == 1) { // Button is pressed
            smartSwitch.setLightState(i, 1);        // Set LED to BLINKING set to 2 for blinking
        } else {
            smartSwitch.setLightState(i, 0);        // Turn LED OFF
        }
    }
}
