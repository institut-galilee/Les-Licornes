/*
    DECHAUMET Léo
    BOUZIANE Hajar
    ZHANG Bingqin

    Date : 18/11/2019

   Le programme récupère une chaîne de caractère saisit par l'utilsateur 
   et utilise cette valeur pour définir la fréquence du passive buzzer.
 */

const int led = 5;
//tableau qui stoke la chaîne de caractère
char tab [100];

void setup() 
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);

}

void loop()
{
    int i =0;

    while(Serial.available() >0)
    {
        byte val = Serial.read(); //On récupère le caractère que l'on a envoyé à notre carte
        tab[i]=(char)val;         //On stocke le caractère dans un tableau
        i++; 
    }
    tab[i] = '\0';                //Fin de chaîne de caractère
    Serial.println(atoi(tab));    //On affiche le caractère sur le serial monitor
    tone(led, atoi(tab), 500);    //On déclenche le passive buzzer.
}
