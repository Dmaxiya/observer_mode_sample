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
    wd.mesurementChange(&temperature, &humidity, NULL);

    temperature = 26;
    wd.mesurementChange(&temperature, NULL, NULL);

    // ccBoard ����£�sBoard �� aqiBoard ���������
    temperature = 25.5;
    wd.mesurementChange(&temperature, NULL, NULL);

    // ccBoard �� sBoard ��������£�aqiBoard �����
    aqi = 50;
    wd.mesurementChange(NULL, NULL, &aqi);

    return 0;
}
