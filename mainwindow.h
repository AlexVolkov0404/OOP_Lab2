#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "editconstructor.h"
#include "timer.h"
#include "alarm.h"
#include "timeoutwindow.h"
#include "settings.h"
#include "timerconstructor.h"
#include "timerdelete.h"

#include <QMainWindow>
#include <QToolBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QSplitter>
#include <QListWidget>
#include <QApplication>
#include <QFontDatabase>
#include <QList>
#include <QMessageBox>
#include <QTextEdit>
#include <QTimeEdit>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QCheckBox>
#include <QProcess>
#include <QDir>
#include <QPainter>
#include <QPainterPath>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QFont>
#include <QListWidget>
#include <QShortcut>
#include <QSpinBox>
#include <QMenuBar>
#include <QSignalMapper>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QString>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    QTime temp;
    QTimer* alarm;
private:
    QString figure;
    QString textDesk;
    //Toolbar
    QToolBar *toolbar;
    QMenuBar*menubar;
    QSystemTrayIcon* m_systemTrayIcon;
    void setToolBar();
    QLabel *timelbl;
    //Main window widgets
    QLabel *mainTimerLbl;
    QTextEdit *mainTimerDescriptionLbl;
    QListWidget *listW;
    QListWidget *listB;
    QList<Timer> timers;

    EditConstructor econstructor;
    TimerConstructor constructr;
    TimerDelete delet;

    QList<Timer> alarms;
    //QList<Alarm> alarms;
    //Add window
    QWidget *addWindow;
    QWidget *addWindowAlarm;
    QSpinBox*amountTimer;
    QSpinBox*amountTimerAlarm;
    QLabel *addTimerLbl;
    QLabel *addAlarmLbl;
    QLabel *addDescLbl;
    QLabel *addDescLblAlarm;
    QLabel *addCountLbl;
    QLabel *addCountLblAlarm;
    QLabel *addPathsLbl;
    QLabel *addPathsLblAlarm;
    QTimeEdit *addTimeEdit;
    QTimeEdit *addTimeEditAlarm;
    QTextEdit *addTextEdit;
    QTextEdit *addTextEditAlarm;
    QTextEdit *addCountTextEdit;
    QTextEdit *addCountTextEditAlarm;
    QTextEdit *addPathsTextEdit;
    QTextEdit *addPathsTextEditAlarm;
    void addTimer();
    void addAlarm();
    //Edit Window
    QWidget *editWindow;
    QWidget *editWindowAlarm;
    QLabel *editTimeLbl;
    QLabel *editTimeLblAlarm;
    QLabel *editDescLbl;
    QLabel *editDescLblAlarm;
    QTimeEdit *editTimeEdit;
    QTimeEdit *editTimeEditAlarm;
    QTextEdit *editDescEdit;
    QTextEdit *editDescEditAlarm;
    QPushButton *editTimerBtn;
    QPushButton *editTimerBtnAlarm;
    void toEditWindow();
    void toEditWindowAlarm();
    Timer buffer;
    Alarm bufferAlarm;
    QString tmp;
    QString tmpAlarm;
    QString curTime;
    QString curTimeAlarm;
    int positionToEdit;
    int positionToEditAlarm;
    Settings settings;
    //To Stop
    QVector<int> stoppedTimersPositions;
    QVector<int> stoppedAlarmsPositions;

    QWidget *signalWindow;
    QLabel *timeoutLbl;
    QTextEdit *timeoutDescLbl;
    QPushButton *timeoutOKBtn;
    QVBoxLayout *vbox;
    QMediaPlayer *player;
    timeoutwindow wind;

private slots:
   void addTimerBtnClicked();
   // void addAlarmBtnClicked();
    void stopTimer();
    void editTimerBtnClicked();
//    void editAlarmBtnClicked();
    void deleteTimer();
//    void deleteAlarm();
    void deleteAllTimers();
//    void deleteAllAlarms();
    void showDescription();
    void showDescriptionAlarm();
   // void updateTimersListW();
private:
    void timerEvent(QTimerEvent *e);
    void alarmEvent(QTimerEvent *e);
    void timersSort();
    void updateTimersListW();
    void updateAlarmsListB();
    void timeoutwindow(QString description,QString paths);


};

#endif // MAINWINDOW_H
