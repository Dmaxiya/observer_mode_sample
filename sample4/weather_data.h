#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "subject.h"
#include <cstdio>

class weatherData: public subject {
private:
    int updateTimes;

    double temperature;
    double humidity;
    double aqi;

public:
    struct changeInfo {
        double *temperature;
        double *humidity;
        double *aqi;

        changeInfo(double *temperature, double *humidity, double *aqi):
            temperature(temperature), humidity(humidity), aqi(aqi) {}
    };

    weatherData() {
        updateTimes = 0;

        temperature = 0;
        humidity = 0;
        aqi = 0;
    }

    void mesurementChange(double *temperature, double *humidity, double *aqi) {
        void *ci = new changeInfo(temperature, humidity, aqi);

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

        notify(ci);
    }
};

#endif // _WEATHER_DATA_H_
