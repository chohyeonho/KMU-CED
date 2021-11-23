#include <Servo.h>
#define PIN_SERVO 10
#define INTERVAL 25 // sampling interval (unit: ms)
unsigned long last_sampling_time; // unit: ms
Servo myservo;

void setup() {
  myservo.attach(PIN_SERVO); 
}

void loop() {
  if(millis() < last_sampling_time + INTERVAL) return;
  if(millis()/50%360<180)
  {
    myservo.write(millis()/50%180);
  }
  else
  {
    myservo.write(180-millis()/50%180);
  }
  last_sampling_time += INTERVAL;
}
