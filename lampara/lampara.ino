#include <Servo.h> 

int IRpin = 1;                                    // analog pin for reading the IR sensor
Servo myservo;

int potpin = 5;
int val;

void setup() {
  Serial.begin(9600);     


  // start the serial port
  myservo.attach(9);
}

void loop() {
  //float volts = analogRead(IRpin)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
  //float distance = 65*pow(volts, -1.10);          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk
  float volts = analogRead(IRpin)*0.00322265624;
  float distance = 12.21*pow(volts, -1.15); 
  if (distance > 80) {
    distance = 80;
  }
  
  //val = analogRead(potpin);
  val = map(distance,0,80, 0, 179);
  
  
  Serial.println(val);
  
  myservo.write(val);
  Serial.println(distance);      

  // print the distance
  delay(350);                                    // arbitary wait time.
}
