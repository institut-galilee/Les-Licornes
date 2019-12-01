# Rapport

### Partie 4

Pour cette dernière partie de TP, nous devions manipulé le module MPU6050. Il est composé d'un gyroscope à 3 axes et d'un accéléromètre à 3 axes qui communiquent entre eux via l'I2C.
Nous avons donc, dans un premier temps, connecté l'Arduino au MPU6050 de cette façon :

### Shéma fritzing
<p align="left">
  <img src="https://user-images.githubusercontent.com/56651530/69917545-8db72b00-1467-11ea-823b-1c12c36e2997.png" width=500px alt="sketch Fritzing"/>
  </p>
  
### Photo
<p align="left">
  <img src="https://user-images.githubusercontent.com/56651530/69917547-8ee85800-1467-11ea-9cd0-ac086e0759da.jpg" width=400px alt="sketch Fritzing"/>
  </p>

Une fois connecté, nous avons tenté de téléversé le code suivant :

### Code 
```C
// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {
  /* Take a new reading */
  mpu.read();

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print(a.acceleration.z);
  Serial.print(", ");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print(g.gyro.z);
  Serial.println("");

  delay(10);
}
```

Mais une erreur survenue à la compilation ne nous à pas permis de terminer notre exercice.
