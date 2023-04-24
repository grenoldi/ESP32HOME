#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = "SILVIA";
const char* pass = "sgg311220";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass); // Substitua SSID e password pelas credenciais da sua rede Wi-Fi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando-se à rede Wi-Fi...");
  }

  Serial.println("Conectado à rede Wi-Fi!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/resource", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "HELLO WORLD FROM BOBS ESP32");
  });

  server.on("/resource", HTTP_PUT, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Recebido PUT");
  });

  server.on("/resource", HTTP_DELETE, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Recebido DELETE");
  });

  server.begin();
}

void loop() {}