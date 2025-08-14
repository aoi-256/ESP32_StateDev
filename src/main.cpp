#include <Arduino.h>
#include "core/StateManager.hpp"

StateManager stateManager;

void setup() {

  Serial.begin(115200);
  Serial.println("State Manager Example Started");
}

void loop() {

  stateManager.update();

  delay(1);
}