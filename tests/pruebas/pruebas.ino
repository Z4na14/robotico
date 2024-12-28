#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


Servo top_left_servos[3];
Servo top_right_servos[3];
Servo bot_left_servos[3];
Servo bot_right_servos[3];


void setup_servos(int pin1, int pin2, int pin3, Servo matrix[], int direction) {
    matrix[0].attach(pin1);
    matrix[1].attach(pin2);
    matrix[2].attach(pin3);

    matrix[0].write(direction);
    delay(500);
    matrix[1].write(direction);
    delay(500);
    matrix[2].write(direction);
    delay(500);

}


// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};


void setup() {
  
  setup_servos(17, 16, 4, top_left_servos, 0);
  setup_servos(12, 14, 27, top_right_servos, 0);
  setup_servos(19, 18, 5, bot_left_servos, 0);
  setup_servos(26, 25, 33, bot_right_servos, 0);
  
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.createChar(0, heart);
}

void loop() {
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("192.168.1.30");
  
  lcd.setCursor(0, 1);
  lcd.print(":8080");

  lcd.setCursor(15, 0);
  lcd.write(0);

    
  setup_servos(17, 16, 4, top_left_servos, 0);
  setup_servos(12, 14, 27, top_right_servos, 0);
  setup_servos(19, 18, 5, bot_left_servos, 0);
  setup_servos(26, 25, 33, bot_right_servos, 0);
  
  delay(1000);
    
  setup_servos(17, 16, 4, top_left_servos, 180);
  setup_servos(12, 14, 27, top_right_servos, 180);
  setup_servos(19, 18, 5, bot_left_servos, 180);
  setup_servos(26, 25, 33, bot_right_servos, 180);
  

}
