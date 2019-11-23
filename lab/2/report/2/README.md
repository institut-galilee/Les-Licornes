# Practic 2

## Passive buzzer frequency

Dans cette seconde partie de Tp, il nous a été demandé d'ajuster la fréquence d'un buzzer selon la valeur saisie par l'utilisation sur le *serial communication software*

## Code
```C
const int pin = A0;
void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() 
{
    // put your main code here, to run repeatedly:
    int val = analogRead(pin);
    Serial.println(val);
    delay (400);
}
```

## LDR

Il nous a été demandé de réaliser un graphe selon les valeurs du LDR reçues par l'ordinateur grâce au sérial.
Des mofications ont été apportées au fichier plot.py afin que le fichier puisse s'exécuter sur les ordianateurs de la fac. 
- Le port *MOC6* à été remplacé par */dev/ttyACM0* 
- Le print de la boucle for car il n'était pas compatible avec la version python3

## Code 
```C
const int pin = A0;
void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    int val = analogRead(pin);
    Serial.println(val);
    delay(400);
}

```
## Graph 

![CourbeLuminosite](https://user-images.githubusercontent.com/56651530/69481358-f7ed2180-0e10-11ea-93b8-9fcd3981c36c.png)

## Fritzing sketch

![sketch2](https://user-images.githubusercontent.com/56651530/69481381-2c60dd80-0e11-11ea-9c46-bba92368e14a.png)



