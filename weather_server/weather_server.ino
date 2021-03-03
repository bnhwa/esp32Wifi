// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "DHTesp.h"
//DHT sensor setup
DHTesp dht;
int dhtPin = 19;
int lightLevel =4095;
//light sensor
// When using wifi, use pins 32 and above
#define PIN_ANALOG_IN 34
#define LIGHT_MIN 372
#define LIGHT_MAX 2048


// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String get_temp_humid(){
  //temp,humidity,lightlevel
  //
  int adcVal = analogRead(PIN_ANALOG_IN); //read adc
  Serial.println(adcVal);
//  float pwmVal = map(constrain(adcVal, LIGHT_MIN, LIGHT_MAX), LIGHT_MIN, LIGHT_MAX, 0, 4095);
  flag:TempAndHumidity nVals = dht.getTempAndHumidity();
  if (dht.getStatus() !=0){ goto flag;}
  return String(nVals.temperature)+","+String(nVals.humidity)+","+String(lightLevel);
}

void setup(){
  // Serial port for debugging purposes
  dht.setup(dhtPin,DHTesp::DHT11);
  pinMode(PIN_ANALOG_IN, INPUT);
  Serial.begin(9600);//115200   //9600
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
  delay(500);
  lightLevel = analogRead(PIN_ANALOG_IN);
  Serial.println(analogRead(PIN_ANALOG_IN));
  
}
