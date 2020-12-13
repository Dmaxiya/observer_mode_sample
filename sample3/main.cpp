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

	wd.attach(&ccBoard, {wd.aspectTemperature, wd.aspectHumidity});
	wd.attach(&sBoard, {wd.aspectTemperature});
	wd.attach(&aqiBoard, {wd.aspectAQI});

	// bug fix�����ڿ��Դ������и�����
	temperature = 0;
	humidity = 0;
	aqi = 0;
	wd.mesurementChange(&temperature, &humidity, &aqi);

	// ccdBoard �� sdBoard ������£�aqiBoard �������
	temperature = 25;
	humidity = 0.9;
	wd.mesurementChange(&temperature, &humidity, NULL);

	temperature = 26;
	wd.mesurementChange(&temperature, NULL, NULL);

	// ccdBoard ����£�sdBoard �� aqiBoard ���������
	temperature = 25.5;
	wd.mesurementChange(&temperature, NULL, NULL);

	// ccdBoard �� sdBoard ��������£�aqiBoard �����
	aqi = 50;
	wd.mesurementChange(NULL, NULL, &aqi);

	// aqiBoard ȡ�����ģ����� aqi �ĸ��½����ᴥ�� aqiBoard ��ˢ����ʾ
	wd.detach(&aqiBoard, {wd.aspectAQI});
	aqi = 300;
	wd.mesurementChange(NULL, NULL, &aqi);

    return 0;
}
