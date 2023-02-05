#ifndef SORTING_H
#define SORTING_H


#include "timer.h"
class Sorting
{
private:
     Timer tmp;
public:
    Sorting();
    static void sortByTimeIncrease(QList<Timer> &timers);
    static void sortByTimeDecrease(QList<Timer> &timers);
    static void sortByTimeDescription(QList<Timer> &timers);
    static int findMin(QList<Timer> &timers);
};

#endif // SORTING_H
