#ifndef _STATISTICS_DISPLAY_BOARD_H_
#define _STATISTICS_DISPLAY_BOARD_H_

#include <limits>
#include <algorithm>
#include <cstdio>

class statisticsDisplayBoard {
private:
    double minTemperature;
    double maxTemperature;

public:
    statisticsDisplayBoard() {
        minTemperature = std::numeric_limits<double>::infinity();
        maxTemperature = -minTemperature;
    }

    void update(double temperature) {
        if (temperature >= minTemperature && temperature <= maxTemperature) {
            return ;
        }

        maxTemperature = std::max(maxTemperature, temperature);
        minTemperature = std::min(minTemperature, temperature);

        printf("=============== Statistics Display Board ===============\n");
        printf("\tmax temperature: %.1f\tmin temperature: %.1f\n\n", maxTemperature, minTemperature);
    }
};

#endif // _STATISTICS_DISPLAY_BOARD_H_
