#include "OneWire.h"
#include "DallasTemperature.h"
#include "EspMQTTClient.h"

EspMQTTClient client(
  "Wokwi-GUEST",         // SSID WiFi
  "",                    // PAssword WiFi
  "test.mosquitto.org",  // MQTT Broker
  "mqtt-wokwi",          // Client
  1883                   // MQTT port
);


// GPIO where the DS18B20 is connected to
OneWire oneWire(4);         
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
// Temperature value
float temp;


void setup() {
  // Start o DS18B20 sensor
  Serial.begin(115200);
  delay(2);
  sensors.begin();
  delay(20);

  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "Offline");
}

void lerEnviarDados() {
  
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  Serial.println("temp: " + String(temp) + "°C");
  Serial.println("---");
  client.publish("topicowokwi/temp", String(temp) + "°C");

}


void onConnectionEstablished()
{
  // Subscribe no "topicowokwi/msgRecebida/#" e mostra a mensagem recebida na Serial
  client.subscribe("topicowokwi/msgRecebida/#", [](const String & topic, const String & payload) {
    Serial.println("Mensagem recebida no topic: " + topic + ", payload: " + payload);
  });


  lerEnviarDados();
}

void loop() {
  client.loop(); // Executa em loop

}
