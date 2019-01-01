// Simple sketch to read the pulse width of a PWM signal
// Useful for reading PWM valuss from a R/C reciever
// to create actions that are not typically handled
// with a servo, such as controlling LED lighting.

int pinChan01 = 2;  // Check what pin to use
int pinChan02 = 3;  // Check what pin to use
int pinChan03 = 4;  // Check what pin to use
int pinChan04 = 5;  // Check what pin to use
int duration01; // Duration of the pulse on CH01
int duration02; // Duration of the pulse on CH02
int duration03; // Duration of the pulse on CH03
int duration04; // Duration of the pulse on CH04

// setup serial and input, output pins
void setup()
{
 
  Serial.begin(9600);
  pinMode(pinChan01, INPUT); // PWM input pin
  pinMode(pinChan02, INPUT); // PWM input pin
  pinMode(pinChan03, INPUT); // PWM input pin
  pinMode(pinChan04, INPUT); // PWM input pin

}

 

void loop()
{

  duration01 = pulseIn(pinChan01, HIGH);
  Serial.print("PWM channel 01 = ");
  Serial.println(duration01);
  duration02 = pulseIn(pinChan02, HIGH);
  Serial.print("PWM channel 02 = ");
  Serial.println(duration02);
  duration03 = pulseIn(pinChan03, HIGH);
  Serial.print("PWM channel 03 = ");
  Serial.println(duration03);
  duration04 = pulseIn(pinChan01, HIGH);
  Serial.print("PWM channel 04 = ");
  Serial.println(duration04);
  
  delay(100); //delay so you can read the scrolling output
}
