#include <SPI.h>
#include <LoRa.h>
#define ECHOPIN 7 //TX

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  pinMode(ECHOPIN, INPUT);
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  int distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/58;

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(distance);
  LoRa.print(" en cm");
  LoRa.endPacket();

  counter++;

  delay(5000);
}
