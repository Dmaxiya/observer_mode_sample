#ifndef _AQI_DISPLAY_H_
#define _AQI_DISPLAY_H_

#include "observer.h"
#include "weather_data.h"
#include <cmath>
#include "util.h"
#include <cstdio>

class aqiDisplayBoard: public observer {
private:
    double aqi;
    weatherData &wd;

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
    aqiDisplayBoard(weatherData &wd): wd(wd) {
        aqi = 0;
    }

    void update() {
        double aqi = wd.getAQI();
        if (util::equal(aqi, this->aqi)) {
            return ;
        }

        this->aqi = aqi;
        printf("================== AQI Display Board ===================\n");
        printf("\taqi: %.1f\t\tlevel: %d\n\n", aqi, getLevel());
    }
};

#endif // _AQI_DISPLAY_H_
