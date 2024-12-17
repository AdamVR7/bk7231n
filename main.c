#include "sdk/include/gpio.h"
#include "sdk/include/wifi.h"
#include "sdk/include/mqtt.h"
#include "sdk/include/system.h"
#include "sdk/include/os_api.h"

#define PIN1 5
#define PIN2 6

int main(void) {
    // Инициализация системы
    system_init();

    // Настройка GPIO
    gpio_config(PIN1, GPIO_MODE_OUTPUT);
    gpio_config(PIN2, GPIO_MODE_OUTPUT);

    // Инициализация Wi-Fi
    wifi_init();
    if (wifi_connect("MySSID", "MyPassword") == 1) {
        printf("Wi-Fi connected!\n");
    }

    // Настройка MQTT клиента
    mqtt_client_t mqtt_client;
    mqtt_init(&mqtt_client, "broker.hivemq.com", 1883, "BK7231N_Client");
    if (mqtt_connect(&mqtt_client)) {
        printf("Connected to MQTT broker!\n");
    }

    // Главный цикл программы
    while (1) {
        // Переключение GPIO выводов
        gpio_write(PIN1, 1);
        os_delay(1000);
        gpio_write(PIN1, 0);
        os_delay(1000);

        gpio_write(PIN2, 1);
        os_delay(1000);
        gpio_write(PIN2, 0);
        os_delay(1000);

        // Отправка сообщения через MQTT
        mqtt_publish(&mqtt_client, "test/bk7231n", "GPIO toggled!");

        // Обновление MQTT
        mqtt_loop(&mqtt_client);
    }

    return 0;
}
