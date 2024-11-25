#include "gpio_control.h"
#include "bk_gpio.h"

void gpio_init_channel(int channel) {
    bk_gpio_config(channel, GPIO_OUTPUT);
    gpio_set_state(channel, 0); // Выключить по умолчанию
}

void gpio_set_state(int channel, int state) {
    bk_gpio_write(channel, state);
}

int gpio_get_state(int channel) {
    return bk_gpio_read(channel);
}
