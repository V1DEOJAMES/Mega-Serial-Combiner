void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
  while (!Serial || !Serial1 || !Serial2 || !Serial3) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop() {
  if (Serial1.available() > 0) {
    char character1 = '0';
    Serial.print("1: ");
    while (Serial1.available() > 0) {
      if (character1 == '\n') {
        Serial.print("1: ");
      }
      character1 = Serial1.read();
      Serial.print(character1);
      delayMicroseconds(100);
    }
  }
  if (Serial2.available() > 0) {
    char character2 = '0';
    Serial.print("2: ");
    while (Serial2.available() > 0) {
      if (character2 == '\n') {
        Serial.print("2: ");
      }
      character2 = Serial2.read();
      Serial.print(character2);
      delayMicroseconds(100);
    }
  }

  if (Serial3.available() > 0) {
    char character3 = '0';
    Serial.print("3: ");
    while (Serial3.available() > 0) {
      if (character3 == '\n') {
        Serial.print("3: ");
      }
      character3 = Serial3.read();
      Serial.print(character3);
      delayMicroseconds(100);
    }
    //Serial.print("\r\n");
  }
}
