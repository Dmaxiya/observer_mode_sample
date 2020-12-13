#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "observer.h"
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

    void notify(const void *changeInfo) {
        for (auto o: os) {
            o->update(changeInfo);
        }
    }
};

#endif // _SUBJECT_H_
