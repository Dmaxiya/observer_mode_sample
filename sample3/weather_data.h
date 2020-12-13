#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "subject.h"
#include <vector>
#include <cstdio>

class weatherData: public subject {
private:
    int updateTimes;

    double temperature;
    double humidity;
    double aqi;

public:
    static const aspect aspectTemperature;
    static const aspect aspectHumidity;
    static const aspect aspectAQI;

    weatherData() {
        updateTimes = 0;

        temperature = 0;
        humidity = 0;
        aqi = 0;
    }

    double getTemperature() { return temperature; }
    double getHumidity() { return humidity; }
    double getAQI() { return aqi; }

    void mesurementChange(double *temperature, double *humidity, double *aqi) {
        std::vector<aspect> as;

        if (temperature != NULL) {
            this->temperature = *temperature;
            as.push_back(this->aspectTemperature);
        }
        if (humidity != NULL) {
            this->humidity = *humidity;
            as.push_back(aspectHumidity);
        }
        if (aqi != NULL) {
            this->aqi = *aqi;
            as.push_back(aspectAQI);
        }

        ++updateTimes;
        printf("Update case %d:\n", updateTimes);

        notify(as);
    }
};

const aspect weatherData::aspectTemperature = 0;
const aspect weatherData::aspectHumidity = 1;
const aspect weatherData::aspectAQI= 2;

#endif // _WEATHER_DATA_H_
