#ifndef _STATISTICS_DISPLAY_BOARD_H_
#define _STATISTICS_DISPLAY_BOARD_H_

class statisticsDisplayBoard {
private:
    double minTemperature;
    double maxTemperature;

public:
    statisticsDisplayBoard();
    void update(double temperature);
};

#endif // _STATISTICS_DISPLAY_BOARD_H_
