#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID       "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME     "Device"
#define BLYNK_AUTH_TOKEN        "YourAuthToken"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

BlynkTimer timer;

#define LED 23
#define PB  16

BLYNK_WRITE(V0)
{ int pbBlynk = param.asInt();
  digitalWrite(LED,pbBlynk);
}
void getPB()
{ if(digitalRead(PB)==0)
    Blynk.virtualWrite(V1,"PB Pressed");
  if(digitalRead(PB)==1)
    Blynk.virtualWrite(V1,"PB Idle");
}

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(LED,OUTPUT);
  pinMode(PB,INPUT_PULLUP);
  timer.setInterval(10L,getPB);
}

void loop()
{ Blynk.run();
  timer.run();
}
