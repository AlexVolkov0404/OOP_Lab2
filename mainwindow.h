#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "editconstructor.h"
#include "timer.h"
#include "alarm.h"
#include "timeoutwindow.h"
#include "settings.h"
#include "timerconstructor.h"
#include "timerdelete.h"
#include "icon.h"

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
    Icon icon;
    QList<Timer> alarms;
    Timer buffer;
//    Alarm bufferAlarm;
    QString tmp;
//    QString tmpAlarm;
    QString curTime;
//    QString curTimeAlarm;
    int positionToEdit;
    int positionToEditAlarm;
    Settings settings;   
    timeoutwindow wind;

private slots:
    void showDescription();
    void showDescriptionAlarm();

private:
    void timerEvent(QTimerEvent *e);
};

#endif // MAINWINDOW_H
