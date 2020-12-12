#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "current_condition_display_board.h"
#include "statistics_display_board.h"
#include "aqi_display_board.h"

class weatherData {
private:
    int updateTimes;

    double temperature;
    double humidity;
    double aqi;

    currentConditionDisplayBoard &ccBoard;
    statisticsDisplayBoard &sBoard;
    aqiDisplayBoard &aqiBoard;

public:
    weatherData(currentConditionDisplayBoard &ccBoard, statisticsDisplayBoard &sBoard, aqiDisplayBoard &aqiBoard);
    void MesurementChange(double *temperature, double *humidity, double *aqi);
};

#endif // _WEATHER_DATA_H_
