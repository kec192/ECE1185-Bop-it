#define encoderPin 3

#define Lever 2

#define LED 13

#define SpeakerPin 9

#define C5 523
#define E5 659
#define G5 784
#define C6 1047

int speakerArray[] = {
    C5,
    E5,
    G5,
    C6
  };

void setup() {
  /*** Encoder Setup ***/
  pinMode(encoderPin, INPUT); 
  digitalWrite(encoderPin, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(digitalPinToInterrupt(encoderPin), 
                  updateEncoder, 
                  CHANGE); 

  /*** Lever Setup ***/
  pinMode(Lever, INPUT);
  digitalWrite(Lever, HIGH); //turn pullup resistor on

  attachInterrupt(digitalPinToInterrupt(Lever), 
                  updateLever, 
                  CHANGE);

  // LED setup
  pinMode(LED, OUTPUT);

  // Speaker setup
  pinMode(SpeakerPin, OUTPUT);

  playSong();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void playSong() {
  for( int i = 0; i < 4; i++ ) {
    tone(SpeakerPin, speakerArray[i], 150);
    delay(200);
  }
}

void updateEncoder(){
    tone(SpeakerPin, C5, 150);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
}

void updateLever() {
    tone(SpeakerPin, C6, 150);
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
}
