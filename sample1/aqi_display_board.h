#ifndef _AQI_DISPLAY_H_
#define _AQI_DISPLAY_H_

#include <cmath>
#include <cstdio>

class aqiDisplayBoard {
private:
    int getLevel(double aqi) {
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

public:
    void update(double aqi) {
        printf("================== AQI Display Board ===================\n");
        printf("\taqi: %.1f\t\tlevel: %d\n\n", aqi, getLevel(aqi));
    }
};

#endif // _AQI_DISPLAY_H_
