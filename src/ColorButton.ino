SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
void setup() {
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
int red = 0;
int green = 0;
int blue = 0;
int current = 0;
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
}