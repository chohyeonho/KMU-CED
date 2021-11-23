#include <Servo.h>
#define PIN_SERVO 10
// Arduino pin assignment
#define PIN_IR A0
#define PIN_LED 9
Servo myservo;
int a, b; // unit: mm

void setup() {
  myservo.attach(PIN_SERVO); 
// initialize GPIO pins
  pinMode(PIN_LED,OUTPUT);
  digitalWrite(PIN_LED, 1);
  
// initialize serial port
  Serial.begin(57600);

  a = 75; //70;
  b = 240; //300;
  myservo.write(90);
  while(1)
  {
    
  }
}

float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}

void loop() {
  float raw_dist = ir_distance();
  float dist_cali = 100 + 300.0 / (b - a) * (raw_dist - a);
  Serial.print("min:0,max:500,dist:");
  Serial.print(raw_dist);
  Serial.print(",dist_cali:");
  Serial.println(dist_cali);
  if(raw_dist > 156 && raw_dist <224) digitalWrite(PIN_LED, 0);
  else digitalWrite(PIN_LED, 255);
  if(dist_cali>285)
  {
    myservo.write(70);
  }
  else
  {
    myservo.write(90);
  }
  delay(20);
}
