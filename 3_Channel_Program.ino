#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  110 // this is the 'minimum' pulse length count (out of 4096. This is the low end of the ESC range in the jibber-jabber that the PWM Wing speaks.
#define SERVOMAX  650 // this is the 'maximum' pulse length count (out of 4096. This is the low end of the ESC range in the jibber-jabber that the PWM Wing speaks.

  int leftTrack = 0; //The servo channel on the WING output to the Left Track ESC
  int rightTrack = 1; //The servo channel on the WING output to the Right Track ESC
  int transMotor = 2; //The servo channel on the wing output to the turret transverse motor
  
  int pinChan01 = 5;  // Check what pin to use
  int pinChan02 = 6;  // Check what pin to use
  int pinChan03 = 9;  // Check what pin to use

  int duration01; // Duration of the pulse on CH01
  int duration02; // Duration of the pulse on CH02
  int duration03; // Duration of the pulse on CH03



void setup() {
  Serial.begin(9600); //I haven't decided what to print yet...
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  pinMode(pinChan01, INPUT); // PWM input pin
  pinMode(pinChan02, INPUT); // PWM input pin
  pinMode(pinChan03, INPUT); // PWM input pin  
  delay(10);
}

void loop() {

  int servoPWM = 1500;
  

  //Left Track ESC
  duration01 = pulseIn(pinChan01, HIGH, 25000);
  servoPWM = pwmConverter (duration01);
  pwm.setPWM(leftTrack, 0, servoPWM); 
  Serial.print ("Left Track ESC = ");
  Serial.print (servoPWM);

  //Right Track ESC
  duration02 = pulseIn(pinChan02, HIGH, 25000);
  servoPWM = pwmConverter (duration02);
  pwm.setPWM(rightTrack, 0, servoPWM); 
  Serial.print ("Right Track ESC = ");
  Serial.print (servoPWM);
  
  //Transverse motor ESC
  duration03 = pulseIn(pinChan03, HIGH, 25000);  
  servoPWM = pwmConverter (duration03);
  pwm.setPWM(transMotor, 0, servoPWM);
  Serial.print ("Transverse ESC = ");
  Serial.println (servoPWM);
}

int pwmConverter(int x){
  int result;
  result =  map(x, 980, 2020, 110, 650);
  return result;

}
