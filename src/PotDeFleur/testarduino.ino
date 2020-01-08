
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>


// Set these to run example.
#define FIREBASE_HOST "https://careplant-bad6a.firebaseio.com"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

#define BD_TEMP "arduino/capteurs/temperature"
#define BD_NIVEAU "arduino/capteurs/niveau"
#define BD_HUM "arduino/capteurs/humidite"
#define BD_TIMESTAMP "arduino/timestamp"

#define BD_HUM_PLUS "info/humPlus"
#define BD_HUM_MOINS "info/humMoins"

int temp = 0;
int hum = 20;
int niveau = 3;
int timestamp = 5;


void setup() {
 Serial.begin(115200);
 Serial.println("Interfacfing arduino with nodemcu");
 sw.begin(115200);

}

//liberer mem alloué
/*char * paramToJson(char * param, char * values, int taille){
    retour = malloc(sizeof(int) * 100);
    strcat(retour, "{");
    strcat(retour, param);
    strcat(retour, ":");
    strcat(retour, values);
    strcat(retour, "}");

}*/

void updateVal(char * param, char * value){
    DynamicJsonDocument  doc(200);
    doc[param] = value;

    String output;
    serializeJsonPretty(doc, output);// You can also use serializeJson(doc, Serial);
    Serial.println(output);
    sx.println(output);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.println(x);
}

void loop() {

    updateVal(BD_TEMP, temp);
    updateVal(BD_HUM, hum);
    updateVal(BD_NIVEAU, niveau);
    updateVal(BD_TIMESTAMP, timestamp);
    delay(5000)
}
