# ZenLib

ZenLib is a clean, modern Arduino library offering human-readable time literals and helpers for `millis()`-based timing.

Powered by the `Zentime` module, it helps you write elegant, non-blocking code.

## ✨ Features

- Time literals: `1_s`, `10_min`, `500_ms`, `1_hr`, `1_day`
- Helpers: `every()`, `elapsed()`, `countdown()`, `onceAfter()`, `delayUntil()`
- Header-only. Lightweight. No dependencies.

## 🚀 Example

```cpp
#include <Zentime.h>

unsigned long lastBlink = 0;

void loop() {
  if (every(1_s, lastBlink)) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
```

## 📥 Installation

- Arduino IDE: Install via ZIP or Library Manager (when published)
- PlatformIO: Use `lib_deps = https://github.com/nexbyteio/ZenLib`

## 🧠 License

MIT
