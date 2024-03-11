#include <SoftwareSerial.h>
SoftwareSerial gsm(2, 3);//rx 2 tx 3
void setup() {
gsm.begin(9600);//gsm
Serial.begin(9600);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);
pinMode(10,INPUT_PULLUP);
pinMode(11,INPUT_PULLUP);
gsm.println("AT");
delay(2000);
}

void loop() {
  if(digitalRead(8)==0)
  {
    Serial.println("Calling");
    gsm.println("ATD9446107556;");
    delay(5000);
    }
    else if(digitalRead(9)==0)
    {
      Serial.println("Call disconnecting");
      gsm.println("ATH");
      Serial.println("Call disconnected");
      delay(5000);
      }
      else if(digitalRead(10)==0)
    {
      Serial.println("Call Attending");
      gsm.println("ATA");
      Serial.println("Call connected");
      delay(5000);
      }
      else if(digitalRead(11)==0)
      {
        Serial.println("Message Sending");
      gsm.println("AT+CMGF=1");
      delay(1000);
      gsm.println("AT+CMGS=\"9446107556\"");
      delay(1000);
      gsm.println("Hello from GSM");
      gsm.write(26);
      Serial.println("Message connected");
      delay(5000);
        }
}
