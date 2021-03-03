// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "DHTesp.h"
//DHT sensor setup
DHTesp dht;
int dhtPin = 19;

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String get_temp_humid(){
  flag:TempAndHumidity nVals = dht.getTempAndHumidity();
  if (dht.getStatus() !=0){ goto flag;}
  return String(nVals.temperature)+","+String(nVals.humidity);
}

void setup(){
  // Serial port for debugging purposes
  dht.setup(dhtPin,DHTesp::DHT11);
  Serial.begin(115200);//115200   //9600
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.on("/dat", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", get_temp_humid().c_str());
  });
  // Start server
  server.begin();
}
 
void loop(){
  
}
