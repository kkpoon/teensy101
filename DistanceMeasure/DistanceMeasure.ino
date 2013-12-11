#define REDPIN 23
#define GREENPIN 22
#define BLUEPIN 21

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 450

long distance;
long cm;

int red = 0;
int green = 0;
int blue = 0;

void setup()
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop()
{
  // The DYP-ME007 pings on the low-high flank...
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);   

  // the distance is proportional to the time interval
  // between HIGH and LOW

  distance = pulseIn(ECHO_PIN, HIGH);
  cm = distance/58;

  if (cm > MAX_DISTANCE) {
    analogWrite(REDPIN, 0);
    analogWrite(GREENPIN, 255);
  } 
  else {
    red = 255 - (cm * 255 / MAX_DISTANCE);
    red = red > 255 ? 255 : red;
    red = red < 0 ? 0 : red;
    analogWrite(GREENPIN, 0);
    analogWrite(REDPIN, red);
  }

  Serial.println(cm);
  delay(100);
}
