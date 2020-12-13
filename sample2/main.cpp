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

    // aqiBoard 取消订阅，关于 aqi 的更新将不会触发 aqiBoard 的刷新显示
    wd.detach(&aqiBoard);
    aqi = 300;
    wd.mesurementChange(NULL, NULL, &aqi);

    return 0;
}
