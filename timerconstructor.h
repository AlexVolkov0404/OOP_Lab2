#ifndef TIMERCONSTRUCTOR_H
#define TIMERCONSTRUCTOR_H

#include "qlistwidget.h"
#include "timer.h"
#include "qdatetimeedit.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qspinbox.h"
#include "qtextedit.h"
#include "qwidget.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
class TimerConstructor:public QObject
{
   // Q_OBJECT
private:

    QWidget *addWindow;
    QSpinBox*amountTimer;
    QLabel *addTimerLbl;
    QLabel *addDescLbl;
    QLabel *addCountLbl;
    QLabel *addPathsLbl;
    QLabel *addPathsLblAlarm;
    QTimeEdit *addTimeEdit;
    QTextEdit *addTextEdit;
    QTextEdit *addCountTextEdit;
    QTextEdit *addPathsTextEdit;
    QPushButton *addBtn ;
    QListWidget *listW;

    QList<Timer> *timers;

public:

    TimerConstructor();

public slots:
  void showConstructorWindow(QList<Timer> *timers, QListWidget *listW);
  void addNewTimer(QList<Timer> *timers, QListWidget *listW, int h, int min, int sec, QString Desc, QString paths);
 // void timersort(QList<Timer> &timers);
};

#endif // TIMERCONSTRUCTOR_H
