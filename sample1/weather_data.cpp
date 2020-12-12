#include "weather_data.h"
#include <cstdio>

weatherData::weatherData(currentConditionDisplayBoard &ccBoard, statisticsDisplayBoard &sBoard, aqiDisplayBoard &aqiBoard):
    ccBoard(ccBoard), sBoard(sBoard), aqiBoard(aqiBoard) {
    updateTimes = 0;
}


void weatherData::MesurementChange(double *temperature, double *humidity, double *aqi) {
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
