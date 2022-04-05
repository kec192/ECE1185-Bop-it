#define outPin 13
#define inPin 8

void setup() {
  // put your setup code here, to run once:

  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(inPin) == LOW) {
    digitalWrite(outPin, HIGH);
  } else {
    digitalWrite(outPin, LOW);  
  }

}
