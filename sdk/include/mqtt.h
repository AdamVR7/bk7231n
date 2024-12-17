#ifndef MQTT_H
#define MQTT_H

typedef struct {
    const char* broker;
    int port;
    const char* client_id;
} mqtt_client_t;

void mqtt_init(mqtt_client_t* client, const char* broker, int port, const char* client_id);
int mqtt_connect(mqtt_client_t* client);
void mqtt_publish(mqtt_client_t* client, const char* topic, const char* payload);
void mqtt_subscribe(mqtt_client_t* client, const char* topic);
void mqtt_loop(mqtt_client_t* client);
void mqtt_set_message_callback(mqtt_client_t* client, void (*callback)(const char*, const char*));

#endif
