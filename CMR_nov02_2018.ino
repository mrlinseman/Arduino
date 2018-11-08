// CARL 6 CodeMyRobot.ca
// Ask teachers to upload your video to codemyrobotchallenge.com
// New school libraries can register at codemyrobot.ca
// To get parts or more robots see the Q&A section of the codemyrobot.ca site
//#include <NewPing.h>
// Pin defines for motor - outputs
#define MPIN1B 5 // motor 1 pin B
#define MPIN1A 6 // motor 1 pin A
#define MPIN2A 9 // motor 2 pin A
#define MPIN2B 10 // motor 2 pin B
// Ultra pin definitions
//#define TRIGGER_PIN A2 // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN A3 // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
#define REDPIN 1 // for your lights
#define GREENPIN 3
#define BLUEPIN 4
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Variables
int rSpeed = 195; // robot's max speed (used in Move() calculations)
//int TS1 = 75; // turn speed 1
//int FS = 75; // forward speed:
// move function - we pass a speed for each wheel m1,m2 - as a percentage 0-100
void Move(int m1, int m2) {

 if (m1 < 0) { // for reverse - not used
 analogWrite(MPIN1A, rSpeed * abs(m1) / 100);
 analogWrite(MPIN1B, 0);
 }
 else
 { // normal operation
 analogWrite(MPIN1A, 0);
 analogWrite(MPIN1B, rSpeed * m1 / 100);
 }
 if (m2 < 0) { // for reverse - not used
 analogWrite(MPIN2A, rSpeed * abs(m2) / 100);
 analogWrite(MPIN2B, 0);
 }
 else
 { // normal operation
 analogWrite(MPIN2A, 0);
 analogWrite(MPIN2B, rSpeed * m2 / 100);
 }
}
void Stop( int delayms){
 RGBled(REDPIN,GREENPIN, BLUEPIN,1, 0, 0); //RED
 Move(0,0);
 delay(delayms);

}
void Forward(int delayms){
 RGBled(REDPIN,GREENPIN, BLUEPIN,0, 1, 0); //GREEN
 Move(75,60);
 delay(delayms);
 Move(0,0);
}
void Reverse(int delayms){
 RGBled(REDPIN,GREENPIN, BLUEPIN,0, 0, 1); //BLUE
 Move(-75,-60);
 delay(delayms);
 Move(0,0);
 }
 void TurnRight(int delayms){
 RGBled(REDPIN,GREENPIN, BLUEPIN,1, 1, 0); //YELLOW
 Move(-75,75);
 delay(delayms);
 Move(0,0);
 }
 void TurnLeft(int delayms){
 RGBled(REDPIN,GREENPIN, BLUEPIN,0, 1, 1); //CYAN
 Move(75,-75);
 delay(delayms);
 Move(0,0);
 }
void RGBled(int redPin, int greenPin, int bluePin, int redValue, int greenValue, int blueValue){
 // pinMode(redPin,OUTPUT);
 pinMode(greenPin,OUTPUT);
 pinMode(bluePin,OUTPUT);
 //digitalWrite(redPin, redValue);
 digitalWrite(greenPin, greenValue);
 digitalWrite(bluePin, blueValue);
}
// Setup - runs once
void setup() {
 Serial.begin(115200); // serial for serial port
 pinMode(MPIN1B,OUTPUT); // set motor pin as output
 pinMode(MPIN1A,OUTPUT); // set motor pin as output
 pinMode(MPIN2A,OUTPUT); // set motor pin as output
 pinMode(MPIN2B,OUTPUT); // set motor pin as output
 Stop(2000);

}
// main loop - runs infinetly
void loop() {
 //Serial.print("Ping: ");
 //Serial.print(sonar.ping_cm()); //
 //Serial.println("cm");

 //Forward(300);
 //Stop(150);
 //Reverse(250);
 //TurnLeft(150); //90 degree turn to the left 
 //TurnLeft(150); //90 degree turn to the left 
 //TurnLeft(150); //90 degree turn to the left 
 //TurnLeft(150); //90 degree turn to the left 
 //Stop(1000);

 

 for(int i = 0; i<4; i++){
 Forward(1000);
 //Forward(150);
 //Forward(150);
 Stop(1000);
 Reverse(1000);

 Stop(1000);
 TurnRight(200); //90 degree turn to the left 
 Stop(1000);
 }
 TurnLeft(4*150); //90 degree turn to the left 
 Stop(10000);
}
//Move(75,0);delay(500); // back to the right 90deg
//Move(0,75);delay(500); // back to the left 90deg
//Move(-75,0);delay(500); // fwd to the right 90deg
//Move(0,-75);delay(500); // fwd to the left 90deg
/*
 if(sonar.ping_cm()<= 1){
 Move(0,0);delay(250); // stop
 Move(0,75);delay(600); Move(0,0);delay(250); // back to the left 90deg
 Move(-75,-75);delay(750); Move(0,0);delay(250); // fwd for 250 secs
 Move(75,0);delay(500); Move(0,0);delay(250); // back to the right 90deg
 Move(-75,-75);delay(1000); Move(0,0);delay(250); // fwd for 500 secs
 Move(75,0);delay(600); Move(0,0);delay(250); // back to the right
 Move(-75,-75);delay(700); Move(0,0);delay(250); // fwd for 250 secs
 Move(0,75);delay(750); Move(0,0);delay(250); // back to the left 90deg
 Move(-75,-75);delay(300); Move(0,0);delay(250); // fwd for 500 secs
 Move(0,0);delay(10000);
 }
 Move(-75,-75);
*/
