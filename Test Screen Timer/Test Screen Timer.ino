#include <WiFi.h>
#include "time.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// ==== WiFi Settings ====
const char* ssid     = "HONOR X9c";
const char* password = "Test1234";

// ==== NTP Settings ====
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 8 * 3600;  // Singapore GMT+8
const int daylightOffset_sec = 0;     // No daylight saving

#define TFT_CS    -1
#define TFT_RST    4
#define TFT_DC     2

Adafruit_ST7789 tft = Adafruit_ST7789(-1, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);

  // ==== Init Display ====
  tft.init(240, 240, SPI_MODE3);  // Initialize ST7789 240x240
  tft.setRotation(2);  // Rotate if needed (0–3)
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Connecting WiFi...");

  // ==== Connect WiFi ====
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Show WiFi connected
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 10);
  tft.println("WiFi Connected!");

  // ==== Get NTP Time ====
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  showLocalTime();
  delay(1000);  // update every second
}

void showLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }

  // Format time
  char timeStr[20];
  strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);

  char dateStr[30];
  strftime(dateStr, sizeof(dateStr), "%d %b %Y", &timeinfo);

  // ==== Display on TFT ====
  tft.fillScreen(ST77XX_BLACK);   // Clear screen
  tft.setCursor(30, 80);
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_GREEN);
  tft.println(timeStr);

  tft.setCursor(50, 150);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.println(dateStr);

  // Debug print to Serial too
  Serial.println(timeStr);
  Serial.println(dateStr);
}

