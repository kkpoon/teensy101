#define REDPIN   23
#define GREENPIN 22
#define BLUEPIN  21

int red[] = {
  103, 178, 214, 244, 253, 247, 209, 146, 67, 33, 5};
int green[] = {
  0, 24, 96, 165, 219, 247, 229, 197, 147, 102, 48};
int blue[] = {
  31, 43, 77, 130, 199, 247, 240, 222, 195, 172, 97};

int idx = 0;

void setup()
{
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop()                     
{
  analogWrite(REDPIN, red[idx]);
  analogWrite(GREENPIN, green[idx]);
  analogWrite(BLUEPIN, blue[idx]);
  
  idx++;
  if (idx >= 11) {
    idx = 0;
  }
  delay(1000);
}
