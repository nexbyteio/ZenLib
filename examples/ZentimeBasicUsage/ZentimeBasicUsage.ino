#include <Zentime.h>

unsigned long elapsedTimer = 0;
unsigned long periodicTimer = 0;
unsigned long countdownStart = 0;
unsigned long onceStart = 0;
unsigned long delayStart = 0;

bool onceTriggered = false;

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("Zentime demo started!");
  elapsedTimer = millis();
  periodicTimer = millis();
  countdownStart = millis();
  onceStart = millis();
  delayStart = millis();
}

void loop()
{
  // 1. elapsed: check if a duration has passed
  if (elapsed(elapsedTimer, 2_s))
  {
    Serial.println("[elapsed] 2 seconds passed.");
    elapsedTimer = millis(); // restart
  }

  // 2. elapsedSafe: safe version to handle millis() overflow
  if (elapsedSafe(elapsedTimer, 2_s))
  {
    Serial.println("[elapsedSafe] Safe timer fired.");
  }

  // 3. every: runs every interval
  if (every(3_s, periodicTimer))
  {
    Serial.println("[every] Triggered every 3 seconds.");
  }

  // 4. countdown: how much time remains from 10 seconds
  long remaining = countdown(countdownStart, 10_s);
  if (remaining > 0)
  {
    Serial.print("[countdown] Remaining: ");
    Serial.print(remaining);
    Serial.println(" ms");
  }

  // 5. timePassed: how much time has passed since something started
  Serial.print("[timePassed] Elapsed: ");
  Serial.print(timePassed(countdownStart));
  Serial.println(" ms since countdown started");

  // 6. onceAfter: trigger only once after delay
  if (!onceTriggered && onceAfter(onceStart, 5_s))
  {
    Serial.println("[onceAfter] Triggered once after 5 seconds");
    onceTriggered = true;
  }

  // 7. restartTimer: reset timer manually
  if (Serial.available())
  {
    Serial.read();
    restartTimer(onceStart);
    onceTriggered = false;
    Serial.println("[restartTimer] Timer restarted");
  }

  // 8. delayUntil: like "every", but keeps timing correct even if loop is delayed
  if (delayUntil(4_s, delayStart))
  {
    Serial.println("[delayUntil] Triggered every 4 seconds (even with delay)");
  }

  delay(500); // simulate main loop workload
}
