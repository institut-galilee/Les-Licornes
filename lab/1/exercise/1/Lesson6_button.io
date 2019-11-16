/*
    BOUZIANE HAJAR
    DECHAUMET Léo
    ZHANG Bingqin

    Date : 16/11/2019

    Programme qui allume la built-in LED quand on appuye sur le boutton.
*/

const int pin = 2;
const int led = 13;

void setup() 
{
    //on ouvre le serial port pour lire et ecrire
    Serial.begin(9600);
    pinMode(pin, INPUT);
    //on signal à l'arduino que la connexion 13 doit pourvoir envoyer du courant
    pinMode(led, OUTPUT);
}

void loop() 
{
    //on lit la valeur renvoyer par le pin 2 quand on appuiyer ou non sur le boutton
    int val = digitalRead(pin);
    //si val vaut 1 (on a appuyer sur le bouton) , on allume la built-in LED, sinon on l'éteind
    if(val == HIGH)
    {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
    Serial.print(val);
}
