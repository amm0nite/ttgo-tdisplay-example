#include <Arduino.h>
#include <WiFi.h>
#include <credentials.h>
#include <string>

#define WIFI_TIMEOUT 5000  // WiFi connection timeout (ms)

const char *ssid = CREDENTIALS_SSID;
const char *password = CREDENTIALS_PASSWORD;

const char *ntpServer = "pool.ntp.org";
const char *tzInfo = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

char macHex[16];

WiFiClient wifiClient;

void printLocalTime()
{
    tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

bool wifiConnect()
{
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    int wait = 200;
    int waited = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(wait);
        waited += wait;
        Serial.print(".");

        if (waited > WIFI_TIMEOUT)
        {
            Serial.println("connection failed");
            return false;
        }
    }

    Serial.println("");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    uint8_t mac[6] = {};
    esp_efuse_mac_get_default(mac);
    sprintf(macHex, "%02x%02x%02x%02x%02x%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    return true;
}

void reboot()
{
    Serial.println("Restarting in 10 seconds");
    delay(10 * 1000);
    ESP.restart();
}

void netSetup()
{
    if (!wifiConnect())
    {
        reboot();
    }

    configTime(0, 0, ntpServer);
    setenv("TZ", tzInfo, 1);

    printLocalTime();
}
