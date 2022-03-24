#define outPin 13
#define inPin 8

void setup() {
  // put your setup code here, to run once:
  pinMode(outPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(inPin) == HIGH) {
    digitalWrite(outPin, HIGH);
    delay(1000);
    digitalWrite(outPin, LOW);
    delay(1000);
  }
}

/********8
One fish
Two fish
Red fish
Blue fish.
Black fish
Blue fish
Old fish
New fish [1].
- John Sima
[1. Theodor Seuss Geisel]
*/
