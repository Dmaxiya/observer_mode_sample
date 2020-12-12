#include "weather_data.h"
#include <cstdio>

int main() {
    double temperature;
    double humidity;
    double aqi;

    currentConditionDisplayBoard ccBoard;
    statisticsDisplayBoard sBoard;
    aqiDisplayBoard aqiBoard;
    weatherData wd(ccBoard, sBoard, aqiBoard);

    // ccBoard 与 sBoard 都会更新，aqiBoard 不会更新
    temperature = 25;
    humidity = 0.9;
    wd.MesurementChange(&temperature, &humidity, NULL);

    temperature = 26;
    wd.MesurementChange(&temperature, NULL, NULL);

    return 0;
}
