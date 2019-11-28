#include "FirebaseESP8266.h"
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "dummy-cd6d8.firebaseio.com"
#define FIREBASE_AUTH "RV3DRq90y7ysfFLoWIB5Rs4pacO6cK0pQZIYmWqU"
#define WIFI_SSID "pub"
#define WIFI_PASSWORD "11110000"
FirebaseData firebaseData;
char *myStrings[2][3] = {{" 0B 20 02 0A", " 0C 20 02 0C", " 0F 20 02 0C"},{" 04 20 02 0C", " 0B 2A 02 0C", " 0B 20 02 0C"}};

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);



void setup()
{

    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true); 
    for(int i = 1 ; i<=4;i++)
    {
        String j = String(i);
        String path_ID = "/SchoolData/RegisteredPersons/Person-"+j+"/ID";
        Firebase.getString(firebaseData,path_ID);
        int ID = firebaseData.stringData().toInt();
        Serial.println(ID+123);
        
        String path_Name = "/SchoolData/RegisteredPersons/Person-"+j+"/Name";
        Firebase.getString(firebaseData,path_Name); 
        Serial.println(firebaseData.stringData());
        
        String path_RFID = "/SchoolData/RegisteredPersons/Person-"+j+"/RFID";
        Firebase.getString(firebaseData,path_RFID);  
        Serial.println(firebaseData.stringData());
        Serial.println(".......");  
    }
        


}
void loop() 
  {
            
            
}
