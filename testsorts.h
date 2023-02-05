#ifndef TESTSORTS_H
#define TESTSORTS_H

#include <QTest>
#include "sorting.h"
class TestSorts:public QObject
{
    Q_OBJECT
public:
    TestSorts();
private slots:
    void sortByTimeIncrease();
    void sortByTimeDecrease();
    void sortByTimeDescription();
    void findMin();
};

#endif // TESTSORTS_H
