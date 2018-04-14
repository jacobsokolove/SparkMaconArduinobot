//**********************************************************************//
//*                                                                    *//
//*  SparkMacon ArduinoBot                                             *//
//*                                                                    *//
//*  This is a sketch for a robot. The robot has three sensory inputs: *//
//*    two photoresistors and an ultrasonic sensor.                    *//
//*                                                                    *//
//*  The circuit:                                                      *//
//*      See the github for all diagrams and instructions:             *//
//*      https://github.com/jacobsokolove/SparkMaconArduinobot/        *//
//*                                                                    *//
//*  3-12-2017                                                         *//
//*  Created By:                                                       *//
//*    Jacob Sokolove                                                  *//
//*    jacobsokolove@gmail.com                                         *//
//*    +1 678-346-5895                                                 *//
//*                                                                    *//
//*                                                                    *//
//*  Day-Month-Year                                                    *//
//*  By: author's name                                                 *//
//*                                                                    *//
//**********************************************************************//


//Servo Libray Declaration and Motor Declaration
#include <Servo.h>

  Servo ServoLeft;
  Servo ServoRight;


//Pin Assignments

/* Sets the Pins for the Servos in pin 10 and 11 respectively
 * Any pin can be used as long as it has a "~" next to the number.
 * The "~" denotes the pin as one being able to handle a PWM signal.
 */ 

  const int MotorLeft=11;     // Denoting the pin assignment for the left motor
  const int MotorRight=10;   // Denoting. thep pin assigment for the right motor 


// Defines Trigger and Echo pins numbers for the UltraSonic Sensor

  const int trigPin = 4;
  const int echoPin = 5;

  long duration;
  int sensorDistance;





  
//********************************************//
// *                                         *//
// * THE ANGLES AND DISTANCES CAN BE CHANGED *//
// *                                         *//
//********************************************//


/* 
 * Input desired angle of turn relative to the y axis
 * i.e. 90 deg = sharp right 
 * 
 * varying the angle will allow the bot to follow various
 * paths to creating different polygons
 */
 
  int  cwAngle = 90; // makes a right turn
  int forwardDistance = 3; // moves roughly 3 inches

  int ccwAngle = 90; // makes a left turn
  int backwardDistance = 3; // moves roughly 3 inches





  
// DO NOT CHANGE THE NEXT 4 LINES 

  int cwAngleScaleFactor = cwAngle * 8;
  int ccwAngleScaleFactor = ccwAngle * 8;
  int forwardDistanceScaleFactor = forwardDistance * 100;
  int backwardDistanceScaleFactor = backwardDistance * 100;



void forward(){

//control structure for forward movement
  
  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(180);
  ServoRight.write(0);
  delay(forwardDistanceScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  
}


void backward(){
  
  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(0);
  ServoRight.write(180);
  delay(backwardDistanceScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  
}


void turnClockwise(){

  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(0);
  ServoRight.write(0);
  delay(cwAngleScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  
}


void turnCounterClockwise(){

  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);
  
  ServoLeft.write(180);
  ServoRight.write(180);
  delay(ccwAngleScaleFactor);
  ServoLeft.detach();
  ServoRight.detach();
  
}


void distanceSensor(){
  
// Clears the trigPin
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds

  duration = pulseIn(echoPin, HIGH);

// Calculating the distance

  sensorDistance= duration*0.034/2;

// Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(sensorDistance);

}


void setup() {


//Servo (Motor) Setup

  pinMode(MotorLeft,OUTPUT); 
  pinMode(MotorRight,OUTPUT);


  delay(10);
  ServoLeft.attach(MotorLeft);
  ServoRight.attach(MotorRight);

// Ultrasonic Sensor Setup

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication
  
}


void loop() {

  // Defines the photoresistors  pins 

  int leftPhotoresistor = analogRead(A5);
  int rightPhotoresistor = analogRead(A4);
  
  // read the input on analog pin 0 and 1:
  // print out the value you read:
  
  Serial.print("Left resistor: ");
  Serial.println(leftPhotoresistor);
  
  Serial.print("Right resistor: "); 
  Serial.println(rightPhotoresistor);
  delay(1000);        // delay in between reads for 


  distanceSensor();



  


//Automation Section:

  if(sensorDistance<6){
    
  backward();
  
  }

  else {

    forward();
    
  }


  if(leftPhotoresistor && rightPhotoresistor > 300){
    
    if(leftPhotoresistor<800){

      turnClockwise();
    
    }

    else {

      forward();
    
    }
    
    if(rightPhotoresistor<800){

      turnCounterClockwise();
    
    }

    else {

      forward();
    
    }
  
  }
  

  
}
