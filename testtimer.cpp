#include "testtimer.h"

TestTimer::TestTimer()
{

}
void TestTimer::getTime(){
    QTime tmp(0,0,0);
   Timer timer(tmp," MyTimer","C:/Users/Sasha/Documents/testdisk" );
   QCOMPARE(timer.getTime(),tmp);
}
void TestTimer::getPaths(){
    Timer timer(QTime::currentTime()," MyTimer","C:/Users/Sasha/Documents/testdisk" );
    QCOMPARE(timer.getPaths(),"C:/Users/Sasha/Documents/testdisk");
}
void TestTimer::getDesc(){
    Timer timer(QTime::currentTime()," MyTimer","C:/Users/Sasha/Documents/testdisk" );
    QCOMPARE(timer.getDesc()," MyTimer");
}
void TestTimer::setTime(){
    Timer timer;
    QTime tmp(0,0,0);
    timer.setTime(tmp);
    QCOMPARE(timer.getTime(),tmp);
}
void TestTimer::setDesc(){
    Timer timer;
    timer.setDesc(" MyTimer");
    QCOMPARE(timer.getDesc()," MyTimer");
}
void TestTimer::setPaths(){
    Timer timer;
    timer.setPaths("C:/Users/Sasha/Documents/testdisk");
    QCOMPARE(timer.getPaths(),"C:/Users/Sasha/Documents/testdisk");
}
//QTEST_MAIN(TestTimer)
