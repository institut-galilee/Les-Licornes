/*
    DECHAUMET Léo
    ZHANG Bingqin
    BOUZIANE Hajar

    Date : 13/11/2019

    Programme allume la LED et émet les 7 couleurs
 */
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int rouge = 9;
const int vert = 10;
const int bleu = 11;

int val = 50;
int val2 = 128;
int val3 = 255;
 
// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize the digital pin as an output.
  pinMode(rouge, OUTPUT);     
  pinMode(vert, OUTPUT);     
  pinMode(bleu, OUTPUT);     

}
