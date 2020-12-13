#ifndef _AQI_DISPLAY_H_
#define _AQI_DISPLAY_H_

#include "observer.h"
#include "weather_data.h"
#include <cmath>
#include <cstdio>

class aqiDisplayBoard: public observer {
private:
    double aqi;

    bool getInfo(const void *changeInfo) {
        const weatherData::changeInfo *ci = reinterpret_cast<const weatherData::changeInfo*>(changeInfo);
        if (ci->aqi == NULL) {
            return true;
        }

        aqi = *(ci->aqi);
        return false;
    }

    int getLevel() {
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
    aqiDisplayBoard() {
        aqi = 0;
    }

    void update(const void *changeInfo) {
        bool skip = getInfo(changeInfo);
        if (skip) {
            return ;
        }

        printf("================== AQI Display Board ===================\n");
        printf("\taqi: %.1f\t\tlevel: %d\n\n", aqi, getLevel());
    }
};

#endif // _AQI_DISPLAY_H_
