#ifndef _UTIL_H_
#define _UTIL_H_

#include <cmath>

class util {
private:
    static const double eps;

public:
    static bool equal(double x, double y) {
        return std::fabs(x - y) < eps;
    }
};

const double util::eps = 1e-6;

#endif // _UTIL_H_
