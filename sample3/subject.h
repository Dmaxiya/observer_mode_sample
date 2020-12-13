#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "observer.h"
#include <unordered_set>
#include <initializer_list>
#include <vector>

typedef int aspect;

class subject {
private:
    class observerWithAspect {
    private:
        observer *o;
        std::unordered_set<aspect> as;

    public:
        observerWithAspect(observer *o, const std::initializer_list<aspect> &al): o(o) {
            for (auto a: al) {
                this->as.insert(a);
            }
        }

        friend class subject;
    };

    std::vector<observerWithAspect*> owas;
    static const int npos = -1;

    int indexOfObserver(observer *o) {
        int len = owas.size();
        for (int i = 0; i < len; ++i) {
            if (owas[i]->o == o) {
                return i;
            }
        }
        return npos;
    }

public:
    ~subject() {
        for (auto owa: owas) {
            delete owa;
        }
    }

    void attach(observer *o, std::initializer_list<aspect> al) {
        observerWithAspect *owa = new observerWithAspect(o, al);
        owas.push_back(owa);
    }

    void detach(observer *o, std::initializer_list<aspect> al) {
        int pos = indexOfObserver(o);
        if (pos == npos) {
            return ;
        }

        for (auto a: al) {
            owas[pos]->as.erase(a);
        }

        if (owas[pos]->as.empty()) {
            delete owas[pos];
            owas.erase(owas.begin() + pos);
        }
    }

    void notify(const std::vector<aspect> &as) {
        for (auto owa: owas) {
            for (auto a: as) {
                if (owa->as.find(a) != owa->as.end()) {
                    owa->o->update();
                    break;
                }
            }
        }
    }
};

#endif // _SUBJECT_H_
