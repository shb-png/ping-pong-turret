// Assign pins:

// Pan stepper motor (base rotation):
const int pan_stepper_dir = 4;
const int pan_stepper_step = 3;

// Tilt stepper motor (up/down barrel control):
const int tilt_stepper_dir = 6;
const int tilt_stepper_step = 5;


//generic steps per revolution (used for both motors):
const int stepsPerRevolution = 100; 

const int stepDelay = 10; //delay in a step in miliseconds 

//joystick pins to be added here:
const int x_stick = A0;
const int y_stick = A1;
const int button_stick = 7;

// pin to activate solenoid MOSFET
const int solenoid_pin = 8;

//custom functions 

void motorStep (int stepName, int stepCount, int dir) {
  
  // sending signals to the stepper motor of choice
  if (stepName == 0) {
    digitalWrite(pan_stepper_dir, dir);
    for (int i = 0; i < stepCount; i++) {
      digitalWrite(pan_stepper_step, HIGH);
      delay(stepDelay);
      digitalWrite(pan_stepper_step, LOW);
      delay(stepDelay);
    }
  } else {
    digitalWrite(tilt_stepper_dir, dir);
    for (int i = 0; i < stepCount; i++) {
      digitalWrite(tilt_stepper_step, HIGH);
      delay(stepDelay);
      digitalWrite(tilt_stepper_step, LOW);
      delay(stepDelay);
    }
  }
}

void setup() {
  // make the pins actually work !!
  Serial.begin(9600);
  pinMode(pan_stepper_dir, OUTPUT);
  pinMode(pan_stepper_step, OUTPUT);
  pinMode(tilt_stepper_dir, OUTPUT);
  pinMode(tilt_stepper_step, OUTPUT);

  pinMode(x_stick, INPUT);
  pinMode(y_stick, INPUT);
  pinMode(button_stick, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Joystick movement interpretation
  /* 
  later these joystick movements can probably just be included in the connection with 
  the python script that will include the tag tracking
  
  */

  if (analogRead(x_stick) > 520) {
    // joystick is pointing to the right
    motorStep(0, 10, 0);
  }
  if (analogRead(x_stick) < 500) {
    //joystick is pointing to the left
    motorStep(0, 10, 1);
  }
  if (analogRead(y_stick) > 520) {
    // joystick is pointing down
    motorStep(1, 10, 0);
  }
  if (analogRead(y_stick) < 500) {
    //joystick is pointing up
    motorStep(1, 10, 1);
  }

  if(digitalRead(button_stick) == 1){
    digitalWrite(solenoid_pin, HIGH);
    delay(5);
    digitalWrite(solenoid_pin, LOW);
    delay(1000);
    Serial.println("solenoid activated");
  }

}

/*
At this point I'm thinking of switching to using a raspberry pi instead.
I'm unsure of how to use april tags and arduino together (if that can even work ;-;)
I think I'm just gonna go the well-documented route of PhotonVision + RPi to save myself 
a bit of sanity lol
*/
