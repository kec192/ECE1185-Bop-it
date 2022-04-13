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
  // put your setup code here, to run once:
  pinMode(SpeakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i = 0; i < 4; i++ )
  {
    tone(SpeakerPin, speakerArray[i], 500);
    delay(700);
  }
}
