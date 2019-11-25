# Raport

## Part 1

Dans cette première partie du TP, ils nous a fallu manipuler le BME280, un capteur de :
- température,
- humidité,
- pression athmosphérique

de l'environnement.

Nous l'avons donc connecté à l'Arduino via I2C qui est un protocole de communication qui permet de connecter
plusieurs composants (s'ils sont compatible avec l'I2C).Un fois connecté, nous avons téléversé le code quivant vers l'Arduino:

### Code
```C
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    Serial.println(F("BME280 test"));
    unsigned status;
    
    // default settings
    // (you can also pass in a Wire library object like &Wire2)

    status = bme.begin();  
    if (!status) {

        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");

        while (1);
    }
    Serial.println("-- Default Test --");
    delayTime = 1000;
    Serial.println();
}

void loop() { 
    printValues();
    delay(delayTime);
}

void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");
    
    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");
    
    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");
    Serial.println();
}
```

### Fritzing sketch
<p align = "center">
<img src = "https://user-images.githubusercontent.com/56651530/69525244-fd10b480-0f67-11ea-874d-a44a71414103.png" width = 700px />
</p>

### Photo
<p align = "center">
<img src = "https://user-images.githubusercontent.com/56651530/69525250-000ba500-0f68-11ea-974b-92992454f6ae.jpg" width = 500px />
