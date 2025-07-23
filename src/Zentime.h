#ifndef ZENTIME_H
#define ZENTIME_H

// ======== Time literals ========
constexpr unsigned long operator"" _ms(unsigned long long ms) { return ms; }
constexpr unsigned long operator"" _s(unsigned long long s) { return s * 1000UL; }
constexpr unsigned long operator"" _min(unsigned long long m) { return m * 60UL * 1000UL; }
constexpr unsigned long operator"" _hr(unsigned long long h) { return h * 3600000UL; }
constexpr unsigned long operator"" _day(unsigned long long d) { return d * 86400000UL; }

// ======== Time helpers ========
inline bool elapsed(unsigned long start, unsigned long duration) {
  return millis() - start >= duration;
}

inline bool elapsedSafe(unsigned long start, unsigned long duration) {
  return (long)(millis() - start) >= (long)duration;
}

inline bool every(unsigned long interval, unsigned long& last) {
  if (millis() - last >= interval) {
    last = millis();
    return true;
  }
  return false;
}

inline long countdown(unsigned long start, unsigned long duration) {
  return (long)duration - (long)(millis() - start);
}

inline unsigned long timePassed(unsigned long start) {
  return millis() - start;
}

inline bool onceAfter(unsigned long start, unsigned long delay) {
  return (millis() - start) >= delay;
}

inline void restartTimer(unsigned long& last) {
  last = millis();
}

inline bool delayUntil(unsigned long interval, unsigned long& last) {
  unsigned long now = millis();
  if (now - last >= interval) {
    last = now;
    return true;
  }
  return false;
}

#endif // ZENTIME_H
