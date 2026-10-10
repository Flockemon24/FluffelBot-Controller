#include <Arduino.h>
#include <driver/ledc.h>

struct Motor {
  uint8_t in1;
  uint8_t in2;
  uint8_t pwm;
};

const Motor motors[4] = {
  {16, 17, 18},  // Motor 1
  {19, 23, 25},  // Motor 2
  {26, 27, 32},  // Motor 3
  {33, 14,  4}   // Motor 4
};

const uint8_t STBY = 13; 

const uint32_t PWM_FREQ = 20000;
const uint8_t PWM_BITS = 8;     

void setMotor(uint8_t motor, int speed) {
  if (motor < 1 || motor > 4) {
    return;
  }

  speed = constrain(speed, -255, 255);

  const Motor &m = motors[motor - 1];

  if (speed > 0) {
    digitalWrite(m.in1, HIGH);
    digitalWrite(m.in2, LOW);
    ledcWrite(m.pwm, speed);
  } 
  else if (speed < 0) {
    digitalWrite(m.in1, LOW);
    digitalWrite(m.in2, HIGH);
    ledcWrite(m.pwm, -speed);
  } 
  else {
    ledcWrite(m.pwm, 0);
    digitalWrite(m.in1, LOW);
    digitalWrite(m.in2, LOW);
  }
}

void stopAll() {
  for (int i = 1; i <= 4; i++) {
    setMotor(i, 0);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, LOW); 

  for (const Motor &m : motors) {
    pinMode(m.in1, OUTPUT);
    pinMode(m.in2, OUTPUT);

    if (!ledcAttach(m.pwm, PWM_FREQ, PWM_BITS)) {
      Serial.println("Fehler beim Einrichten eines PWM-Pins!");
    }
  }

  stopAll();

  digitalWrite(STBY, HIGH);

  Serial.println("FluffelBot-Controller gestartet!");
}

void loop() {
  for (int i = 1; i <= 4; i++) {
    setMotor(i, 180);
  }
  delay(2000);

  for (int i = 1; i <= 4; i++) {
    setMotor(i, -180);
  }
  delay(2000);

  setMotor(1, 200);
  setMotor(2, 200);
  setMotor(3, 0);
  setMotor(4, 0);
  delay(2000);

  stopAll();
  delay(2000);
}
