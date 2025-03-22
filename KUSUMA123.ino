#include <Wire.h>
#include <U8g2lib.h>

// Define ESP32 I2C OLED pins
#define OLED_SCL 22
#define OLED_SDA 21

// Define Potentiometer pin
#define POT_PIN 34  // Use an ADC pin on ESP32

// Initialize OLED display
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA, U8X8_PIN_NONE);

void setup() {
    u8g2.begin();
    analogReadResolution(12);  // Set ADC resolution to 12 bits (0-4095)
}

void loop() {
    int potValue = analogRead(POT_PIN);  // Read potentiometer value

    // Convert pot value to string
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%d", potValue);

    // Display on OLED
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(10, 30, "POT Value:");
    u8g2.drawStr(10, 50, buffer);  // Display pot value
    u8g2.sendBuffer();

    delay(200);  // Small delay for stability
}
