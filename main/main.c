#include <stdio.h>
#include <string.h>              // strcmp()

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"       // vTaskDelay()

<<<<<<< HEAD
=======
#include "led.h"
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
#include "lcd.h"
#include "keypad.h"   

char PASSWORD[5] = { '1', '2', '3', '4', '\0'};

char input_pw[5];

void app_main (void)
{
<<<<<<< HEAD
=======
    led_init();
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
    lcd_init();
    keypad_init();
    while(1) {

    input_password(input_pw);
    lcd_clear();

    if (strcmp(input_pw, PASSWORD) == 0) {
        lcd_set(4, 0);
        lcd_print("Success!");
<<<<<<< HEAD
=======
        led_green_on();
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
    }
    else {
        lcd_set(5, 0);
        lcd_print("Fail..");
<<<<<<< HEAD
    }

    vTaskDelay(pdMS_TO_TICKS(3000));
=======
        led_red_on();
    }

    vTaskDelay(pdMS_TO_TICKS(3000));
    led_off();
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
    }
}
