#include <ESP32Servo.h>

Servo s1, s2, s3, s4;

int a1 = 90, a2 = 90, a3 = 90, a4 = 90;
String input = "";

void setup(){
  Serial.begin(9600);

  s1.attach(18);
  s2.attach(19);
  s3.attach(21);
  s4.attach(22);
}

void loop(){
  while(Serial.available()){
    char c = Serial.read();

    if(c == '\n'){
      int vals[4];
      int i = 0;

      char *token = strtok((char*)input.c_str(), ",");

      while(token != NULL && i < 4){
        vals[i++] = atoi(token);
        token = strtok(NULL, ",");
      }

      if(i == 4){
        if(vals[0] >= 0 && vals[0] <= 180) a1 = vals[0];
        if(vals[1] >= 0 && vals[1] <= 180) a2 = vals[1];
        if(vals[2] >= 0 && vals[2] <= 180) a3 = vals[2];
        if(vals[3] >= 0 && vals[3] <= 180) a4 = vals[3];
      }

      input = "";
    } else {
      input += c;
    }
  }

  s1.write(a1);
  s2.write(a2);
  s3.write(a3);
  s4.write(a4);
}