/*
  BOUZIANE Hajar
  DECHAUMET Léo
  ZHANG Bingqin

  Date: 16/11/2019
*/

const int pin = A0;
const int led = 13;

void setup() 
{
    //on ouvre le serial port pour lire et ecrire
    Serial.begin(9600);
}

void loop() 
{
    int sensorValue = analogRead(pin);
    Serial.print(sensorValue);
    digitalWrite(led,HIGH);
    delay(sensorValue);
    digitalWrite(led, LOW);
}
