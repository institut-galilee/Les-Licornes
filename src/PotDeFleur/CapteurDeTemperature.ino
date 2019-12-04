const int pin = A0;

const double a = 0.0011129148;
const double b = 0.000234125;
const double c = 0.0000000876741;

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    int bit_temperature = analogRead(pin);
    double R = log(10000.0* (1024.0 / bit_temperature-1));
    double temperature = 1/(a + b*R + c*R*R*R);
    temperature = temperature - 273.15;     
    Serial.print(temperature);
    Serial.println(" degre");
    delay(2000);
}
