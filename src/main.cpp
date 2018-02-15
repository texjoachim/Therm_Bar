//Therm_Bar: a small thermometer and barometric presssure device

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_BMP280 sensor; // our themperature and pressure sensor
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 4, 5, 7, 6); // our display


void setup() {
    display.begin();
    display.setContrast(60);
    display.clearDisplay();
    sensor.begin();
}
  
void loop() {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0, 0);
    display.println("Temperature = ");
    display.print(sensor.readTemperature());
    display.print(" *C");
    display.println();
    display.println();
    display.println("Pressure = ");
    display.print(sensor.readPressure()/100);
    display.print(" hPa");

    // display.print("Approx altitude = ");
    // display.print(sensor.readAltitude(1013.25));
    // display.println(" m");
    display.display();

    delay(5000);
    
    display.clearDisplay();
}
