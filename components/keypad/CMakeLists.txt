idf_component_register(
    SRCS "keypad.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES   esp_driver_gpio lcd freertos
    )
