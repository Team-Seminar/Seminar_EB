#include "driver/gpio.h"
#include "driver/i2c_master.h"   // I2C LCD 통신
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"       // vTaskDelay()
#include "esp_err.h"
#include "lcd.h"

#define LCD_SDA GPIO_NUM_22
#define LCD_SCL GPIO_NUM_23
#define LCD_ADDR 0x27
#define LCD_FREQ 100000

#define LCD_RS 0x01
#define LCD_RW 0x02
#define LCD_EN 0x04
#define LCD_BACKLIGHT 0x08

i2c_master_bus_handle_t i2c_bus= NULL;
i2c_master_dev_handle_t lcd_dev = NULL;

void lcd_init(void) {           //lcd 초기화
    i2c_master_bus_config_t bus = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = LCD_SDA,
        .scl_io_num = LCD_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
    };

    ESP_ERROR_CHECK(i2c_new_master_bus(&bus, &i2c_bus));

    i2c_device_config_t dev = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = LCD_ADDR,
        .scl_speed_hz = LCD_FREQ
    };

    ESP_ERROR_CHECK(i2c_master_bus_add_device(i2c_bus, &dev, &lcd_dev));

    vTaskDelay(pdMS_TO_TICKS(60));

    lcd_write_4bit(0x30);
    lcd_write_4bit(0x30);
    lcd_write_4bit(0x30);
    lcd_write_4bit(0x20);   //4비트 인터페이스로 전환

    lcd_send(0x28, 0);  //4비트 통신, 2줄로 표시
    lcd_send(0x08, 0); //화면 off
    lcd_clear();
    lcd_send(0x06, 0);  //문자 입력 후 오른쪽 이동
    lcd_send(0x0C, 0);  //화면 on
}

void lcd_write_byte(uint8_t data) {             // 데이터를 i2c로 1바이트 전송
    ESP_ERROR_CHECK(i2c_master_transmit(
        lcd_dev, &data, 1, pdMS_TO_TICKS(1000))
    );
}

void lcd_set(int col, int row) {                        //lcd 커서 위치 셋팅
    uint8_t address = (row == 0) ? 0x00 : 0x40;
    lcd_send(0x80 | (address + col), 0);
}

void lcd_write_4bit(uint8_t data) {             //lcd 4비트 데이터 전송
    data = data | LCD_BACKLIGHT;

    lcd_write_byte(data);
    vTaskDelay(1);

    lcd_write_byte(data | LCD_EN);          //enable HIGH
    vTaskDelay(1);

    lcd_write_byte(data);                           //enable LOW
    vTaskDelay(pdMS_TO_TICKS(10) + 1);
}

void lcd_send(uint8_t data, uint8_t mode) {         //데이터 전송
    lcd_write_4bit((data & 0xF0) | mode);                //상단 4비트 전송
    lcd_write_4bit(((data << 4) & 0xF0) | mode);      //하단 4비트 전송
}

void lcd_clear(void) {                      //화면 초기화, 커서를 처음으로 이동
    lcd_send(0x01, 0);
    vTaskDelay(pdMS_TO_TICKS(1));
}

void lcd_print(char *str) {             //lcd에 문자 출력
    while (*str) {
        lcd_send(*str, LCD_RS);
        str++;
    }
}