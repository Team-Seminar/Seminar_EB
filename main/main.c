#include <stdio.h>
#include <string.h>              // strcmp()

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"       // vTaskDelay()

#include "lcd.h"
#include "keypad.h"   

char PASSWORD[5] = { '1', '2', '3', '4', '\0'};

char input_pw[5];

void app_main (void)
{
    lcd_init();
    keypad_init();
    while(1) {

    input_password(input_pw);
    lcd_clear();

    if (strcmp(input_pw, PASSWORD) == 0) {
        lcd_set(4, 0);
        lcd_print("Success!");
    }
    else {
        lcd_set(5, 0);
        lcd_print("Fail..");
    }

    vTaskDelay(pdMS_TO_TICKS(3000));
    }
}
