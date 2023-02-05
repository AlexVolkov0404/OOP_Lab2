#ifndef TESTTIMER_H
#define TESTTIMER_H

#include "timer.h"
#include "qtmetamacros.h"
#include <QTest>
class TestTimer:public QObject
{
    Q_OBJECT
public:
    TestTimer();
private slots:
   void getTime();
   void getDesc();
   void getPaths();
   void setTime();
   void setDesc();
   void setPaths();

};

#endif // TESTTIMER_H
