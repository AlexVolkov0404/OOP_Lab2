#ifndef EDITCONSTRUCTOR_H
#define EDITCONSTRUCTOR_H

#include <QString>
#include <QVBoxLayout>
#include <QMessageBox>
#include "qdatetimeedit.h"
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "qtextedit.h"
#include "timer.h"
#include "timerconstructor.h"
class EditConstructor:public QObject
{
    Q_OBJECT
private:
    QListWidget *listW;
    QList<Timer> *timers;
    QWidget *editWindow;
    QLabel *editTimeLbl;
    QLabel *editDescLbl;
    QTimeEdit *editTimeEdit;
    QTextEdit *editDescEdit;
    QPushButton *editTimerBtn;
    QString tmp;
    int positionToEdit;
    TimerConstructor constructor;
    Timer buffer;
    QMessageBox message;
public:
    EditConstructor();
public slots:
    void showEditWindow(QList<Timer> *timers, QListWidget *listW);
    void editTimerInformation(QList<Timer> &timers);
    void checker(QList<Timer> &timers, QListWidget *listW);
    void setTimeEdit(QList<Timer> &timers);
};

#endif // EDITCONSTRUCTOR_H
