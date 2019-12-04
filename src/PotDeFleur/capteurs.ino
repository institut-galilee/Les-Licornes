const int Humidite = A0;
const int Niveau = A3;
const int Thermistor = A5;

const double a = 0.0011129148;
const double b = 0.000234125;
const double c = 0.0000000876741;

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    int H = analogRead(Humidite);
    int N = analogRead(Niveau);
    int bit_temperature = analogRead(Thermistor);
    double R = log(1000.0* (1024.0 / bit_temperature-1));
    double temperature = 1/(a + b*R + c*R*R*R);
    temperature = temperature - 273.15;     
   
   Serial.print("Humidite = ");
  Serial.println(H);
  Serial.print("Niveau = ");
  Serial.println(N);
  Serial.print(temperature);
  Serial.println(" degre");
  delay(1000);

}
//Plus c'est humide plus la valeur descend.
//faire un calibrage
//300 dans l'eau
// dans la terre sèche
