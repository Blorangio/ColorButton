/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/Documents/CTD_2023/Personal_Projects/ColorButton/src/ColorButton.ino"
void setup();
void loop();
#line 1 "/Users/admin/Documents/CTD_2023/Personal_Projects/ColorButton/src/ColorButton.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
void setup() {
  pinMode(D1, INPUT);
  pinMode(A5, INPUT);
  pinMode(D0, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  Serial.begin(9600);
}
bool cont = false;
bool onOff = false;
bool cont2 = false;
bool onOff2 = false;
int red = 0;
int green = 0;
int blue = 0;
int current = 0;
int current2 = 0;
int colors[5][3];
void loop() {
  if(current==0) {
    int analog = analogRead(A5);
    red = round((analog*255/4095));
    analogWrite(D4, red);
  } else if(current==1) {
    int analog = analogRead(A5);
    red = round((analog*255/4095));
    analogWrite(D5, red);
  } else {
    int analog = analogRead(A5);
    red = round((analog*255/4095));
    analogWrite(D6, red);
  }
  if(digitalRead(D0)==HIGH&&!cont) {
    Serial.println("Button Down");
    onOff = !onOff;
    current+=1;
    cont=true;
  }
  if(digitalRead(D0)==LOW) {
    cont = false;
  }
  if(digitalRead(D1)==HIGH&&!cont2) {
    Serial.println("Button Down2");
    onOff2 = !onOff2;
    current2+=1;
    cont2=true;
  }
  if(digitalRead(D1)==LOW) {
    cont2 = false;
  }
}