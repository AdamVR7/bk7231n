#include "system.h"
#include "os_api.h"
#include <stdio.h>
#include <unistd.h> // для функции usleep()

void system_init(void) {
    printf("[System] Initialization complete.\n");
}

void system_restart(void) {
    printf("[System] Restarting...\n");
}

void os_delay(int ms) {
    printf("[OS] Delaying for %d ms\n", ms);
    usleep(ms * 1000); // Задержка в миллисекундах
}
