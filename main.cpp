#include <QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "qtestcase.h"
#include "testalarm.h"
#include "testdel.h"
#include "testsorts.h"
#include "testtimer.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow window;

    window.setFixedSize(700,500);
    window.setWindowTitle("Timer Application");
    window.show();
    QTest::qExec(new TestTimer, argc, argv);
    QTest::qExec(new TestAlarm, argc, argv);

    QTest::qExec(new TestDel, argc, argv);
    QTest::qExec(new TestSorts, argc, argv);

    return a.exec();

}
