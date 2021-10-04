#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <AzureIoTHubMQTTClient.h>

#define IOTHUB_HOSTNAME         "IotDataIn.azure-devices.net"
#define DEVICE_ID               "7580f915"
#define DEVICE_KEY              "aSyu58I0eRbFUT6mvJhasUpgkDf/muZBjkLrUB+7oQw=" //Primary key of the device

WiFiClientSecure tlsClient;
AzureIoTHubMQTTClient client(tlsClient, IOTHUB_HOSTNAME, DEVICE_ID, DEVICE_KEY);
WiFiEventHandler  e1, e2;
time_t currentTime;

static const int  countButton     = 5;
static const int  lockButton      = 12;
boolean azureconnected  = false;
static String device_id = "7580f915";
String gelenDersVerisi = "---";
void setup() {

    Serial.begin(115200);
    while(!Serial) {
        yield();
    }
    pinSetup();
    startScreen();
    delay(2000); // is that neccesarry ?
    Serial.setDebugOutput(true);
    Wifi();
    AzureConnectClient();
}
int page = 0;
String bakiye = "----";
int sleepTime1 = 0;
int sleepTime2 = 0;
boolean inSleep = false;

void loop() {

    sleepTime1 = millis() / 1000;
    if(sleepTime1 - sleepTime2 > 3 ){
      inSleep = true;
    }
    
    //MUST CALL THIS in loop()
    if(client.connected() && !inSleep){
     client.run();
    }
    if (digitalRead(countButton) == HIGH)
      {
        doButtonWork();
        page++;
        delay(300);
        Serial.println(page);
      }
    if ((page % 3) == 0)
      {
        mainScreen();
        Serial.print("Ana ekran\n");
      }
    else if ((page % 3) == 1)
      {
        drawQrCode();
        Serial.print("QR\n");
      }
    else if ((page % 3) == 2)
      {
        dispBalance();
        sendMessage("bakiye","bakiye ogrenme istegi");
        Serial.print("Kalan\n");
      }
    if (digitalRead(lockButton) == HIGH)
      {
        doButtonWork();
        sendMessage("dolap","kapi acma aciklama yazisi");
        Serial.print("Kapiyi ac\n");
      }
 
}

void doButtonWork(){
  sleepTime2 = millis()/1000;
  inSleep = false;
  if(!client.connected()){
    AzureConnectClient();
  }
}





