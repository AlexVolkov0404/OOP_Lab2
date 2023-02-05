#include "testsorts.h"

TestSorts::TestSorts()
{

}
void TestSorts::sortByTimeDecrease(){
    Timer timer1;
    QTime tmp1(0,0,0);
    timer1.setTime(tmp1);
    timer1.setDesc("a");
    timer1.setPaths("hello");
    Timer timer2;
    QTime tmp2(2,0,0);
    timer2.setTime(tmp2);
    timer2.setDesc("b");
    timer2.setPaths("hello");
    Timer timer3;
    QTime tmp3(3,0,0);
    timer3.setTime(tmp3);
    timer3.setDesc("c");
    timer3.setPaths("hello");
    QList<Timer> timers1;
    timers1.insert(timers1.size(),timer1);
    timers1.insert(timers1.size(),timer2);
    timers1.insert(timers1.size(),timer3);
    QList<Timer> timers2;
    timers2.insert(timers2.size(),timer3);
    timers2.insert(timers2.size(),timer2);
    timers2.insert(timers2.size(),timer1);
    Sorting sort;
    sort.sortByTimeDecrease(timers2);
    QCOMPARE(timers2[0].getTime(),timers1[0].getTime());
}
void TestSorts::sortByTimeIncrease(){
    Timer timer1;
    QTime tmp1(0,0,0);
    timer1.setTime(tmp1);
    timer1.setDesc("a");
    timer1.setPaths("hello");
    Timer timer2;
    QTime tmp2(2,0,0);
    timer2.setTime(tmp2);
    timer2.setDesc("b");
    timer2.setPaths("hello");
    Timer timer3;
    QTime tmp3(3,0,0);
    timer3.setTime(tmp3);
    timer3.setDesc("c");
    timer3.setPaths("hello");
    QList<Timer> timers1;
    timers1.insert(timers1.size(),timer3);
    timers1.insert(timers1.size(),timer2);
    timers1.insert(timers1.size(),timer1);
    QList<Timer> timers2;
    timers2.insert(timers2.size(),timer1);
    timers2.insert(timers2.size(),timer2);
    timers2.insert(timers2.size(),timer3);
    Sorting sort;
    sort.sortByTimeIncrease(timers2);
    QCOMPARE(timers2[0].getTime(),timers1[0].getTime());
}
void TestSorts::sortByTimeDescription(){
    Timer timer1;
    QTime tmp1(0,0,0);
    timer1.setTime(tmp1);
    timer1.setDesc("a");
    timer1.setPaths("hello");
    Timer timer2;
    QTime tmp2(2,0,0);
    timer2.setTime(tmp2);
    timer2.setDesc("b");
    timer2.setPaths("hello");
    Timer timer3;
    QTime tmp3(3,0,0);
    timer3.setTime(tmp3);
    timer3.setDesc("c");
    timer3.setPaths("hello");
    QList<Timer> timers1;
    timers1.insert(timers1.size(),timer1);
    timers1.insert(timers1.size(),timer2);
    timers1.insert(timers1.size(),timer3);
    QList<Timer> timers2;
    timers2.insert(timers2.size(),timer3);
    timers2.insert(timers2.size(),timer2);
    timers2.insert(timers2.size(),timer1);
    Sorting sort;
    sort.sortByTimeDecrease(timers2);
    QCOMPARE(timers2[0].getDesc(),timers1[0].getDesc());
}
void TestSorts::findMin(){
    Timer timer1;
    QTime tmp1(0,0,0);
    timer1.setTime(tmp1);
    timer1.setDesc("a");
    timer1.setPaths("hello");
    Timer timer2;
    QTime tmp2(2,0,0);
    timer2.setTime(tmp2);
    timer2.setDesc("b");
    timer2.setPaths("hello");
    Timer timer3;
    QTime tmp3(3,0,0);
    timer3.setTime(tmp3);
    timer3.setDesc("c");
    timer3.setPaths("hello");
    QList<Timer> timers1;
    timers1.insert(timers1.size(),timer1);
    timers1.insert(timers1.size(),timer2);
    timers1.insert(timers1.size(),timer3);
    QList<Timer> timers2;
    timers2.insert(timers2.size(),timer3);
    timers2.insert(timers2.size(),timer2);
    timers2.insert(timers2.size(),timer1);
    Sorting sort;

    QCOMPARE(sort.findMin(timers2),2);
}

