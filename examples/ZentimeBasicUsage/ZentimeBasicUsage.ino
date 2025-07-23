#include <Zentime.h>

unsigned long lastPrint = 0;
unsigned long onceStart = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("ZenLib demo starting...");
}

void loop() {
  if (every(3_s, lastPrint)) {
    Serial.println("Every 3 seconds event");
  }

  if (onceAfter(onceStart, 10_s)) {
    Serial.println("Only once after 10 seconds");
    onceStart = millis() + 2_s; // Prevent repeating
  }
}
