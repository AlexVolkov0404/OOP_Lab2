#ifndef TIMERDELETE_H
#define TIMERDELETE_H


#include "qlistwidget.h"
#include "qmessagebox.h"
#include "qtextedit.h"
#include "timer.h"
class TimerDelete:public QObject
{
    Q_OBJECT
private:
    QListWidget *listW;
    QList<Timer> *timers;
    QMessageBox message;
    QLabel *mainTimerLbl;
    QTextEdit *mainTimerDescriptionLbl;
public:
    TimerDelete();
public slots:
    void delChosenTimer(QList<Timer> *timers, QListWidget *listW, QLabel *mainTimerLbl, QTextEdit *mainTimerDescriptionLbl);
    void delAllTimers(QList<Timer> *timers, QListWidget *listW, QLabel *mainTimerLbl, QTextEdit *mainTimerDescriptionLbl);
};

#endif // TIMERDELETE_H
