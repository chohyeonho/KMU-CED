#define PIN_LED 7
unsigned int i,toggle;
void setup()
{
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
  while(!Serial)
  {
    ;
  }
  toggle=1;
  digitalWrite(PIN_LED,toggle);
  delay(1000);
}
void loop()
{
  for(i=0;i<=10;i++)
  {
    toggle=toggle_state(toggle);
    digitalWrite(PIN_LED,toggle);
    delay(100);
  }
  while(1){}
}
int toggle_state(int toggle)
{
  return 1-toggle;
}
