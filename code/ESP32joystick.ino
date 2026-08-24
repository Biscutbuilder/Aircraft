const int buttonPin = 32;
const int xPin = 13;
const int yPin = 12;


int buttonState = 0;
int xValue = 0;
int yValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = analogRead(xPin);

  xValue = analogRead(xPin);
  yValue = analogRead(yPin);


Serial.println(xValue);
Serial.print("\t");
Serial.println(yValue);

delay(110);
}
