#define SERIAL1_PIN A1
#define SERIAL2_PIN A2
#define SERIAL3_PIN A3

void setup() {
  pinMode(SERIAL1_PIN, INPUT);
  pinMode(SERIAL2_PIN, INPUT);
  pinMode(SERIAL3_PIN, INPUT);
  Serial.begin(115200);

  if (digitalRead(SERIAL1_PIN)) {
    Serial1.begin(9600);
    Serial.println(" 1 = 9600");
  }
  else {
    Serial1.begin(115200);
    Serial.println(" 1 = 115200");
  }
  if (digitalRead(SERIAL2_PIN)) {
    Serial2.begin(9600);
    Serial.println(" 2 = 9600");
  }
    else {
    Serial1.begin(115200);
    Serial.println(" 2 = 115200");
  }
  if (digitalRead(SERIAL3_PIN)) {
    Serial3.begin(9600);
    Serial.println(" 3 = 9600");
  }
    else {
    Serial3.begin(115200);
    Serial.println(" 3 = 115200");
  }

  while (!Serial || !Serial1 || !Serial2 || !Serial3) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop() {
  if (Serial1.available() > 0) {
    char character1 = '0';
    //Serial.print("1: ");
    while (Serial1.available() > 0) {
      if (character1 == '\n') {
        //Serial.print("1: ");
      }
      character1 = Serial1.read();
      Serial.print(character1);
      delayMicroseconds(100);
    }
  }
  if (Serial2.available() > 0) {
    char character2 = '0';
    //Serial.print("2: ");
    while (Serial2.available() > 0) {
      if (character2 == '\n') {
        //Serial.print("2: ");
      }
      character2 = Serial2.read();
      Serial.print(character2);
      delayMicroseconds(100);
    }
  }

  if (Serial3.available() > 0) {
    char character3 = '0';
    //Serial.print("3: ");
    while (Serial3.available() > 0) {
      if (character3 == '\n') {
        //Serial.print("3: ");
      }
      character3 = Serial3.read();
      Serial.print(character3);
      delayMicroseconds(100);
    }
    //Serial.print("\r\n");
  }
}
