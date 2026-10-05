#include "driver/gpio.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lcd.h"


#define ROW_NUM 4
#define COLUMN_NUM 3


const gpio_num_t row_pin[ROW_NUM] =  {
    GPIO_NUM_19,
    GPIO_NUM_4,
    GPIO_NUM_16,
    GPIO_NUM_5
};

const gpio_num_t column_pin[COLUMN_NUM] =  {
    GPIO_NUM_18,
    GPIO_NUM_21,
    GPIO_NUM_17
};

char keys[ROW_NUM][COLUMN_NUM] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

void keypad_init(void) {
    for (int row = 0; row < ROW_NUM; row++) {
        gpio_set_direction(row_pin[row], GPIO_MODE_OUTPUT);
        gpio_set_level(row_pin[row], 0);
    }

    for(int col = 0; col < COLUMN_NUM; col++) {
        gpio_set_direction(column_pin[col], GPIO_MODE_INPUT);
        gpio_set_pull_mode(column_pin[col], GPIO_PULLDOWN_ONLY);
    }
}

char keypad_scan(void) {
    for (int row = 0; row < ROW_NUM; row++) {
        gpio_set_level(row_pin[row], 1);

        for (int col = 0; col < COLUMN_NUM; col++) {
            if (gpio_get_level(column_pin[col]) == 1) {
                    char key = keys[row][col];
                    vTaskDelay(pdMS_TO_TICKS(20));

                    while (gpio_get_level(column_pin[col]) == 1) {
                        vTaskDelay(pdMS_TO_TICKS(10));
                    }
                    gpio_set_level(row_pin[row], 0);
                return key;
            }
        }
        gpio_set_level(row_pin[row], 0);
    }
    return '\0';
}

char keypad_key(void) {
    char key;
    while(1) {
        key =  keypad_scan();
        if (key != '\0') {
        return key;
        }
    
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void input_password(char *password) {
    lcd_clear();
    
    lcd_set(4, 0);
    lcd_print("Password");

    lcd_set(6, 1); 
    
    for(int i = 0; i < 4; i++) {
        char key = keypad_key();
        password[i] = key;

        char text[2] = {key, '\0'};
        lcd_print(text);
    }
    password[4] = '\0';
    vTaskDelay(pdMS_TO_TICKS(500));
}