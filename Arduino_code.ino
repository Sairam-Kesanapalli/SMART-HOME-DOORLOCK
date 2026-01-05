#include <Arduino.h>

#define RELAY_PIN 12
#define BUZZER_PIN 14

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // relay OFF (locked)

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("ESP Ready");
}

void unlockDoor() {
  digitalWrite(RELAY_PIN, LOW); // active low relay
  Serial.println("Door Unlocked");
}

void lockDoor() {
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("Door Locked");
}

void alarmTrigger() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  Serial.println("Alarm Triggered");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "UNLOCK") {
      unlockDoor();
    }
    else if (cmd == "LOCK") {
      lockDoor();
    }
    else if (cmd == "ALARM") {
      alarmTrigger();
    }
  }
}
