#ifndef _CURRENT_CONDITION_DISPLAY_BOARD_H_
#define _CURRENT_CONDITION_DISPLAY_BOARD_H_

#include "observer.h"
#include "weather_data.h"

class currentConditionDisplayBoard: public observer {
private:
    weatherData &wd;

public:
    currentConditionDisplayBoard(weatherData &wd): wd(wd) {}

    void update() {
        double temperature = wd.getTemperature();
        double humidity = wd.getHumidity();
        printf("=========== Current Condition Display Board ============\n");
        printf("\ttemperature: %.1f\thumidity: %.1f\n\n", temperature, humidity);
    }
};

#endif // _CURRENT_CONDITION_DISPLAY_BOARD_H_
