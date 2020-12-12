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

    // ccBoard �� sBoard ������£�aqiBoard �������
    temperature = 25;
    humidity = 0.9;
    wd.MesurementChange(&temperature, &humidity, NULL);

    temperature = 26;
    wd.MesurementChange(&temperature, NULL, NULL);

    return 0;
}
