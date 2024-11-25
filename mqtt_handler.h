#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

void mqtt_init(const char *broker, int port);
void mqtt_subscribe(const char *topic);
void mqtt_publish(const char *topic, const char *message);
void mqtt_loop();

#endif // MQTT_HANDLER_H
