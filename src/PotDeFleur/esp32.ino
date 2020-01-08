#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Poussinet";
const char* password = "zvmg7265";
const char* URLDB = "https://careplant-bad6a.firebaseio.com/.json"

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

void SendGetRequest(){
 if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    HTTPClient http;

    http.begin("https://careplant-bad6a.firebaseio.com/.json"); //Specify the URL
    //(A test json server: https://jsonplaceholder.typicode.com/guide.html)

    int httpCode = http.GET();     //Make the request

    if (httpCode > 0) { //Check for the returning code

        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);

        DynamicJsonDocument doc(1024);
        deserializeJson(doc, payload);
        JsonObject obj = doc.as<JsonObject>();
        int userId = obj["message"];
        Serial.println(userId);

      }

    else {
      Serial.println("Error on HTTP request Code:"+httpCode);
    }

    http.end(); //Free the resources
  }
}

/*void SendPatchRequest( char * param, char * value)
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    http.begin(URLDB); //Specify destination for HTTP request
    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument  doc(200);
    doc[param] = value;

    String output;
    serializeJsonPretty(doc, output);// You can also use serializeJson(doc, Serial);
    Serial.println(output);

    int httpCode = http.PATCH(output); //Send the actual POST request
    if(httpCode>0){
      String response = http.getString(); //Get the response to the request
      Serial.println(httpCode);   //Print return code
      Serial.println(response);           //Print request answer
    }else{
      Serial.print("Error on sending PATCH: ");
      Serial.println(httpCode);
    }
  }
}*/

void SendPatchRequest( char * body)
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    http.begin(URLDB); //Specify destination for HTTP request
    http.addHeader("Content-Type", "application/json");


    Serial.println(body);

    int httpCode = http.PATCH(body); //Send the actual POST request
    if(httpCode>0){
      String response = http.getString(); //Get the response to the request
      Serial.println(httpCode);   //Print return code
      Serial.println(response);           //Print request answer
    }else{
      Serial.print("Error on sending PATCH: ");
      Serial.println(httpCode);
    }
  }
}

void setup(){
  Serial.begin(115200);
  scanNetworks();
  connectToNetwork();

}

void loop(){
  SendGetRequest();
   if (Serial.available() > 0) {
     char bfr[501];
     memset(bfr,0, 501);
     Serial.readBytesUntil( '\n',bfr,500);
     SendPatchRequest(bfr);
  }
}
