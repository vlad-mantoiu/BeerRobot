#include <FastLED.h>

#define NUM_LEDS 34
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

// Enum to represent the different animation states
enum AnimationState {
  IDLE,
  HEADLIGHT,
  LEFT_TURN_SIGNAL,
  RIGHT_TURN_SIGNAL,
  STARTUP
};

// Variable to store the current animation state
AnimationState currentAnimation = IDLE;

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(1000);  // Allow time to open the Serial Monitor
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    switch (input) {
      case '1':
        currentAnimation = HEADLIGHT;
        break;
      case '2':
        currentAnimation = LEFT_TURN_SIGNAL;
        break;
      case '3':
        currentAnimation = RIGHT_TURN_SIGNAL;
        break;
      case '4':
        currentAnimation = STARTUP;
        break;
      case 's':
        // Stop all animations
        currentAnimation = IDLE;
        fill_solid(leds, NUM_LEDS, CRGB::Black);
        FastLED.show();
        break;
      default:
        // Invalid input
        break;
    }
  }

  // Perform the animation based on the current state
  switch (currentAnimation) {
    case HEADLIGHT:
      headlightAnimation();
      break;
    case LEFT_TURN_SIGNAL:
      turnSignalAnimation(0, 6, CRGB::Orange, 400);
      break;
    case RIGHT_TURN_SIGNAL:
      turnSignalAnimation(28, 34, CRGB::Orange, 400);
      break;
    case STARTUP:
      startupAnimation();
      break;
    case IDLE:
      // Do nothing in the IDLE state
      break;
  }
}

void startupAnimation() {
  // Set the color for the startup animation (e.g., blue)
  CRGB startupColor = CRGB::Black;

  // Calculate the middle index of the strip
  int middleIndex = NUM_LEDS / 2;

  // Startup animation: Symmetrical wipe from the middle with rainbow glitter
  for (int i = 0; i <= middleIndex; i++) {
    fill_rainbow(leds + 7, 21, i * 5, 7);  // Rainbow effect for LEDs 7 to 27
    addGlitter(1);  // Add glitter effect (adjust density as needed)
    FastLED.show();
    delay(50);
  }
}

void headlightAnimation() {
  // Set the color for the headlight animation (e.g., white)
  CRGB headlightColor = CRGB::White;
  CRGB headlightColor2 = CRGB::Black;
  // Calculate the middle index of the strip
  int middleIndex = NUM_LEDS / 2;

  // Headlight animation: Symmetrical wipe from the middle
  for (int i = 0; i <= middleIndex; i++) {
    leds[middleIndex - i] = headlightColor;  // Turn on left side
    leds[middleIndex + i] = headlightColor;  // Turn on right side
    FastLED.show();
    delay(50);  // Adjust the delay for the desired animation speed
  }
}

void turnSignalAnimation(int startIdx, int endIdx, CRGB signalColor, int delayTime) {
  // Turn signal animation: Blinking effect
  for (int i = 0; i < 3; i++) {  // Repeat the animation 3 times
    fill_solid(leds + startIdx, endIdx - startIdx, signalColor);  // Turn on the turn signal LEDs
    FastLED.show();
    delay(delayTime);

    fill_solid(leds + startIdx, endIdx - startIdx, CRGB::White);  // Turn off the turn signal LEDs
    FastLED.show();
    delay(delayTime);
  }
}

void addGlitter(int chanceOfGlitter) {
  if (random8() < chanceOfGlitter) {
    leds[random16(7, 28)] += CRGB::White;  // Add a white glitter pixel
  }
}
