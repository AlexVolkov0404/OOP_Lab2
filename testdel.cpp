#include "testdel.h"

TestDel::TestDel()
{

}
void TestDel::dellAll(){
    QList<Timer> timers;
    Timer timer;
    QTime tmp(0,0,0);
    timer.setTime(tmp);
    timer.setDesc("hello");
    timer.setPaths("hello");
    timers.insert(timers.size(),timer);
    TimerDelete delt;
    timers.clear();
    QCOMPARE(timers.size(),0);
}

