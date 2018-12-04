/*
 * Little Helper One
 * uBlox GPS M8 via soft serial and display ST7735 126x160 via SPI on Arduino nano
 * displays latitude, longitude, QTH locator, UTC time
 * 
 * 12/2018 by Frank, DH8JF
 */

#include "QTHLocator.h"
#include "GPS.h"
#include "Display.h"

void setup() {
  Serial.begin(9600);
 
  setupGPS();
  setupDisplay();
  
}

void loop() {
  if ( processGPS() ) {
    dispLanLot(10, 8);
    dispLocator(15, 40);
    dispTime(15, 60);
    
    // Windows program time sychronisation by Fieldday-Buddy
    Serial.print(pvt.minute); Serial.print(","); 
    if (pvt.second < 10) {
      Serial.print(F("0"));
      }
    Serial.print(pvt.second);
  }
}
