#include "mqtt_handler.h"
#include "gpio_control.h"
#include "bk_uart.h"

static mqtt_client_t *client;

void mqtt_init(const char *broker, int port) {
    client = mqtt_client_new();
    if (client == NULL) {
        uart_printf("MQTT: Ошибка инициализации клиента\n");
        return;
    }
    mqtt_connect(client, broker, port);
    uart_printf("MQTT: Подключение к брокеру %s:%d\n", broker, port);
}

void mqtt_subscribe(const char *topic) {
    if (mqtt_subscribe(client, topic, 0) == MQTT_ERR_SUCCESS) {
        uart_printf("MQTT: Подписка на %s\n", topic);
    } else {
        uart_printf("MQTT: Ошибка подписки на %s\n", topic);
    }
}

void mqtt_publish(const char *topic, const char *message) {
    mqtt_publish_message(client, topic, message, 0, false);
}

void mqtt_loop() {
    mqtt_client_loop(client);

    // Обработка входящих сообщений
    char *topic, *message;
    if (mqtt_receive_message(client, &topic, &message)) {
        uart_printf("MQTT: Получено сообщение %s: %s\n", topic, message);

        // Управление реле
        if (strcmp(topic, MQTT_TOPIC_CMD) == 0) {
            if (strcmp(message, "relay1_on") == 0) {
                gpio_set_state(0, 1); // Включить реле 1
                mqtt_publish(MQTT_TOPIC_STAT, "relay1_on");
            } else if (strcmp(message, "relay1_off") == 0) {
                gpio_set_state(0, 0); // Выключить реле 1
                mqtt_publish(MQTT_TOPIC_STAT, "relay1_off");
            } else if (strcmp(message, "relay2_on") == 0) {
                gpio_set_state(1, 1); // Включить реле 2
                mqtt_publish(MQTT_TOPIC_STAT, "relay2_on");
            } else if (strcmp(message, "relay2_off") == 0) {
                gpio_set_state(1, 0); // Выключить реле 2
                mqtt_publish(MQTT_TOPIC_STAT, "relay2_off");
            }
        }
    }
}
