#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "observer.h"
#include <vector>
#include <algorithm>

class subject {
private:
    std::vector<observer*> observers;

public:
    void attach(observer *o) {
        observers.push_back(o);
    }

    void detach(observer *o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notify() {
        for (auto o: observers) {
            o->update();
        }
    }
};

#endif // _SUBJECT_H_
