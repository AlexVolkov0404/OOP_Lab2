#include "testalarm.h"

TestAlarm::TestAlarm()
{

}
void TestAlarm::getTimeAlarm(){
    QTime tmp(0,0,0);
    Alarm timer(tmp," MyTimer","C:/Users/Sasha/Documents/testdisk" );
    QCOMPARE(timer.getTimeAlarm(),tmp);
}
void TestAlarm::getPathsAlarm(){
    Alarm timer(QTime::currentTime()," MyTimer","C:/Users/Sasha/Documents/testdisk" );
    QCOMPARE(timer.getPathsAlarm(),"C:/Users/Sasha/Documents/testdisk");
}
void TestAlarm::getDescAlarm(){
    Alarm timer(QTime::currentTime()," MyTimer","C:/Users/Sasha/Documents/testdisk" );
    QCOMPARE(timer.getDescAlarm()," MyTimer");
}
void TestAlarm::setTimeAlarm(){
    Alarm timer;
    QTime tmp(0,0,0);
    timer.setTimeAlarm(tmp);
    QCOMPARE(timer.getTimeAlarm(),tmp);
}
void TestAlarm::setDescAlarm(){
    Alarm timer;
    timer.setDescAlarm(" MyTimer");
    QCOMPARE(timer.getDescAlarm()," MyTimer");
}
void TestAlarm::setPathsAlarm(){
    Alarm timer;
    timer.setPathsAlarm("C:/Users/Sasha/Documents/testdisk");
    QCOMPARE(timer.getPathsAlarm(),"C:/Users/Sasha/Documents/testdisk");
}
