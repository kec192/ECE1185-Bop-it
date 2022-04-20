// define inputs
#define button 0
#define lever 2
#define encoder 3

// define outputs
#define speaker 9
#define greenLED 6
#define redLED 7

//define constants
#define C5 523
#define E5 659
#define G5 784
#define C6 1047

enum LEDColor {
  red,
  green
};

int startupTune[] = {
  C5,
  G5,
  E5,
  C6
};

int startupTuneSize = sizeof(startupTune) / sizeof(startupTune[0]);

int sel, score;
unsigned long timer; 
bool cor;

void setup() 
{

  timer = 2500;
  score = 0;
  
  /*** Encoder Setup ***/
  pinMode(encoder, INPUT); 
  digitalWrite(encoder, HIGH); //turn pullup resistor on

  /*** Lever Setup ***/
  pinMode(lever, INPUT);
  digitalWrite(lever, HIGH); //turn pullup resistor on

  /*** Button Setup ***/
  pinMode(button, INPUT);
  digitalWrite(button, LOW); //turn pulldown resistor on

  // LED setup
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Speaker setup
  pinMode(speaker, OUTPUT);

  playStartupTune();

  randomSeed(analogRead(5));
}

void loop() 
{
  //selects which noise to play
  sel = randNoiseGen();

  switch(sel)
  {
    // Major third
    case 0:
      tone(speaker, C5, 500);
      delay(500);
      tone(speaker, E5, 500);
      delay(500);
      break;
    // Perfect fifth
    case 1:
      tone(speaker, C5, 500);
      delay(500);
      tone(speaker, G5, 500);
      delay(500);
      break;
    // Octave
    case 2:
      tone(speaker, C5, 500);
      delay(500);
      tone(speaker, C6, 500);
      delay(500);
      break;
    // Default case
    default:
      // "Error tone"
      tone(speaker, C6, 200);
      delay(210);
      tone(speaker, C6, 200);
      delay(210);
      tone(speaker, C6, 200);
      delay(210);
      return;
  }

  delay(200);

  unsigned long startLoop = millis();
  unsigned long deltaTime = 0;

  cor = false;

  do
  {
    //if button pressed
    if(digitalRead(button) == HIGH)
    {
      cor = checkInput(sel,0);
      break;
    }
    //if lever pulled
    else if(digitalRead(lever) == HIGH)
    {
      cor = checkInput(sel,1);
      break;
    }
    //if scroll wheel used
    else if(digitalRead(encoder) == LOW)
    {
      cor = checkInput(sel, 2);
      break;
    }

    // Check how much time has passed since start of loop
    deltaTime = millis() - startLoop;
  } while (deltaTime <= timer);
  
  if(cor)
  {
    score += 1;
    timer *= 0.9;
    blinkLED(green);
  }
  else
  {
    blinkLED(red);
    delay(100);
    gameOver();
  }

}

void playStartupTune() 
{
  for ( int i = 0; i < startupTuneSize; i++ ) {
    tone(speaker, startupTune[i], 150);
    delay(200);
  }
  delay(1000);
}

//function to return random number between 0-2
int randNoiseGen()
{
  return random(0,3);
}

bool checkInput(int sel, int input)
{
  return (sel == input);
}

void blinkLED(LEDColor color)
{
  switch(color)
  {
    case red:
      for ( int i = 0; i < 4; i++ ) {
        tone(speaker, 1000, 200);
        digitalWrite(redLED, HIGH);
        delay(200);
        digitalWrite(redLED, LOW);
        delay(50);
      }
      break;
    case green:
      for ( int i = 0; i < 2; i++ ) {
        tone(speaker, C5, 250);
        digitalWrite(greenLED, HIGH);
        delay(200);
        digitalWrite(greenLED, LOW);
        delay(50);
      }
      delay(100);
      break;
    default:
      break;
  }
}

void gameOver()
{
  // Output score
  for( int i = 0; i < score; i++ ) {
    tone(speaker, C6, 250);
    digitalWrite(greenLED, HIGH);
    delay(250);
    tone(speaker, C6, 250);
    delay(250);
    digitalWrite(greenLED, LOW);
    delay(100);
  }

  score = 0;
  
  // hang until circuit is reset
//  while(1);
}
