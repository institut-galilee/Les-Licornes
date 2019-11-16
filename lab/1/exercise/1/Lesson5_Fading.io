/*
    ZHANG Bingqin
    DECHAUMET Léo
    BOUZIANE Hajar

    Date : 13/11/2019
    Programme qui permet de changer l'intensité
    de la LED.
*/

//Déclaration d'une constante initialisé au pin 5.
const int led = 5;
//Déclaration d'un variable
int val = 0;

void setup() 
{
    // initialize the PWM pin as output.
    pinMode(led, OUTPUT);
}

void loop() 
{
    /* On utilise la sortie "analogique" PWD pour gérer l'intensité de la led
       en utilisant la variable val.*/
    analogWrite(led, val);
    val = (val + 10) % 255; //val est compris entre en 0 et 255
    delay(100);             //on attend 100ms avant de changer d'intensité
}
