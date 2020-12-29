#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <string>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite buffer = TFT_eSprite(&tft);

void screenSetup()
{
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);

    tft.setCursor(0, 0);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE);
    tft.println("Starting...");

    buffer.setColorDepth(8);
    buffer.createSprite(240, 135);
    buffer.fillSprite(TFT_BLACK);
}

void screenBufferClear()
{
    buffer.fillSprite(TFT_BLACK);
}

void screenBufferPrintBig(std::string &str)
{
    buffer.setCursor(0, 50);
    buffer.setTextSize(5);
    buffer.setTextColor(TFT_RED);
    buffer.println(str.c_str());
}

void screenBufferRender()
{
    buffer.pushSprite(0, 0);
}
