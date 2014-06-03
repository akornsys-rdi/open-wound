#define CALTIMER 10000
#define THRESHOLD 1
#include <CapacitiveSensor.h>

CapacitiveSensor blade = CapacitiveSensor(4,2);

void setup() {
   blade.set_CS_AutocaL_Millis(0xFFFF);
   Serial.begin(9600);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
}

void loop() {
  static boolean cal = true;
  static unsigned long timer = 0;
  static unsigned long maxval = 0;
  static unsigned long minval = 0xFFFFFFFF;
  static unsigned long rangeval = 0;
  static unsigned long readval = 0;
  
  timer = millis();
  readval = blade.capacitiveSensor(30);
  if (timer < CALTIMER) {
    cal = true;
    if (readval > maxval) maxval = readval;
    if (readval < minval) minval = readval;
  }
  else {
    if (cal) {
      cal = false;
      rangeval = maxval - minval;
      Serial.print("max: ");
      Serial.println(maxval, DEC);
      Serial.print("min: ");
      Serial.println(minval, DEC);
      Serial.print("range: ");
      Serial.println(rangeval, DEC);
    }
    else {
      do {
        readval = blade.capacitiveSensor(30);
        if (((readval - maxval) > (rangeval * THRESHOLD)) && (readval > maxval)) digitalWrite(13, HIGH);
        else digitalWrite(13, LOW);
        delay(50);
        Serial.println(readval);
      } while(1);
    }
  }
}
