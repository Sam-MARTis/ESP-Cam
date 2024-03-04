#include<esp32cam.h>
#include<WebServer.h>
#include<WiFi.h>

#define ssid "Esp32SamAP"
#define pass "EspCamWorks"

Webserver server(80);

void handleCapture(){
  auto img = esp32cam::capture();
  if(img == nullptr){
    server.send(500,"", "");
    return;
  }
  server.setContentLength(img->size());
  server.send(200, "image/jpeg");
  WiFiClient client = server.client();
  img->writeTo(client);
  
}



void setup() {
  // put your setup code here, to run once:
  auto res = esp32Cam::Resolution::find(1024, 768);
  esp32cam::Config cfg;
  cfg.setPins(esp32cam::pins::AiThinker);
  cfg.setResolution(res);
  cfg.setJpeg(80);
  esp32cam::Camera.begin(cfg);
  WiFi.softAP(ssid, pass);
  server.on("/capture.jpg", handleCapture);
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

}
