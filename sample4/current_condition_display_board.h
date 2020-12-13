#ifndef _CURRENT_CONDITION_DISPLAY_BOARD_H_
#define _CURRENT_CONDITION_DISPLAY_BOARD_H_

#include "observer.h"
#include "weather_data.h"
#include <cstdio>

class currentConditionDisplayBoard: public observer {
private:
    double temperature;
    double humidity;

    bool getInfo(const void *changeInfo) {
        bool skip = true;
        const weatherData::changeInfo *ci = reinterpret_cast<const weatherData::changeInfo*>(changeInfo);

        if (ci->temperature != NULL) {
            skip = false;
            temperature = *(ci->temperature);
        }
        if (ci->humidity != NULL) {
            skip = false;
            humidity = *(ci->humidity);
        }

        return skip;
    }

public:
    currentConditionDisplayBoard() {
        temperature = 0;
        humidity = 0;
    }

    void update(const void *changeInfo) {
        bool skip = getInfo(changeInfo);
        if (skip) {
            return ;
        }

        printf("=========== Current Condition Display Board ============\n");
        printf("\ttemperature: %.1f\thumidity: %.1f\n\n", temperature, humidity);
    }
};

#endif // _CURRENT_CONDITION_DISPLAY_BOARD_H_
