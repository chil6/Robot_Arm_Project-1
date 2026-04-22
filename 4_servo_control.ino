#include <ESP32Servo.h>

Servo s1, s2, s3, s4;

void setup(){
  s1.attach(18);
  s2.attach(19);
  s3.attach(21);
  s4.attach(22);
}

void loop(){
  int p1 = analogRead(34);
  int p2 = analogRead(35);
  int p3 = analogRead(32);
  int p4 = analogRead(33);

  s1.write(map(p1, 0, 4095, 0, 180));
  s2.write(map(p2, 0, 4095, 0, 180));
  s3.write(map(p3, 0, 4095, 0, 180));
  s4.write(map(p4, 0, 4095, 0, 180));

  delay(20);
}