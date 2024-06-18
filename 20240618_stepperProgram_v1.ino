// I'm trying to get into the habit of actually commenting up my code so I can actually remember what it does, lets see if I stick with that ;-;

//determines the direction of the motor (CW or CCW)
const int dirPin = 4;

//for every pulse of a signal sent through this pin, one step is made by the motor
const int stepPin = 3;

//the number used in the motorTurn function that is created in line ___
const int stepsPerRevolution = 200;

// I have no idea what the line below was for, I am keeping it as decoration now.
// const int logicPower = 6;


void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

/*
Below lies the relic of past failures. This was the old version of the motorTurn function

  pinMode(logicPower, OUTPUT);
  analogWrite(logicPower, 153);
  void spin (int count, int dir, int del) {
    digitalWrite(dirPin, dir);
    for (int i = 0; i < count; i++) {
      analogWrite(stepPin, customHIGH);
      delayMicroseconds(del);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(del);
      }
    }
*/

  
  pinMode(LED_BUILTIN, OUTPUT);

/*
This is where I found out that Arduino's IOT dashboard app only works with certain boards. 
It doesn't work with the UNO R3, which is what I am using. I'm not sure if I'm going to buy
a different board, or if there is a way I can create a local dashboard. 

I also want to integrate computer vision, so I dont know how that factors in quite yet. 
*/

void loop() {

  //Code below is just a little blinking action to see if my board is actually connected 
    digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                     
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500); 
  
  // Setting the motor direction to be clockwise
  digitalWrite(dirPin, HIGH);


  
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(stepPin, HIGH);
      delay(10);
      digitalWrite(stepPin, LOW);

      Serial.println("running");
      }
}
