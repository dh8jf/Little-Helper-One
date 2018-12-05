/*
 * Display
 */

#include "Ucglib.h"

Ucglib_ST7735_18x128x160_HWSPI ucg(9, 10, 8);  // (A0=9, CS=10, RESET=8)

void setupDisplay(void) {
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();

  ucg.setColor(143, 143, 143);
  ucg.drawHLine(0, 25, ucg.getWidth());
  ucg.drawHLine(0, 45, ucg.getWidth());
  ucg.drawHLine(0, 65, ucg.getWidth());
}

void dispLanLot(int xPos, int yPos) {
  char outString[11];
  
  ucg.setFont(ucg_font_profont11_8r);
  if (pvt.fixType <= 2) {
    ucg.setColor(255, 255, 0);
  }
  if (pvt.fixType >= 3) {
    ucg.setColor(0, 255, 0);
  }
  ucg.setPrintPos(xPos, yPos);
  dtostrf((pvt.lat/10000000.0f), 10, 7, outString);
  ucg.print(F("B: ")); ucg.print(outString);
  ucg.setPrintPos(xPos, yPos + 14);
  dtostrf((pvt.lon/10000000.0f), 10, 7, outString);
  ucg.print(F("L: ")); ucg.print(outString);
}

void dispLocator(int xPos, int yPos) {
  char latString[11];
  char lonString[11];
  dtostrf((pvt.lat/10000000.0f), 10, 7, latString);
  dtostrf((pvt.lon/10000000.0f), 10, 7, lonString);
  
  ucg.setFont(ucg_font_profont12_8r);
  ucg.setColor(255, 255, 255);
  ucg.setPrintPos(xPos, yPos);
  ucg.print(F("LOC: "));
  ucg.print(CalculateGridSquare(atof(latString), atof(lonString)));
}

void dispTime(int xPos, int yPos) {
  ucg.setFont(ucg_font_profont12_8r);
  ucg.setColor(255, 255, 255);
  ucg.setPrintPos(xPos, yPos);
  ucg.print(F("UTC: "));
  ucg.print(pvt.hour);
  if (pvt.hour < 10) {
    ucg.print(F("0"));
  }
  ucg.print(pvt.hour); ucg.print(":"); 
  if (pvt.minute < 10) {
    ucg.print(F("0"));
  }
  ucg.print(pvt.minute); ucg.print(":"); 
  if (pvt.second < 10) {
    ucg.print(F("0"));
  }
  ucg.print(pvt.second);
}
