#include "driver/gpio.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lcd.h"        //input password에 사용


#define ROW_NUM 4
#define COLUMN_NUM 3


const gpio_num_t row_pin[ROW_NUM] =  {          //행 핀 번호
    GPIO_NUM_19,
    GPIO_NUM_4,
    GPIO_NUM_16,
    GPIO_NUM_5
};

const gpio_num_t column_pin[COLUMN_NUM] =  {            //열 핀 번호
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

void keypad_init(void) {                    //키패드 gpio 초기화
    for (int row = 0; row < ROW_NUM; row++) {
        gpio_set_direction(row_pin[row], GPIO_MODE_OUTPUT);
        gpio_set_level(row_pin[row], 0);  
    }

    for(int col = 0; col < COLUMN_NUM; col++) {
        gpio_set_direction(column_pin[col], GPIO_MODE_INPUT);
        gpio_set_pull_mode(column_pin[col], GPIO_PULLDOWN_ONLY);   
    }
}

char keypad_scan(void) {                    //키패드 스캔, 누른 키 반환
    for (int row = 0; row < ROW_NUM; row++) {
        gpio_set_level(row_pin[row], 1);        //현재 행을 HIGH로 설정

        for (int col = 0; col < COLUMN_NUM; col++) {
            if (gpio_get_level(column_pin[col]) == 1) {     //열에서 HIGH 상태 눌린 키 감지
                    char key = keys[row][col];
                    vTaskDelay(pdMS_TO_TICKS(20));

                    while (gpio_get_level(column_pin[col]) == 1) {      //길게 누른 키 중복 입력 방지
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

char keypad_key(void) {         //키가 입력 될 때까지 대기
    char key;
    while(1) {
        key =  keypad_scan();
        if (key != '\0') {
        return key;
        }
    
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void input_password(char *password) {           //4자리 비밀번호 입력 및 lcd 출력
    lcd_clear();
    
    lcd_set(4, 0);                                //print위치 (첫째줄)
    lcd_print("Password");              //패스워드 입력 전 기본으로 띄워둘 글

    lcd_set(6, 1);                                 //숫자 들어갈 위치
    
    for(int i = 0; i < 4; i++) {               //4자리 입력받기
        char key = keypad_key();
        password[i] = key;

        char text[2] = {key, '\0'};
        lcd_print(text);
    }
    password[4] = '\0';
    vTaskDelay(pdMS_TO_TICKS(500));
}