#define UPDATE_TIME 5000 //milisegundos de repeticion de los pir
#define BLADES 12 //numero de sensores
#define DELAY 1000 //milisegundos de deteccion de pulsos
const byte sensorpin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, A0, A1, A2}; //pines lectura de los sensores

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < BLADES + 1; i++) {
    pinMode(sensorpin[i], INPUT);
  }
  pinMode(13, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A3, HIGH);
}

void loop() {
  byte c = 0;
  boolean touch = false;
  static boolean pir = false;
  static boolean sense[BLADES + 1];
  static boolean active[BLADES + 1];
  static unsigned long timer = 0;
  static unsigned long timeout[BLADES + 1];
  
  for (byte i = 0; i < BLADES; i++) {
    if (digitalRead(sensorpin[i])) {
      if (!active[i]) {
        timeout[i] = millis();
        active[i] = true;
      }
      else {
        if ((timeout[i] + DELAY) > millis()) {
          sense[i] = true;
          Serial.write((i*2)+1);
        }
      }
    }
    else {
      if (sense[i]) {
        Serial.write(i*2);
        sense[i] = false;
      }
      active[i] = false;
    }
  }
  touch = false;
  for (byte i = 0; i < BLADES; i++) {
    if (sense[i] == true) touch = true;
  }
  if (touch) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
  if (Serial.available()) {
    c = Serial.read();
    if (c == 0x50) digitalWrite(A3, LOW);
    else if (c == 0x51) digitalWrite(A3, HIGH);
  }
  if ((digitalRead(A4)) || (digitalRead(A5))) {
    if ((timer + UPDATE_TIME) < millis()) {
      timer = millis();
      Serial.write(0x21);
    }
  }
  else {
    pir = false;
  }
}

