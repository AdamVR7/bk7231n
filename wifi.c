#include "wifi.h"
#include <stdio.h>

void wifi_init(void) {
    printf("[Wi-Fi] Initialized\n");
}

int wifi_connect(const char* ssid, const char* password) {
    printf("[Wi-Fi] Connecting to SSID: %s\n", ssid);
    return 1;  // Simulate successful connection
}

int wifi_status(void) {
    return 1;  // Always "connected"
}
