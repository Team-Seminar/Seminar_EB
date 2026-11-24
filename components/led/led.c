#include "driver/gpio.h"         // gpio_set_level(), gpio_get_level()

<<<<<<< HEAD
#include "led.h"

#define RED_GPIO GPIO_NUM_25
#define GREEN_GPIO GPIO_NUM_23
//#define BLUE_GPIO GPIO_NUM_21
=======
#define RED_GPIO GPIO_NUM_23
#define GREEN_GPIO GPIO_NUM_22
#define BLUE_GPIO GPIO_NUM_21
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c

void led_init(void) {                               //led 초기화
    gpio_reset_pin(RED_GPIO);
    gpio_reset_pin(GREEN_GPIO);
<<<<<<< HEAD
    //gpio_reset_pin(BLUE_GPIO);

    gpio_set_direction(RED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_GPIO, GPIO_MODE_OUTPUT);
    //gpio_set_direction(BLUE_GPIO, GPIO_MODE_OUTPUT);

    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
    //gpio_set_level(BLUE_GPIO, 0);
=======
    gpio_reset_pin(BLUE_GPIO);

    gpio_set_direction(RED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLUE_GPIO, GPIO_MODE_OUTPUT);

    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
    gpio_set_level(BLUE_GPIO, 0);
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
}

void led_red_on(void) {                         // 빨간 led 켜기
    gpio_set_level(RED_GPIO, 1);
    gpio_set_level(GREEN_GPIO, 0);
<<<<<<< HEAD
    //gpio_set_level(BLUE_GPIO, 0);
=======
    gpio_set_level(BLUE_GPIO, 0);
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
}

void led_green_on(void) {                       //초록 led 켜기
    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 1);
<<<<<<< HEAD
    //gpio_set_level(BLUE_GPIO, 0);
=======
    gpio_set_level(BLUE_GPIO, 0);
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
}

void led_blue_on(void) {                       //파랑 led 켜기
    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
<<<<<<< HEAD
    //gpio_set_level(BLUE_GPIO, 1);
=======
    gpio_set_level(BLUE_GPIO, 1);
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
}

void led_off(void) {                                    //led 끄기
    gpio_set_level(RED_GPIO, 0);
    gpio_set_level(GREEN_GPIO, 0);
<<<<<<< HEAD
    //gpio_set_level(BLUE_GPIO, 0);
=======
    gpio_set_level(BLUE_GPIO, 0);
>>>>>>> ee8997a13354f517a8850e8bdc05c4a3e074948c
}
