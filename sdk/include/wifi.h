#ifndef WIFI_H
#define WIFI_H

void wifi_init(void);
int wifi_connect(const char* ssid, const char* password);
int wifi_status(void); // 0: disconnected, 1: connected

#endif
