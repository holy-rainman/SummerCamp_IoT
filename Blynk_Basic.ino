#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID       "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME     "Device"
#define BLYNK_AUTH_TOKEN        "YourAuthToken"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{ Blynk.run();
}
