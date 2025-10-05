#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID       "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME     "Device"
#define BLYNK_AUTH_TOKEN        "YourAuthToken"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define LED 23
#define PB  16

BLYNK_WRITE(V0)
{ int pbBlynk = param.asInt();
  digitalWrite(LED,pbBlynk);
}

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(LED,OUTPUT);
  pinMode(PB,INPUT_PULLUP);
}

bool PB_old, PB_new;
void loop()
{ Blynk.run();
  
  PB_new = digitalRead(PB);

  if(PB_new==0 && PB_old==1)
    Blynk.virtualWrite(V1,"PB Pressed");
  if(PB_new==1 && PB_old==0)
    Blynk.virtualWrite(V1,"PB Idle");

  PB_old = PB_new;  
}




