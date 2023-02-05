#ifndef TESTALARM_H
#define TESTALARM_H

#include <QTest>
#include "alarm.h"
class TestAlarm:public QObject
{
    Q_OBJECT
public:
    TestAlarm();
private slots:
   void getTimeAlarm();
   void getDescAlarm();
   void getPathsAlarm();
   void setTimeAlarm();
   void setDescAlarm();
   void setPathsAlarm();
};

#endif // TESTALARM_H
