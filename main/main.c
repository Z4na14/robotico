#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "i2clib.h"
#include "iot_servo.h"

#define SERVO_PIN_1 18
#define SERVO_PIN_2 19
#define SPEED_MODE LEDC_LOW_SPEED_MODE

void sleep_prog(int x)
{
    esp_cpu_cycle_count_t init_count = esp_cpu_get_cycle_count();
    while (esp_cpu_get_cycle_count() < init_count + 250000000*x) {}
}


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

    sleep_prog(2);


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


    servo_config_t servo_cfg = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = LEDC_TIMER_0,
        .channels = {
            .servo_pin = {
                SERVO_PIN_1,
                SERVO_PIN_2,

            },
            .ch = {
                LEDC_CHANNEL_0,
                LEDC_CHANNEL_1,

            },
        },
        .channel_number = 2,
    };
    iot_servo_init(SPEED_MODE, &servo_cfg);

    iot_servo_write_angle(SPEED_MODE, 0, 90.0f);
    iot_servo_write_angle(SPEED_MODE, 1, 90.0f);

}