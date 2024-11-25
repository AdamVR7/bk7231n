#include "mqtt_handler.h"
#include "gpio_control.h"
#include "bk_uart.h"
#include "rtos.h"

#define WIFI_SSID       "YourSSID"
#define WIFI_PASSWORD   "YourPassword"
#define MQTT_BROKER     "mqtt://broker.hivemq.com"
#define MQTT_PORT       1883
#define MQTT_TOPIC_CMD  "bk7231n/relay/cmd"
#define MQTT_TOPIC_STAT "bk7231n/relay/stat"

void app_main() {
    // Инициализация Wi-Fi
    wifi_init(WIFI_SSID, WIFI_PASSWORD);

    // Инициализация GPIO для двух каналов
    gpio_init_channel(0); // Реле 1
    gpio_init_channel(1); // Реле 2

    // Подключение к MQTT
    mqtt_init(MQTT_BROKER, MQTT_PORT);
    mqtt_subscribe(MQTT_TOPIC_CMD);

    // Основной цикл
    while (1) {
        // Обработка сообщений MQTT
        mqtt_loop();
        rtos_delay(100); // Задержка 100 мс
    }
}
