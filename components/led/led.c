#include "driver/gpio.h"         // gpio_set_level(), gpio_get_level()

#define RED_GPIO GPIO_NUM_2
#define GREEN_GPIO GPIO_NUM_15

void led_init(void) {                               //led 초기화
    gpio_reset_pin(RED_GPIO);
    gpio_reset_pin(GREEN_GPIO);

    gpio_set_direction(RED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_GPIO, GPIO_MODE_OUTPUT);

    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
}

void led_red_on(void) {                         // 빨간 led 켜기
    gpio_set_level(RED_GPIO, 1);
    gpio_set_level(GREEN_GPIO, 0);
}

void led_green_on(void) {                       //초록 led 켜기
    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 1);
}

void led_off(void) {                                    //led 끄기
    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
}
