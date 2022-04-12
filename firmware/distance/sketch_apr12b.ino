#define ECHOPIN 7 //TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int distance = pulseIn(ECHOPIN,HIGH);
  distance = distance/58;
  Serial.print(distance);
  Serial.println("  cm");
  delay(50);
}
