#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "kerkorn";
const char* password =  "0838393616";
const char* mqttServer = "192.168.1.200";
const int mqttPort = 1883;
const char* mqttUser = "roomkorn";
const char* mqttPassword = "korn1234";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) 
  {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) 
    {
      Serial.println("connected");
    } 
    else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  client.publish("DHT", "Hello from ESP32");
  delay(1000);
}
