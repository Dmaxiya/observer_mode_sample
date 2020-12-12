#include "current_condition_display_board.h"
#include <cstdio>

void currentConditionDisplayBoard::update(double temperature, double humidity) {
    printf("=========== Current Condition Display Board ===========\n");
    printf("\ttemperature: %.1f\thumidity: %.1f\n\n", temperature, humidity);
}
