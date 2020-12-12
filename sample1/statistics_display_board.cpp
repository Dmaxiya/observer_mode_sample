#include "statistics_display_board.h"
#include <limits>
#include <algorithm>
#include <cstdio>

statisticsDisplayBoard::statisticsDisplayBoard() {
    minTemperature = std::numeric_limits<double>::infinity();
    maxTemperature = -minTemperature;
}

void statisticsDisplayBoard::update(double temperature) {
    if (temperature >= minTemperature && temperature <= maxTemperature) {
        return ;
    }

    maxTemperature = std::max(maxTemperature, temperature);
    minTemperature = std::min(minTemperature, temperature);

    printf("=============== Statistics Display Board ===============\n");
    printf("\tmax temperature: %.1f\tmin temperature: %.1f\n\n", maxTemperature, minTemperature);
}
