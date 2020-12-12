#ifndef _CURRENT_CONDITION_DISPLAY_BOARD_H_
#define _CURRENT_CONDITION_DISPLAY_BOARD_H_

#include <cstdio>

class currentConditionDisplayBoard {
public:
    void update(double temperature, double humidity) {
        printf("=========== Current Condition Display Board ============\n");
        printf("\ttemperature: %.1f\thumidity: %.1f\n\n", temperature, humidity);
    }
};

#endif // _CURRENT_CONDITION_DISPLAY_BOARD_H_
