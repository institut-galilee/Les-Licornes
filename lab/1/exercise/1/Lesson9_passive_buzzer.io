/*
    ZHANG Bingqin
    DECHAUMET Léo
    BOUZIANE Hajar

    Date : 16/11/2019
*/

const int led = 5;
 
// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  tone(led, 200, 2000);   
}

void loop() {

}
