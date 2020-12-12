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

    // ccBoard ����£�sBoard �� aqiBoard ���������
    temperature = 25.5;
    wd.MesurementChange(&temperature, NULL, NULL);

    // ccBoard �� sBoard ��������£�aqiBoard �����
    aqi = 50;
    wd.MesurementChange(NULL, NULL, &aqi);

    return 0;
}
