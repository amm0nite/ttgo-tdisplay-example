#include <Arduino.h>

#include "net.h"
#include "screen.h"

#define TimeSize 10

std::string getTime()
{
    tm timeinfo;
    getLocalTime(&timeinfo);
    char buffer[TimeSize];
    strftime(buffer, TimeSize, "%H:%M:%S", &timeinfo);

    return std::string(buffer);
}

void setup()
{
    Serial.begin(115200);
    delay(10);

    netSetup();
    screenSetup();
}

void loop()
{
    screenBufferClear();

    std::string date = getTime();
    screenBufferPrintBig(date);

    screenBufferRender();
}
