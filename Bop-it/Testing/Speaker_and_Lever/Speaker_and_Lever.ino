#define outPin 9
#define inPin 8

void setup() {
  // put your setup code here, to run once:

  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(inPin) == LOW) {
    tone(outPin, 1000);
  } else {
    noTone(outPin);
  }

}
