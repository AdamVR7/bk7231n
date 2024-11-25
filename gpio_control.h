#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

void gpio_init_channel(int channel);
void gpio_set_state(int channel, int state);
int gpio_get_state(int channel);

#endif // GPIO_CONTROL_H
