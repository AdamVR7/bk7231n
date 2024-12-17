#include "gpio.h"
#include <stdio.h>

void gpio_config(int pin, int mode) {
    printf("[GPIO] Configuring pin %d to mode %d\n", pin, mode);
}

void gpio_write(int pin, int value) {
    printf("[GPIO] Writing %d to pin %d\n", value, pin);
}

int gpio_read(int pin) {
    printf("[GPIO] Reading pin %d\n", pin);
    return 0;
}
