#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "i2clib.h"

#define sleep(x) esp_cpu_cycle_count_t init_count = esp_cpu_get_cycle_count(); \
                 while (esp_cpu_get_cycle_count() < init_count + 250000000*x) {}


void app_main(void) {

    LCD_init(0x3F, 21, 22, 16, 2);
    LCD_home();

    /*
    char *PRIV_IP = "192.168.1.1";
    char *PORT = "8080";
    LCD_writeStr(PRIV_IP);
    LCD_setCursor(0, 1);
    LCD_writeStr(PORT);

    esp_cpu_cycle_count_t init_count = esp_cpu_get_cycle_count();
    while (esp_cpu_get_cycle_count() < init_count + 500000000L) {};
    */

    LCD_clearScreen();
    LCD_setCursor(6,0);
    LCD_writeStr("UwU");
    LCD_setCursor(6,1);
    LCD_writeStr("d d");

    sleep(2);


    // Example custom character: A smiley face
    uint8_t huevos[8] = {
        0x0E, 0x11, 0x11, 0x0E, 0x0E, 0x11, 0x11, 0x0E};

    uint8_t tronco[8] = {
        0x00, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00};

    uint8_t cabeza[8] = {
        0x00, 0x00, 0x1E, 0x09, 0x09, 0x1E, 0x00, 0x00};

    LCD_createCustomChar(0, huevos);
    LCD_createCustomChar(1, tronco);
    LCD_createCustomChar(2, cabeza);
    LCD_clearScreen();
    LCD_setCursor(0,0);
    LCD_writeCustomChar(0);

    for (int i = 1; i < 15; i++)
    {
        LCD_setCursor(i, 0);
        LCD_writeCustomChar(1);
    }

    LCD_setCursor(15, 0);
    LCD_writeCustomChar(2);

}