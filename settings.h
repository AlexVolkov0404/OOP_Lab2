#ifndef SETTINGS_H
#define SETTINGS_H


#include "qboxlayout.h"
#include "qcheckbox.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include <QRadioButton>
#include <timer.h>
#include <sorting.h>
class Settings :public QObject
{
    Q_OBJECT
private:
    QWidget *settingsWindow;
    QLabel *doNotLbl;
    QLabel *sortByTimeIncreaseLabel;
    QLabel *sortByTimeDecreaseLabel;
    QLabel *sortByNameLabel;
    QCheckBox *doNotCheckBox;
    //QCheckBox *sortByTimeIncrease;
    //QCheckBox *sortByTimeDecrease;
    //QCheckBox *sortByName;
    QPushButton *infoOKBtn;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox ;
    bool doNotDisturb;
    bool timerIncrease;
    bool timerDecrease;
    bool timerName;
    QRadioButton *sortByTimeIncrease;
    QRadioButton *sortByTimeDecrease;
    QRadioButton *sortByName;
public:
    Settings();
    void setsettingswindow();
    void sortInfo(QList<Timer> &timers);
public slots:

     bool infoOk();

     void showSettingsWindow();
};

#endif // SETTINGS_H
