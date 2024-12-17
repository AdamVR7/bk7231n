#ifndef GPIO_H
#define GPIO_H

#define GPIO_MODE_INPUT     0
#define GPIO_MODE_OUTPUT    1
#define GPIO_ON             1
#define GPIO_OFF            0

void gpio_config(int pin, int mode);
void gpio_write(int pin, int value);
int gpio_read(int pin);

#endif
