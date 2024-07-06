#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include <DHT.h>

#define LED1 2
#define LED2 5
#define DHTPIN 4     // Pin de datos del sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT (DHT11 en este caso)

AsyncWebServer server(80);
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Red1";          // SSID de WiFi
const char* password = "123456789";  // Contraseña de WiFi

void recvMsg(uint8_t *data, size_t len){
  WebSerial.println("Received Data...");
  String d = "";
  for(int i=0; i < len; i++){
    d += char(data[i]);
  }
  WebSerial.println(d);
  if (d == "ON1"){
    digitalWrite(LED1, HIGH);
  } else if (d == "OFF1"){
    digitalWrite(LED1, LOW);
  } else if (d == "ON2"){
    digitalWrite(LED2, HIGH);
  } else if (d == "OFF2"){
    digitalWrite(LED2, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  dht.begin();

  // Conectarse a la misma red y acceder a web serial mediante: "<IP Address>/webserial" en el navegador
  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  server.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  WebSerial.print("Temperatura: ");
  WebSerial.print(temperature);
  WebSerial.println(" °C");
  WebSerial.print("Humedad: ");
  WebSerial.print(humidity);
  WebSerial.println(" %");

  delay(2000);
}
