#define REDPIN   23
#define GREENPIN 22
#define BLUEPIN  21

int red = 0;
int green = 0;
int blue = 0;

void setup()   {
  // initialize the digitals pin as an outputs
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop()                     
{
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  analogWrite(REDPIN, red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
  delay(2000);
}
