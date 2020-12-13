#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "current_condition_display_board.h"
#include "statistics_display_board.h"
#include "aqi_display_board.h"
#include <cstdio>

class weatherData {
private:
    int updateTimes;

    double temperature;
    double humidity;
    double aqi;

    currentConditionDisplayBoard &ccBoard;
    statisticsDisplayBoard &sBoard;
    aqiDisplayBoard &aqiBoard;

public:
    weatherData(currentConditionDisplayBoard &ccBoard, statisticsDisplayBoard &sBoard, aqiDisplayBoard &aqiBoard):
        ccBoard(ccBoard), sBoard(sBoard), aqiBoard(aqiBoard) {

        updateTimes = 0;

        temperature = 0;
        humidity = 0;
        aqi = 0;
    }

    void mesurementChange(double *temperature, double *humidity, double *aqi) {
        if (temperature != NULL) {
            this->temperature = *temperature;
        }
        if (humidity != NULL) {
            this->humidity = *humidity;
        }
        if (aqi != NULL) {
            this->aqi = *aqi;
        }

        ++updateTimes;
        printf("Update case %d:\n", updateTimes);

        if (temperature != NULL || humidity != NULL) {
            ccBoard.update(this->temperature, this->humidity);
        }
        if (temperature != NULL) {
            sBoard.update(this->temperature);
        }
        if (aqi != NULL) {
            aqiBoard.update(this->aqi);
        }
    }
};

#endif // _WEATHER_DATA_H_
