//// Rotary Encoder Inputs
//#define CLK 2
//#define DT 3
//#define SW 4
//
//#define outPin 13
//
//int counter = 0;
//int currentStateCLK;
//int lastStateCLK;
//String currentDir ="";
//unsigned long lastButtonPress = 0;
//
//void setup() {
//  
//  // Set encoder pins as inputs
//  pinMode(CLK,INPUT);
//  pinMode(DT,INPUT);
//  pinMode(SW, INPUT_PULLUP);
//
//  pinMode(outPin, OUTPUT);
//
//  // Setup Serial Monitor
//  Serial.begin(9600);
//
//  // Read the initial state of CLK
//  lastStateCLK = digitalRead(CLK);
//}
//
//void loop() {
//  
//  // Read the current state of CLK
////  currentStateCLK = digitalRead(CLK);
////
////  // If last and current state of CLK are different, then pulse occurred
////  // React to only 1 state change to avoid double count
////  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
////
////    // If the DT state is different than the CLK state then
////    // the encoder is rotating CCW so decrement
////    if (digitalRead(DT) != currentStateCLK) {
////      counter --;
////      currentDir ="CCW";
////      digitalWrite(outPin, HIGH);
////      delay(1);
////    } else {
////      // Encoder is rotating CW so increment
////      counter ++;
////      currentDir ="CW";
////      digitalWrite(outPin, HIGH);
////      delay(1);
////    }
////
////    digitalWrite(outPin, LOW);
////  }
////
////  // Remember last CLK state
////  lastStateCLK = currentStateCLK;
//
//if (digitalRead(SW) == HIGH) {
//  digitalWrite(outPin, HIGH);
//} else {
//  digitalWrite(outPin, LOW);
//}
//}

//these pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;

#define outPin 13

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
  Serial.begin (9600);

  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);

  pinMode(outPin, OUTPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);

}

void loop(){ 
  //Do stuff here

  digitalWrite(outPin, LOW);

  Serial.println(encoderValue);
  delay(100); //just here to slow down the output, and show it will work  even during a delay
}


void updateEncoder(){
  digitalWrite(outPin, HIGH);
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}