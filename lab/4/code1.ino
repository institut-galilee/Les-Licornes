```C
#include <WiFi.h>

const char* ssid = "Poussinet";
const char* password = "zvmg7265";

void scanNetworks() {
 
  int numberOfNetworks = WiFi.scanNetworks();
 
  Serial.print("Number of networks found: ");
  Serial.println(numberOfNetworks);
 
  for (int i = 0; i < numberOfNetworks; i++) {
 
    Serial.print("Network name: ");
    Serial.println(WiFi.SSID(i));
 
    Serial.print("Signal strength: ");
    Serial.println(WiFi.RSSI(i));
 
    Serial.print("MAC address: ");
    Serial.println(WiFi.BSSIDstr(i));
 
    //Serial.print("Encryption type: ");
    //Serial.print(WiFi.encryptionType(i)); the type is  wifi_auth_mode_t
   
    Serial.println("-----------------------");
 
  }
}

void printWiFiInfo() {
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
 
  WiFi.disconnect(true);
  Serial.println(WiFi.localIP());
}

void connectToNetwork() {
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Establishing connection to WiFi..");
  }
  
  Serial.println("Connected to network");
}


void setup(){
  Serial.begin(115200);
  scanNetworks();
  connectToNetwork();
}

void loop(){  }
```
