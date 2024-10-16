#ifndef BUZZERCONFIG_H
#define BUZZERCONFIG_H

class BuzzerConfig {
  private:
    int pin;

  public:
    BuzzerConfig(int pin) {
      this->pin = pin;
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);  
    }

    void on() {
      digitalWrite(pin, HIGH);
    }

    void off() {
      digitalWrite(pin, LOW);
    }
};

#endif
