
//Simple trim-pot adjustable square wave generator
//produces a square wave @ 50% duty-cycle
//used with ATtiny-85, set internal oscillator to 16Mhz, trim-pot on A2 (pin 3)
//min and max periods are in milliseconds, and can be scaled to whatever
//D.Bailey 2/27/20

int minPeriod = 10; //(100Hz)
int maxPeriod = 1000; //(1Hz)

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  int val = analogRead(2);
  val = map(val, 0, 1023, maxPeriod * .5, minPeriod * .5 ); //this is inverted so turning pot CW increases freq.
  digitalWrite(2, HIGH);
  delay(val);
  digitalWrite(2, LOW);
  delay(val);
}
