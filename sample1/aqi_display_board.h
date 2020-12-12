#ifndef _AQI_DISPLAY_H_
#define _AQI_DISPLAY_H_

class aqiDisplayBoard {
private:
    int getLevel(double aqi);

public:
    void update(double sqi);
};

#endif // _AQI_DISPLAY_H_
