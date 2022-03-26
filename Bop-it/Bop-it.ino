#define outTone 
#define button
#define lever 
#define scrollWheel
//function to return random number between 0-2
int randNoiseGen()
{
  return random(3);
}

bool checkInput(sel, input)
{
  if(sel == input)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void(decreaseTime)
{
  
}

void setup() 
{
  // put your setup code here, to run once:
  float C5 = 523
  float E5 = 659
  float G5 = 784
  float C6 = 1047
  int sel, score; 
  int timer = 500;
  bool cor;
}

void loop() 
{
  //selects which noise to play
  sel = randNoiseGen();
  
  //major third
  if(sel == 0)
  {
    tone(outTone, C5, 500) //play C5 for 500 ms
    tone(outTone, E5, 500) //play E5 for 500 ms
  }

  //perfect fifth
  else if(sel == 1)
  {
    tone(outTone, C5, 500) //play C5 for 500 ms
    tone(outTone, G5, 500) //play G5 for 500 ms
  }

  //octave
  else if(sel == 2)
  {
    tone(outTone, C5, 500) //play C5 for 500 ms
    tone(outTone, C6, 500) //play C6 for 500 ms
  }
  //wait for timer length for user input
  while(millis() <= timer)
  {
    //check userInput

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
    else if(digitalRead(scrollWheel) == HIGH)
    {
      cor = checkInput(sel, 2);
      break;
    }
  }
  if(cor)
  {
    decreaseTime();
    blinkLED(green);
  else
  {
    blinkLED(red);
    gameOver();
  }
  }

}
