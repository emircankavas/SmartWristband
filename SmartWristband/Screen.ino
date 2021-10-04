//Screen Config
// pin 10 D4 - Serial clock out (SCLK)
// pin 13 D7 - Serial data out (DIN)
// pin  4 D2 - Data/Command select (D/C)
// pin 16 D0 - LCD chip select (CS)
// pin  5 D1 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(10,13,4,16,5);

void startScreen()
{
  display.begin();
  display.setContrast(60);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.clearDisplay();
  display.println();
  display.println();
  display.print("    AKILLI\n");
  display.print("   BILEKLIK");
  display.display();
  Serial.print("giris");
}


void mainScreen() {
//  Serial.println("Ana ekran basladi");
//  tmElements_t tm;
//  char *dayOfWeek;
//  breakTime(now(), tm);
//  dayOfWeek = dayShortStr(tm.Wday);
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.printf(" Simdiki Ders");
//  display.setTextWrap(false);
//  display.setCursor(0, 8);
//  display.printf("Beden Egitimi");
//  display.setTextSize(2);
//  display.setCursor(0, 19);
//  display.printf("%02d", tm.Hour);
//  display.drawBitmap(24, 20, colon, 4, 14, 1);
//  display.setCursor(30, 20);
//  display.printf("%02d", tm.Minute);
//  display.drawBitmap(54, 20, colon, 4, 14, 1);
//  display.setCursor(60, 20);
//  display.printf("%02d", tm.Second);
//  display.setTextSize(1);
//  display.setCursor(0, 40);
//  display.printf("%02d/%02d/%02d   %s\n", tm.Day, tm.Month, (tm.Year + 1970)%2000, (tm.Wday));
//  display.display();
//  Serial.println("Ana ekran tamamlandi");
//  Serial.println(tm.Wday);
}

void dispBalance()
{ 
  display.clearDisplay();
  display.setTextSize(1);
  display.print("Kalan bakiye :");
  display.setCursor(0, 19);
  display.setTextSize(2);
  display.print(bakiye);
  display.print("TL");
  Serial.print("bakiye");
  display.display();
}



void drawQrCode()
{
  display.clearDisplay();
  display.drawBitmap(15, 0, qrCode48, 48, 48, 1);
  display.display();
}
