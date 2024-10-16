#ifndef PULSESENSOR_H
#define PULSESENSOR_H

class PulseSensor {
  private:
    int pin;
    int pulseCount;

  public:
    PulseSensor(int pin) {
      this->pin = pin;
      pulseCount = 0;
      pinMode(pin, INPUT);
    }

    int read() {
      return analogRead(pin);
    }

    void countPulse() {
      pulseCount++;
    }

    int calculatePPM() {
      return pulseCount * 4;
    }

    void resetCount() {
      pulseCount = 0;
    }
};

#endif
