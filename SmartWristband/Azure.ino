int pwm_pin = 4;
const int LED_PIN = 15; //Pin to turn on/of LED a command from IoT Hub
unsigned long lastMillis = 0;

void connectToIoTHub(); // <- predefine connectToIoTHub() for setup()
void onMessageCallback(const MQTT::Publish& msg);

void AzureConnectClient(){
    e1 = WiFi.onStationModeGotIP(onSTAGotIP);// As soon WiFi is connected, start the Client
    e2 = WiFi.onStationModeDisconnected(onSTADisconnected);
    client.onEvent(onClientEvent);
    client.onCloudCommand("ActivateRelay", onActivateRelayCommand);
    currentTime = now();
}

void onSTAGotIP(WiFiEventStationModeGotIP ipInfo) {
    Serial.printf("Got IP: %s\r\n", ipInfo.ip.toString().c_str());

    //do connect upon WiFi connected
    connectToIoTHub();
}

void onSTADisconnected(WiFiEventStationModeDisconnected event_info) {
    Serial.printf("Disconnected from SSID: %s\n", event_info.ssid.c_str());
    Serial.printf("Reason: %d\n", event_info.reason);
}

void onClientEvent(const AzureIoTHubMQTTClient::AzureIoTHubMQTTClientEvent event) {
    if (event == AzureIoTHubMQTTClient::AzureIoTHubMQTTClientEventConnected) {

        Serial.println("Connected to Azure IoT Hub");

        //Add the callback to process cloud-to-device message/command
        client.onMessage(onMessageCallback);
    }
}

void onActivateRelayCommand(String cmdName, JsonVariant jsonValue) {

    //Parse cloud-to-device message JSON. In this example, I send the command message with following format:
    //{"Name":"ActivateRelay","Parameters":{"Activated":0}}

    JsonObject& jsonObject = jsonValue.as<JsonObject>();
    if (jsonObject.containsKey("Parameters")) {
        auto params = jsonValue["Parameters"];
        auto isAct = (params["Activated"]);
        if (isAct) {
            Serial.println("Activated true");
        }
        else {
            Serial.println("Activated false");
        }
    }
}

void onMessageCallback(const MQTT::Publish& msg) {

    //Handle Cloud to Device message by yourself.

    if (msg.payload_len() == 0) {
        return;
    }else{
          if(msg.payload_string().startsWith("b:")){
              String asd = msg.payload_string();
              asd.remove(0,2);
              bakiye = asd;
              dispBalance();
          } else if (msg.payload_string().startsWith("d:")){
            String asd = msg.payload_string();
              asd.remove(0,2);
              gelenDersVerisi = asd;
          }
    }
    Serial.println(msg.payload_string());
}

void connectToIoTHub() {

    Serial.print("\nBeginning Azure IoT Hub Client... ");
    if (client.begin()) {
        Serial.println("OK");
    } else {
        Serial.println("Could not connect to MQTT");
    }
}


void sendMessage(char* islemTip, char* aciklama){
  if (client.connected()) {
        time_t currentTime = now();
        AzureIoTHubMQTTClient::KeyValueMap keyVal = {{"id", DEVICE_ID}, {"i", islemTip}, {"a", aciklama}, {"t", currentTime}};
        client.sendEventWithKeyVal(keyVal);
        delay(10);
    } else {
     Serial.println("cant connected to the azure");
    }
}



