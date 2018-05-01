/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/
#include "./bitmap.h"
#include "./oled.h"
#include "wireless.h"
#include <EEPROM.h>

#include <Fonts/FreeSerif9pt7b.h>

#define delay_ms 1

void setup() {

    Serial.begin(9600);
    setup_rfm();

    //while (1) rfm_loop();
                                  
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  

  uint8_t num_of_frames = 8;
while (1) {
    // for (uint8_t i = 0; i < num_of_frames; i++) {
    //     display.clearDisplay();
    //     //display.invertDisplay(true);
    //     display.drawBitmap(38, 0,  buffer1[i], 96, 64, 1);  
    //     //display.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
    //     cooking_time();    
    //     display.display();  
    //     delay(delay_ms);
        
    //     // test reading ID from EEPROM
    //     int dev_id = EEPROM.read(0);
    //     Serial.print("My device ID:  ");
    //     Serial.println(dev_id,DEC);

    //     rfm_loop();     
    // }
    
    display.setFont(&FreeSerif9pt7b);
    display.clearDisplay();

    display.drawRoundRect(0,0, 128, 64, 4, WHITE);

    // display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(15,13);       // y=12, is the top most    
    display.println("~ Welcome ~");

    // underlines of 'Welcome'
    display.drawLine(15, 14, 111, 14, WHITE);
    display.drawLine(22, 16,  104, 16, WHITE);


    // display.setCursor(0,30);
    // display.print("Meja:");    
    // ID number
    display.setTextSize(2);
    display.setCursor(8,55);
    display.println("26");

    // separator line
    display.drawLine(50, 24, 50, 59, WHITE);
    display.drawLine(51, 23, 51, 60, WHITE);
    display.drawLine(52, 24, 52, 59, WHITE);

    //test available range
    //display.drawLine(80, 20, 80, 45, WHITE);
    display.drawBitmap(80, 20,  spoon, 32, 25, 1);
    

    display.setTextSize(1);
    display.setCursor(56,58);
    display.println("90 to go...");

    display.display();
    while(1);
};
    
  
}


void loop() {
  
}


