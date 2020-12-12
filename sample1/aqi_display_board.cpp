#include "aqi_display_board.h"

#include <cmath>
#include <cstdio>

int aqiDisplayBoard::getLevel(double aqi) {
    if (aqi <= 0) {
        return 1;
    }
    if (aqi <= 250) {
        return int(ceil(aqi / 50));
    }
    if (aqi <= 300) {
        return 5;
    }
    return 6;
}

void aqiDisplayBoard::update(double aqi) {
    printf("================== AQI Display Board ==================\n");
    printf("\taqi: %.1f\t\t\t\t\tlevel: %d\n\n", aqi, getLevel(aqi));
}
