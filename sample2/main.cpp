#include "weather_data.h"
#include "current_condition_display_board.h"
#include "statistics_display_board.h"
#include "aqi_display_board.h"

int main() {
    double temperature;
    double humidity;
    double aqi;

    weatherData wd;
    currentConditionDisplayBoard ccBoard(wd);
    statisticsDisplayBoard sBoard(wd);
    aqiDisplayBoard aqiBoard(wd);

    wd.attach(&ccBoard);
    wd.attach(&sBoard);
    wd.attach(&aqiBoard);

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

    // aqiBoard ȡ�����ģ����� aqi �ĸ��½����ᴥ�� aqiBoard ��ˢ����ʾ
    wd.detach(&aqiBoard);
    aqi = 300;
    wd.mesurementChange(NULL, NULL, &aqi);

    return 0;
}
