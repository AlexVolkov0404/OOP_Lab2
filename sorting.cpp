#include "sorting.h"

Sorting::Sorting()
{

}
void Sorting::sortByTimeDecrease(QList<Timer> &timers){
    if(timers.size() > 1) {
        int i, j;
        for (i = 0; i < timers.size()-1; i++)
        for (j = 0; j < timers.size()-i-1; j++){
            if (timers[j].getTime() > timers[j+1].getTime()){
                Timer tmp = timers[j];
                timers[j] = timers[j+1];
                timers[j+1] = tmp;
            }
        }
    } else return;
}
void Sorting::sortByTimeIncrease(QList<Timer> &timers){
    if(timers.size() > 1) {
        int i, j;
        for (i = 0; i < timers.size()-1; i++)
        for (j = 0; j < timers.size()-i-1; j++){
            if (timers[j].getTime() < timers[j+1].getTime()){
                Timer tmp = timers[j];
                timers[j] = timers[j+1];
                timers[j+1] = tmp;
            }
        }
    } else return;
}
void Sorting::sortByTimeDescription(QList<Timer> &timers){
    if(timers.size() > 1) {
        int i, j;
        for (i = 0; i < timers.size()-1; i++)
        for (j = 0; j < timers.size()-i-1; j++){
            if (timers[j].getDesc() > timers[j+1].getDesc()){
                Timer tmp = timers[j];
                timers[j] = timers[j+1];
                timers[j+1] = tmp;
            }
        }
    } else return;
}
int Sorting::findMin(QList<Timer> &timers){
    if(timers.size() > 1) {
        int i, j;
        for (i = 0; i < timers.size()-1; i++)
        for (j = 0; j < timers.size()-i-1; j++){
            if (timers[j].getTime() < timers[j+1].getTime()){
                Timer tmp = timers[j];
                timers[j] = timers[j+1];
                timers[j+1] = tmp;
            }
        }
        return i;
    }
}
