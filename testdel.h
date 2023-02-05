#ifndef TESTDEL_H
#define TESTDEL_H

#include <QTest>
#include "timerdelete.h"
#include "qtmetamacros.h"
class TestDel:public QObject
{
    Q_OBJECT
public:
    TestDel();
private slots:
   void dellAll();

};

#endif // TESTDEL_H
