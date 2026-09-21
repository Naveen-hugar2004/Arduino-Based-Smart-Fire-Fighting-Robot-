/*
 * FireSense Rover - ESP32 Environmental Monitoring
 * Starter template for DHT11, MQ-2, MQ-135 and OLED.
 * Verify GPIO pins and OLED address with the actual hardware.
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT11
#define MQ2_PIN 34
#define MQ135_PIN 35

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
    Serial.begin(115200);
    dht.begin();

    pinMode(MQ2_PIN, INPUT);
    pinMode(MQ135_PIN, INPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS))
    {
        Serial.println("OLED initialization failed");
        while (true);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("FireSense Rover");
    display.println("Monitoring Ready");
    display.display();
    delay(2000);
}

void loop()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int gasValue = analogRead(MQ2_PIN);
    int airQualityValue = analogRead(MQ135_PIN);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("MQ-2: ");
    Serial.println(gasValue);

    Serial.print("MQ-135: ");
    Serial.println(airQualityValue);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Temp: ");
    display.print(temperature);
    display.println(" C");

    display.print("Humidity: ");
    display.print(humidity);
    display.println(" %");

    display.print("MQ2: ");
    display.println(gasValue);

    display.print("MQ135: ");
    display.println(airQualityValue);

    display.display();
    delay(2000);
}
