char *myStrings[2][3] = {{" 0B 20 02 0A", " 0C 20 02 0C", " 0F 20 02 0C"},{" 04 20 02 0C", " 0B 2A 02 0C", " 0B 20 02 0C"}};
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
void setup() {
   Serial.begin(115200);
   SPI.begin();       // Init SPI bus
   mfrc522.PCD_Init(); // Init MFRC522
   Serial.println("RFID reading UID");
}
void loop() {
if ( mfrc522.PICC_IsNewCardPresent())
    {
      String content= "";byte letter;
        if ( mfrc522.PICC_ReadCardSerial())
        {
           for (byte i = 0; i < mfrc522.uid.size; i++) {
            
                  content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
                  content.concat(String(mfrc522.uid.uidByte[i], HEX));
            }
            content.toUpperCase();
         
            //Serial.println(content);
            mfrc522.PICC_HaltA();
        }
        int count = 1;
        for(int i = 0 ; i<2;i++)
        {
          for(int j = 0;j<3 ; j++)
          {
            String idNum = String(myStrings[i][j]);
            if(idNum == content)
            {
              Serial.println("Found the card");
              //Serial.println(" the card number is :" + content);
            }
            else
            {
              if(count == 6)
              {
                Serial.println("Card not Found");
                
              }
              else
              {
                //Serial.println("Check at the position :"+String(count));
                count++;

              }
            }
          }
        }
        
        
}
}
