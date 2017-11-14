// This is a program to run a mini arduino robot.
#include <Servo.h>


//Instantiating the Left and Right Motors

Servo ServoLeft;
Servo ServoRight;

// Sets the Pins for the Servos in pin 10 and 11 respectively
// Any pin can be used as long as it has a "~" next to the number.
// The "~" denotes the pin as one being able to handle a PWM signal.

  int MotorLeft=11;     // Denoting the pin assignment for the left motor
  int MotorRight=10;   // Denoting. thep pin assigment for the right motor 

  
void setup() {


//Denoting that each respective element is an ouput.

  pinMode(MotorLeft,OUTPUT); 
  pinMode(MotorRight,OUTPUT);


// Tells the Arduino that not only are the devices on pins 10 and 11 outputs,
// but they are also servo devices (one can also drive a brushless motor in the same manner).

  
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  

}

////THIS COMMENTED SECTION IS LEGACY CODE DO NOT USE

/*
// This function drives the bot backward for int b seconds.

void backward(){

  int b=2000;

  ServoLeft.write(0);
  ServoRight.write(180);
  delay(b);
  ServoLeft.write(90);
  ServoRight.write(90);
  
}



// This function turns the bot left.


void left(){

  int c=1200;

  ServoLeft.write(180);
  ServoRight.write(180);
  delay(c);
  ServoLeft.write(90);
  ServoRight.write(90);
  
}

//This function turns the robot right.

void right (){

  int d=1200;

  ServoLeft.write(0);
  ServoRight.write(0);
  delay(d);
  ServoLeft.write(70);
  ServoRight.write(70);
  
}

*/

// This function drives the bot forward for int a seconds.

void forward(){

  // Input the desired distance here:

  int distance;
   distance = 3;
  int distanceScaleFactor = distance * 100;

//control structure for forward movement
  
  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(180);
  ServoRight.write(0);
  delay(distanceScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  
}



// Input desired angle of turn relative to the positive y axis 
//i.e. 90 deg= right turn 180= turn around 270= left turn
// varying the angle at which one turns can allow the bot to
// follow various paths in the shape of polygons

void turnClockwise(){

  int angle;
    angle = 90;
  int angleScaleFactor = angle * 8;


// control structure for turns

  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(0);
  ServoRight.write(0);
  delay(angleScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  

  
}


void loop() {

  forward();
  turnClockwise();
  forward();
  


}





















