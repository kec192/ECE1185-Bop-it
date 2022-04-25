#define outPin1 6
#define outPin2 7
#define inPin 0

void setup() {
  // put your setup code here, to run once:

  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  pinMode(inPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(inPin) == HIGH) {
    digitalWrite(outPin1, HIGH);
    digitalWrite(outPin2, HIGH);
  } else {
    digitalWrite(outPin1, LOW);
    digitalWrite(outPin2, LOW);  
  }

}
