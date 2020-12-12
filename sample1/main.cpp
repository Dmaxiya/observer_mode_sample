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
    wd.mesurementChange(&temperature, &humidity, NULL);

    temperature = 26;
    wd.mesurementChange(&temperature, NULL, NULL);

    // ccBoard 会更新，sBoard 和 aqiBoard 都不会更新
    temperature = 25.5;
    wd.mesurementChange(&temperature, NULL, NULL);

    // ccBoard 和 sBoard 都不会更新，aqiBoard 会更新
    aqi = 50;
    wd.mesurementChange(NULL, NULL, &aqi);

    return 0;
}
