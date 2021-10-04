const char *AP_SSID = "PeakUp-Guest";
const char *AP_PASS = "hosgeldiniz";

void Wifi(){
//    WiFi.mode(WIFI_STA);

  Serial.print("Connecting to WiFi...");
    //Begin WiFi joining with provided Access Point name and password
    WiFi.begin(AP_SSID, AP_PASS);

    //Handle WiFi events
    e1 = WiFi.onStationModeGotIP(onSTAGotIP);// As soon WiFi is connected, start the Client
    e2 = WiFi.onStationModeDisconnected(onSTADisconnected);

    //Handle client events
    client.onEvent(onClientEvent);

    //Add command to handle and its handler
    //Command format is assumed like this: {"Name":"[COMMAND_NAME]","Parameters":[PARAMETERS_JSON_ARRAY]}
    client.onCloudCommand("ActivateRelay", onActivateRelayCommand);
}

