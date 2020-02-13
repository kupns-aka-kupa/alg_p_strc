#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <list>
#include "observer.h"

template<typename T>
class Notifier
{
private:
    const T &data;
    std::list<Observer *> subs;

public:
    Notifier() = default;
    Notifier(const T &data);

    ~Notifier() = default;

    void unsubscribe();
    void subscribe();
    void notify();
};

#endif // NOTIFIER_H
