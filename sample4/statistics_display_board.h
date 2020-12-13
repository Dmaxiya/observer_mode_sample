#ifndef _STATISTICS_DISPLAY_BOARD_H_
#define _STATISTICS_DISPLAY_BOARD_H_

#include "observer.h"
#include "weather_data.h"

class statisticsDisplayBoard: public observer {
private:
    double minTemperature;
    double maxTemperature;

    bool getInfo(const void *changeInfo) {
        const weatherData::changeInfo *ci = reinterpret_cast<const weatherData::changeInfo*>(changeInfo);
        if (ci->temperature == NULL) {
            return true;
        }

        double temperature = *(ci->temperature);
        if (temperature >= minTemperature && temperature <= maxTemperature) {
            return true;
        }

        maxTemperature = std::max(maxTemperature, temperature);
        minTemperature = std::min(minTemperature, temperature);
        return false;
    }

public:
    statisticsDisplayBoard() {
        minTemperature = std::numeric_limits<double>::infinity();
        maxTemperature = -minTemperature;
    }

    void update(const void *changeInfo) {
        bool skip = getInfo(changeInfo);
        if (skip) {
            return ;
        }

        printf("=============== Statistics Display Board ===============\n");
        printf("\tmax temperature: %.1f\tmin temperature: %.1f\n\n", maxTemperature, minTemperature);
    }
};

#endif // _STATISTICS_DISPLAY_BOARD_H_
