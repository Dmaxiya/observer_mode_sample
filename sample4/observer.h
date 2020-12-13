#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class observer {
public:
    virtual void update(const void* changeInfo) = 0;
};

#endif // _OBSERVER_H_
