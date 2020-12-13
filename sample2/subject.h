#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "observer.h"
#include <vector>
#include <algorithm>

class subject {
private:
    std::vector<observer*> os;

public:
    void attach(observer *o) {
        os.push_back(o);
    }

    void detach(observer *o) {
        os.erase(std::remove(os.begin(), os.end(), o), os.end());
    }

    void notify() {
        for (auto o: os) {
            o->update();
        }
    }
};

#endif // _SUBJECT_H_
