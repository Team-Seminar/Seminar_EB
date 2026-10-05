#include <stdio.h>
#include <string.h>              // strcmp()

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"       // vTaskDelay()

#include "led.h"
#include "lcd.h"
#include "keypad.h"   
#include "wifi.h"

char PASSWORD[5] = { '1', '2', '3', '4', '\0'};

char input_pw[5];

void app_main (void)
{
    led_init();
    lcd_init();
    keypad_init();
    wifi_init();
    while(1) {

    input_password(input_pw);
    lcd_clear();

    if (strcmp(input_pw, PASSWORD) == 0) {
        lcd_set(4, 0);
        lcd_print("Success!");
        led_green_on();
    }
    else {
        lcd_set(5, 0);
        lcd_print("Fail..");
        led_red_on();
    }

    vTaskDelay(pdMS_TO_TICKS(3000));
    led_off();
    }
}
